/*
큐를 두 개 만들고, 그들을 각각 run_q,sto_q가 가리킨다.
run_q가 가리키는 큐는 k만큼 pop를 하고 그 pop한 값은 sto_q에 push된다.
run_q가 가리키는 큐의 k번째 index는 pop하여, printf로 출력하고 다시 k만큼 pop를 하고 그 pop한 값은 sto_q에 push한다.
run_q가 가리키는 큐가 텅 비었다면 sto_q가 가리키는 큐와 run_q가 가리키는 큐를 서로 교환하고, 다시 반복
두 개의 큐가 텅 빌 때까지 반복한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int rear, front;
	int *data;//동적 할당된 배열을 가리킴
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
	if (empty(run_q))//run_q가 비어있다면 sto_q가 가리키는 배열과 맞바꾼다.
	{
		int* temp = sto_q->data;
		sto_q->data = run_q->data;
		run_q->data = temp;
		run_q->rear = sto_q->rear;//run_q이 가리키는 배열의 index중 k번째 index를 제외한 나머지 index를 sto_q가 가리키는 배열에 push했는데 그 push횟수를 sto_q->rear가 나타냄
								  //즉 sto_q->rear는 sto_q가 가리키는 큐에 저장된 원소의 개수를 나타낸다.
		run_q->front = sto_q->front;//처음부터 다시 pop해야하므로 front초기화
		create_queue(sto_q);//sto_q가 가리키는 큐 초기화(front와 rear를 -1로 함으로써 구현됨)
	}
	return run_q->data[++(run_q->front)];
}


void queue_change(queue* run_q, queue* sto_q,int kth)
{
	while ( kth>1)//k번 반복문 실행
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