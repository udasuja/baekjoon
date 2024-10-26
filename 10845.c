/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
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


//push만하고 front함수를 호출하면 0번째 인덱스에 저장된 값이 출력되도록 front는 0으로 초기화함,그리고 rear도 0으로 초기화함
void create_queue(queue* q)
{
	q->count = 0;
	q->rear = 0;
	q->front = 0;
}
//empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
int empty(queue* q)
{
	if(q->rear == q->front)
		return 1;
	return 0;
}
//push X: 정수 X를 큐에 넣는 연산이다.
void push(queue* q, int item)
{
	q->count++;
	q->data[(q->rear)++] = item;
}

//pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
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
//push후에 rear값이 1증가하고 끝나므로 rear이 가리키는 값은 빈 인덱스이므로 -1를 하여 마지막으로 push한 값을 출력한다.
}

int main(void)
{
	queue q;
	int n;
	int outp;

	scanf("%d", &n);
	getchar();//버퍼 내 \n제거
	create_queue(&q);
	while (n--)
	{
		char arr[6];
		scanf("%s", arr);
		
		getchar();//버퍼 내 \n제거
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