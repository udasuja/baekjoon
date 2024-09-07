#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	struct node* link;
}node;

int main(void)
{
	int n,top=-1;
	struct node first = { -1,NULL };
	scanf("%d", &n);
	while (n--)
	{
		char instruc[6];
		scanf("%s", instruc);
		if (!strcmp(instruc, "push"))
		{
			int num;
			node* new_node = (node*)malloc(sizeof(node));
			scanf("%d", &num);
			new_node->x = num;//new_node가 가리키는 node, 즉 동적 할당 받은 node의 x에 num저장
			new_node->link = first.link;//first가 가리키던 node를 동적 할당 받은 node가 가리킨다.
			first.link = new_node;//처음 node가 동적 할당 받은 node를 가리키도록 한다.
			top += top==-1?2:1;
		}
		else if (!strcmp(instruc, "pop"))
		{
			if (first.link == NULL)//스택에 아무것도 없으면 -1출력한다.
				printf("-1\n");
			else
			{
				top -= top==1?2:1;
				printf("%d\n", (first.link)->x);//first라는 node가 가리키는 node의 x값을 출력한다. 그것이 가장 마지막으로 저장된 값이므로
				if((first.link)->link==NULL)//first가 가리키는 node가 마지막 node라면
				{
					free(first.link);//출력된 node를 동적 해제한다.
					first.link = NULL;
				}
				else
				{
					node* temp = (first.link)->link;//first가 가리키는 node가 가리키는 node의 주소값을 저장하고
					free(first.link);
					first.link = temp;//그 주소값을 first.link에 저장하여 first가 가리키도록 한다. 
				}
			}
		}
		else if (!strcmp(instruc, "size"))
		{
			int size = top == -1 ? 0 : top;//top이 -1이면 아무것도 없는 것이기에 0을 size에 저장한다.
			printf("%d\n", size);
		}
		else if (!strcmp(instruc, "empty"))
		{
			if (top == -1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!strcmp(instruc, "top"))
		{
			if (first.link == NULL)
				printf("-1\n");
			else
				printf("%d\n", (first.link)->x);
		}
	}
}