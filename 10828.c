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
			new_node->x = num;//new_node�� ����Ű�� node, �� ���� �Ҵ� ���� node�� x�� num����
			new_node->link = first.link;//first�� ����Ű�� node�� ���� �Ҵ� ���� node�� ����Ų��.
			first.link = new_node;//ó�� node�� ���� �Ҵ� ���� node�� ����Ű���� �Ѵ�.
			top += top==-1?2:1;
		}
		else if (!strcmp(instruc, "pop"))
		{
			if (first.link == NULL)//���ÿ� �ƹ��͵� ������ -1����Ѵ�.
				printf("-1\n");
			else
			{
				top -= top==1?2:1;
				printf("%d\n", (first.link)->x);//first��� node�� ����Ű�� node�� x���� ����Ѵ�. �װ��� ���� ���������� ����� ���̹Ƿ�
				if((first.link)->link==NULL)//first�� ����Ű�� node�� ������ node���
				{
					free(first.link);//��µ� node�� ���� �����Ѵ�.
					first.link = NULL;
				}
				else
				{
					node* temp = (first.link)->link;//first�� ����Ű�� node�� ����Ű�� node�� �ּҰ��� �����ϰ�
					free(first.link);
					first.link = temp;//�� �ּҰ��� first.link�� �����Ͽ� first�� ����Ű���� �Ѵ�. 
				}
			}
		}
		else if (!strcmp(instruc, "size"))
		{
			int size = top == -1 ? 0 : top;//top�� -1�̸� �ƹ��͵� ���� ���̱⿡ 0�� size�� �����Ѵ�.
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