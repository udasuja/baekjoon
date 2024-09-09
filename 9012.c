#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char ch;
	struct node* link;
}node;

node* parenthesis(node* list, char s)
{
	if (s == '(')
	{
		node* new_node = (node*)malloc(sizeof(node));
		new_node->ch = s;
		new_node->link = list;//list���� first�� ����Ű�� node�� �ּҰ��� ����Ǿ� �ִ�.
		return new_node;//new_node�� ����� ���� �Ҵ�� node�� �ּҰ��� ��ȯ��
	}
	else if (s == ')' && list->ch == '(')//first�� ����Ű�� ��尡 (�� �����ϰ� �Է¹��� ���ڰ� )�϶�
	{
		node* next_node = list->link;//������ ��尡 ����Ű�� ���� ����� �ּҰ��� ������
		free(list);
		return next_node;
	}
	return list;
}

void remote(node* first)
{
	while (first == NULL)
	{
		node* temp = first->link;
		free(first);
		first = temp;
	}
}


int main(void)
{
	node* first = NULL;//node�� ����Ű�� ������ ����
	int n;
	scanf("%d", &n);
	getchar();//���� ���� ����
	while (n--)
	{
		char c;
		while ((c = getchar()) != '\n')
		{
			if (c == '(' || c == ')')
			{
				first = parenthesis(first, c);//first�� ����Ű�� node�� �ּҰ��� ����, �Է¹��� ���� c�� ����
			}
		}
		if (first == NULL)
		{
			printf("YES\n");
		}
		else
		{
			remote(first);
			printf("NO\n");
		}
	}
}