/*
ť�� �� �� �����, �׵��� ���� run_q,sto_q�� ����Ų��.
run_q�� ����Ű�� ť�� k��ŭ pop�� �ϰ� �� pop�� ���� sto_q�� push�ȴ�.
run_q�� ����Ű�� ť�� k��° index�� pop�Ͽ�, printf�� ����ϰ� �ٽ� k��ŭ pop�� �ϰ� �� pop�� ���� sto_q�� push�Ѵ�.
run_q�� ����Ű�� ť�� �� ����ٸ� sto_q�� ����Ű�� ť�� run_q�� ����Ű�� ť�� ���� ��ȯ�ϰ�, �ٽ� �ݺ�
�� ���� ť�� �� �� ������ �ݺ��Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int rear, front;
	int *data;//���� �Ҵ�� �迭�� ����Ŵ
}queue;

void create_queue(queue* q)
{
	q->rear = q->front = -1;
}


int empty(queue* q)
{
	return (q->front == q->rear);
}

void push(queue* q,int item)
{
	q->data[++(q->rear)] = item;
}

int pop(queue* run_q,queue*sto_q)
{
	if (empty(run_q))//run_q�� ����ִٸ� sto_q�� ����Ű�� �迭�� �¹ٲ۴�.
	{
		int* temp = sto_q->data;
		sto_q->data = run_q->data;
		run_q->data = temp;
		run_q->rear = sto_q->rear;//run_q�� ����Ű�� �迭�� index�� k��° index�� ������ ������ index�� sto_q�� ����Ű�� �迭�� push�ߴµ� �� pushȽ���� sto_q->rear�� ��Ÿ��
								  //�� sto_q->rear�� sto_q�� ����Ű�� ť�� ����� ������ ������ ��Ÿ����.
		run_q->front = sto_q->front;//ó������ �ٽ� pop�ؾ��ϹǷ� front�ʱ�ȭ
		create_queue(sto_q);//sto_q�� ����Ű�� ť �ʱ�ȭ(front�� rear�� -1�� �����ν� ������)
	}
	return run_q->data[++(run_q->front)];
}


void queue_change(queue* run_q, queue* sto_q,int kth)
{
	while ( kth>1)//k�� �ݺ��� ����
	{
		int item = pop(run_q,sto_q);
		push(sto_q, item);
		kth -= 1;
	}

	printf("%d", pop(run_q,sto_q));
	return;
}


int main(void)
{
	queue run_q, sto_q;
	int n,num,k,i;

	create_queue(&run_q);
	create_queue(&sto_q);
	scanf("%d %d", &n,&k);
	run_q.data = (int*)malloc(sizeof(int) * n);
	sto_q.data = (int*)malloc(sizeof(int) * n);
	for (i = 0, num = n; i < num; i++)
	{
		push(&run_q,i + 1);
	}
	num = n;
	printf("<");
	while (num--)
	{
		queue_change(&run_q, &sto_q, k);

		if (num > 0)
			printf(", ");
	}
	printf(">");
}