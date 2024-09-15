/*
���� ���캸�� ������ ���� �����ϰڴ�.

�Է�:
8 -> n��
4
3
6
8
7
5
2
1

���� 1���� 4������ ���� ���ÿ� �ִ´�.-> +�� 4�� ����
�� ���� 4�� ������ ù��° �ڸ��� �����Ƿ� ���ÿ��� 4�� pop�ߴ�.-> -�� 1�� ����
3�� ������ �ι�° �ڸ��� �����Ƿ� ���ÿ��� 3�� pop�ߴ�. -> -�� 1�� ����
6�� ������ ����° �ڸ��� �����Ƿ� ������ 5�� 6�� push�ߴ�. �׸��� 6�� pop�ߴ�. -> +�� 2�� ������ -�� 1�� ����
8�� ������ �׹�° �ڸ��� �����Ƿ� ������ 7�� 8�� push�ߴ�. �׸��� 8�� pop�ߴ�. -> +�� 2�� ������ -�� 1�� ����
7�� ������ �ټ���° �ڸ��� �����Ƿ� ������ 7�� pop�ߴ�. -> -�� 1�� ����

linked list�� �����Ͽ� +Ȥ�� -�� element�� ����ִ´�.
�̶� arr[i]�� ���� ���� stack�迭 �ε��� �� ĭ ���� ���� 1�̸� NO�� ����ϰ� ���α׷��� �����Ѵ�.

�迭�� 2�� �����Ѵ�. �׸��� linked list�� �����Ѵ�.
�ϳ��� arr�� �ٸ� �ϳ��� �������� �����Ѵ�.
���ÿ��� k���� ���ʴ�� ����ִ´�.
�׸��� top�� �̿��Ͽ� ���ÿ� �󸶳� ���Դ��� �����Ѵ�.
push�� ���� k���� top���� ������Ű�� ���ÿ� �ְ� linked list���� +�� ����ִ´�.
�׸��� pop�� ���� top���� ���ҽ�Ű�� ���ÿ��� ���� ���Ž�Ų��. ���� pop�ϴ� ���� top�ε����� �ִ� ���� �ƴϸ� NO�� ����ϰ� �����Ѵ�.
push pop �ݺ����� ������ linked list�� ����� +�� ����Ѵ�. 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	char c;
	struct node* link;
}node;

int main(void)
{
	int i,n,k=0;
	int* stack, * arr;
	int top = -1;
	node* first=NULL;

	scanf("%d", &n);
	stack = (int*)malloc(sizeof(int) * n);
	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}


	for (i = 0; i < n; i++)
	{
		while (k < arr[i])//i��° ���� ���� ������ ũ�� push�� ������
		{
			node* new_node = (node*)malloc(sizeof(node));
			top++;//������ �ε����� �ش�
			k++;//���ÿ� �� ���� �ش�
			stack[top] = k;
			new_node->c = '+';
			new_node->link = first;//first�� ����Ű�� ���� new_node�� ����Ű��
			first = new_node;//first�� �����Ҵ�� ���ο� node�� ����Ų��.
	//		printf("k: %d, top: %d, stack[top]: %d ", k, top, stack[top]);
		}
	//	printf("\n");
		if (stack[top] != arr[i])//���� i��° ���� ���� ������ ������ �� �ݺ����� �������� �ʴµ�, top��° ���̶� �ٸ��� ���ÿ� �� ���� ���� �ƴ϶�� ���̴�.
		{
			printf("NO\n");
			return 0;
		}
		else 
		{
			node* new_node = (node*)malloc(sizeof(node));
			new_node->c = '-';
			new_node->link = first;
			first = new_node;
			stack[top] = 0;//�ʱ�ȭ
			top--;//����Ű�� �ε����� �ϳ� ���ҽ�Ų��.
		}
	}
	reflexive(first);

}