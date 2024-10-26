/*
push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10000

typedef struct
{
	int rear;
	int count;
	int front;
	int data[SIZE];
}queue;


//push���ϰ� front�Լ��� ȣ���ϸ� 0��° �ε����� ����� ���� ��µǵ��� front�� 0���� �ʱ�ȭ��,�׸��� rear�� 0���� �ʱ�ȭ��
void create_queue(queue* q)
{
	q->count = 0;
	q->rear = 0;
	q->front = 0;
}
//empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
int empty(queue* q)
{
	if(q->rear == q->front)
		return 1;
	return 0;
}
//push X: ���� X�� ť�� �ִ� �����̴�.
void push(queue* q, int item)
{
	q->count++;
	q->data[(q->rear)++] = item;
}

//pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int pop(queue* q)
{
	if (empty(q))
	{
		return -1;
	}
	q->count--;
	return (q->data[(q->front)++]);
}

int front(queue* q)
{
	if (empty(q))
	{
		return -1;
	}
	return q->data[q->front];
}

int back(queue* q)
{
	if (empty(q))
	{
		return -1;
	}
	return q->data[(q->rear)-1];
//push�Ŀ� rear���� 1�����ϰ� �����Ƿ� rear�� ����Ű�� ���� �� �ε����̹Ƿ� -1�� �Ͽ� ���������� push�� ���� ����Ѵ�.
}

int main(void)
{
	queue q;
	int n;
	int outp;

	scanf("%d", &n);
	getchar();//���� �� \n����
	create_queue(&q);
	while (n--)
	{
		char arr[6];
		scanf("%s", arr);
		
		getchar();//���� �� \n����
		if (!strncmp(arr,"push",4))
		{
			int num;
			scanf("%d", &num);
			getchar();
			push(&q, num);
			continue;
		}
		else if (!strncmp(arr, "pop", 3))
		{
			outp = pop(&q);
		}
		else if (!strncmp(arr, "empty", 5))
		{
			outp = empty(&q);
		}
		else if (!strncmp(arr, "size", 4))
		{
			outp=q.count;
		}
		else if (!strncmp(arr, "front", 5))
		{
			outp = front(&q);
		}
		else if (!strncmp(arr, "back", 4))
		{
			outp = back(&q);
		}
		printf("%d\n", outp);
	}
}