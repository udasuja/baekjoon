/*
�� ���� ����:

left_stack: Ŀ�� ���ʿ� �ִ� ���ڵ�.
right_stack: Ŀ�� �����ʿ� �ִ� ���ڵ�.

��ɾ� ó��:

L: ���� ���ÿ��� ������ �������� pop & push. ���� ���� top-=1,������ ���� top+=1
D: ������ ���ÿ��� ���� �������� pop & push. ���� ���� top+=1, ������ ���� top-=1
B: ���� ���ÿ��� pop. ���� top-=1
P: ���� ���ÿ� push. ���� top+=1

��� ���:

�������� ���� ���ÿ� ���� ���ڵ��� ������ ���ÿ� �ٽ� push�� ��, ������ ������ �������� ���.
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
	if (!empty(start))//stact�� ���Ұ� ���� ���
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
			//	L: ���� ���ÿ��� ������ �������� pop& push.���� ���� top -= 1, ������ ���� top += 1
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
			//	D : ������ ���ÿ��� ���� �������� pop & push.���� ���� top += 1, ������ ���� top -= 1
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
			//	B : ���� ���ÿ��� pop.���� top -= 1
		case 'B':
		{
			if (!empty(&left))
			{
				pop(&left);
				top_l--;
			}
			break;
		}
			//	P : ���� ���ÿ� push.���� top += 1
		case 'P':
		{
			push(&left, comm[2]);
			top_l++;
			break;
		}
		}

	}
	//���� ���ÿ� ���� ���ڵ��� ������ ���ÿ� �ٽ� push�� ��, ������ ������ �������� ���.
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