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
	new_node->link = list;//list에는 first가 가리키는 node의 주소값이 저장되어 있다.
	return new_node;//new_node에 저장된 동적 할당된 node의 주소값을 반환함
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
		*check = 1;//first가 null이 아니라는 것은 (와)의 개수가 일치하지 않는다는 것이다.
	}
}


int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();//개행 문자 제거
	while (n--)
	{
		node* first = NULL;//node를 가리키는 포인터 변수
		int check = 0;
		char c;
		while ((c = getchar()) != '\n')
		{
			if (c == '(')
			{
				first = parenthesis_open(first, c);//first가 가리키는 node의 주소값을 전달, 입력받은 문자 c를 전달
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