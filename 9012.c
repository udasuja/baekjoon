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
		new_node->link = list;//list에는 first가 가리키는 node의 주소값이 저장되어 있다.
		return new_node;//new_node에 저장된 동적 할당된 node의 주소값을 반환함
	}
	else if (s == ')' && list->ch == '(')//first가 가리키는 노드가 (를 저장하고 입력받은 문자가 )일때
	{
		node* next_node = list->link;//삭제할 노드가 가리키는 다음 노드의 주소값을 저장함
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
	node* first = NULL;//node를 가리키는 포인터 변수
	int n;
	scanf("%d", &n);
	getchar();//개행 문자 제거
	while (n--)
	{
		char c;
		while ((c = getchar()) != '\n')
		{
			if (c == '(' || c == ')')
			{
				first = parenthesis(first, c);//first가 가리키는 node의 주소값을 전달, 입력받은 문자 c를 전달
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