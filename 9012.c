#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char ch;
	struct node* link;
}node;

node* parenthesis_open(node* list, char s)
{
	
	node* new_node = (node*)malloc(sizeof(node));
	new_node->ch = s;
	new_node->link = list;//list���� first�� ����Ű�� node�� �ּҰ��� ����Ǿ� �ִ�.
	return new_node;//new_node�� ����� ���� �Ҵ�� node�� �ּҰ��� ��ȯ��
}

node* parenthesis_close(node* list,int *check)
{
	if(list!=NULL&&list->ch=='(')
	{
		node* temp = list->link;
		printf("%c\n", list->ch);
		free(list);
		return temp;
	}
	*check = 1;
	return list;
}

void remove_node(node*first,int *check)
{
	while (first != NULL)
	{
		node* temp = first->link;
		free(first);
		first = temp;
		*check = 1;//first�� null�� �ƴ϶�� ���� (��)�� ������ ��ġ���� �ʴ´ٴ� ���̴�.
	}
}


int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();//���� ���� ����
	while (n--)
	{
		node* first = NULL;//node�� ����Ű�� ������ ����
		int check = 0;
		char c;
		while ((c = getchar()) != '\n')
		{
			if (c == '(')
			{
				first = parenthesis_open(first, c);//first�� ����Ű�� node�� �ּҰ��� ����, �Է¹��� ���� c�� ����
			}
			else if(c==')')
			{
				first = parenthesis_close(first, &check);
			}
		}

		remove_node(first,&check);
		if (check==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}