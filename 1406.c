/*
두 개의 스택:

left_stack: 커서 왼쪽에 있는 문자들.
right_stack: 커서 오른쪽에 있는 문자들.

명령어 처리:

L: 왼쪽 스택에서 오른쪽 스택으로 pop & push. 왼쪽 스택 top-=1,오른쪽 스택 top+=1
D: 오른쪽 스택에서 왼쪽 스택으로 pop & push. 왼쪽 스택 top+=1, 오른쪽 스택 top-=1
B: 왼쪽 스택에서 pop. 왼쪽 top-=1
P: 왼쪽 스택에 push. 왼쪽 top+=1

결과 출력:

마지막에 왼쪽 스택에 남은 문자들을 오른쪽 스택에 다시 push한 후, 오른쪽 스택을 역순으로 출력.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	char c;
	struct _node* link;
}node;

int empty(node *first)
{
	return first->link == NULL;
}


void push(node *start, char item)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->c = item;
	new_node->link = start->link;
	start->link = new_node;
	return;
}

char pop(node* start)
{
	if (!empty(start))//stact에 원소가 있을 경우
	{
		node* temp = start->link;
		char charec = temp->c;
		start->link = temp->link;
		free(temp);
		return charec;
	}
}


int main(void)
{
	node left={'\0',NULL};
	node right = { '\0',NULL };
	int top_l = -1, top_r = -1;
	char ch;
	int n;

	while ((ch = getchar()) != '\n')
	{
		push(&left, ch);
		top_l += 1;
	}

	scanf("%d", &n);
	getchar();
	while (n--)
	{
		char comm[5];
		fgets(comm, 5, stdin);
		switch (comm[0])
		{
			//	L: 왼쪽 스택에서 오른쪽 스택으로 pop& push.왼쪽 스택 top -= 1, 오른쪽 스택 top += 1
		case 'L':
		{
			if (!empty(&left))
			{
				char le = pop(&left);
				top_l--;
				push(&right, le);
				top_r++;
			}
			break;
		}
			//	D : 오른쪽 스택에서 왼쪽 스택으로 pop & push.왼쪽 스택 top += 1, 오른쪽 스택 top -= 1
		case 'D':
		{
			if (!empty(&right))
			{
				char ri = pop(&right);
				top_r--;
				push(&left, ri);
				top_l++;
			}
			break;
		}
			//	B : 왼쪽 스택에서 pop.왼쪽 top -= 1
		case 'B':
		{
			if (!empty(&left))
			{
				pop(&left);
				top_l--;
			}
			break;
		}
			//	P : 왼쪽 스택에 push.왼쪽 top += 1
		case 'P':
		{
			push(&left, comm[2]);
			top_l++;
			break;
		}
		}

	}
	//왼쪽 스택에 남은 문자들을 오른쪽 스택에 다시 push한 후, 오른쪽 스택을 역순으로 출력.
	while (top_l > -1)
	{
		char le = pop(&left);
		push(&right, le);
		top_l--;
	}
	while (!empty(&right))
	{
		char ch = pop(&right);
		printf("%c", ch);
	}
	return 0;
}