/*
L->Ŀ���� �������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
D->Ŀ���� ���������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
B->Ŀ�� ���ʿ� �ִ� ���ڸ� ������ (Ŀ���� ������ �� ���̸� ���õ�)
������ ���� Ŀ���� �� ĭ �������� �̵��� ��ó�� ��Ÿ������, 
������ Ŀ���� �����ʿ� �ִ� ���ڴ� �״����
P $->$��� ���ڸ� Ŀ�� ���ʿ� �߰���

����:
	�Է�
	abcd
	3
	P x     ->top�� 4��° �ε����� ����Ű�� �ű⿡ x�� ����ִ´�. �׸��� top���� 1������Ų��. 
	L		->top�� 5��° �ε����� ����Ű�ٰ� 3��° �ε����� ����Ų��.
	P y		->top�� 4��° �ε����� ����Ű�µ� �ű⿡�� x�� ����Ǿ���.
			  �׷��Ƿ� x�� ���������� �� ĭ �ű�� ���ڸ��� y�� ����
	���
	abcdyx


	�Է�
	abc
	9
	L->top�� 3�� �����ߴµ� L ������ 2�� ����
	L->top�� 1�� ����
	L->top�� 0�� ����
	L->top�� -1�� �����Ͽ� ���� ���� �ٴ޾Ҵٴ� ���� �ǹ���
	L->������ top�� -1�̴�.
	P x->top�� -1�̹Ƿ� 0��°���� ��� ���ڸ� ���������� �� ĭ �ű��.
		 �׸��� 0��°�� x�� ����ְ� top�� 1������Ų��.
	L ->top�� 0�̹Ƿ� -1�� �����.
	B ->top�� -1�̹Ƿ� �ƹ��͵� ���ŵ��� �ʴ´�.
	P y -> top�� -1�̹Ƿ� 0��° ���� ���ڸ� ���������� �ű��, 0��°�� ���ڸ� �ִ´�.
	���
	yxabc

	�Է�
	dmih
	11
	B  ->dmi
	B  ->dm
	P x->dmx
	L  ->top�� m�� ����Ŵ
	B  ->dx
	B  ->x
	B  ->x
	P y->yx
	D   
	D
	P z

	���
	yxz

���Ḯ��Ʈ�� ����� ������ �����Ͽ� �� ������ Ǯ �� ���� ���̶�� �����Ѵ�.(dmih�� �ԷµǾ��ٸ� h�� ���� ��ܿ� ��ġ, d�� ���� �ϴܿ� ��ġ)
L�� D�� ������ top���� ���� 1���ϰ�, 1���� ������ ������ �����ϰ�
B�� P�� ������ �� top�� ��ŭ ���Ḯ��Ʈ�� ���� top��ġ�� ���� �����ϰų� �� ��ġ�� ���ڸ� �߰��Ѵ�. 

�̶� top����ü�� �� ��° node�� ����Ű�� �ִ����� ���� �������� �� node�� ���� �ּҰ��� �����Ѵ�.
node�� �յ� node ��� ����Ű��, L�� �ԷµǸ� top-- �� �ڿ� node�� ����Ų��. ���� �ڿ� node�� null�̸� top���� -1�� ����


*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char c;
	struct node* left;
	struct node* right;
}node;

typedef struct 
{
	node* top_node;
	int top_int;
}Top;

int main(void)
{
	node last = { '\0',NULL,NULL };//������ node
	node first = { '\0',NULL,&last };//ù��° node
	Top top = { &first,-1 };
	int n;
	char ch;
	last.left = &first;//������ node�� left�� first�� ����Ű���� ��

	while ((ch = getchar()) != '\n')
	{
		node* new_node = (node*)malloc(sizeof(node));
		node* last_l = last.left;
		new_node->c = ch;
		new_node->left = last_l;
		new_node->right = &last;
		last.left = new_node;
		last_l->right = new_node;
		top.top_int += 1;
		top.top_node = new_node;
	}
	//top.top_int�� �� �ݺ������� �߰��� 'node�� ����-1��'�� ���� �����Ѵ�.

	scanf("%d", &n);
	getchar();
	while (n--)
	{
		char comm[5];
		fgets(comm, 5, stdin);

		switch (comm[0])
		{
		case 'L':
			if (top.top_int != -1)//���� ������ �ƴ϶��
			{
				top.top_int -= 1;//top_int�� 1�� ����
				top.top_node = (top.top_node)->left;//���� node�� ����Ű���� ��
			}
			break;
		case 'D':
			if ((top.top_node)->right != &last)//top.top_node�� right�� ����Ű�� node�� last�� �ƴϸ�
			{
				top.top_int += 1;
				top.top_node = (top.top_node)->right;
			}
			break;
		case 'B':
			if (top.top_node != &first)//top_int�� -1�̸� �� ���ʿ� �����Ƿ� ���� node�� ������ �� ����.
			{
				node* left_n = (top.top_node)->left;//left_n�� �����ҷ��� node ���� node�� ����Ų��.
				node* right_n = (top.top_node)->right;//right_n�� �����ҷ��� node ������ node�� ����Ų��.
				right_n->left = left_n;//A B C ������ �̷� ������ ����������� C node�� left�� B�� �ƴ� A�� ����Ű�� �ȴ�.
				left_n->right = right_n;//A node�� right�� B�� �ƴ� C�� ����Ű�� �ȴ�.
				free(top.top_node);
				top.top_int -= 1;//B node�� �����ǰ� top�� A�� ����Ű���� �Ѵ�.
				top.top_node = left_n;
			}
			break;
		case 'P':
		{
			node* new_node = (node*)malloc(sizeof(node));
		
			//A B ������ �̷� ������ ����Ǿ��ִ�. �̶� C node�� A�� B���̿� �߰��Ѵ�.
			node* last_n = (top.top_node)->right;//B node, top.top_node�� last���������� ����Ǳ⿡ right�� null�� ������ �ƴϴ�.
			new_node->c = comm[2];
			new_node->left = last_n->left;//C�� left�� A�� ����Ű���� ��
			new_node->right = last_n;//C�� right�� B�� ����Ű���� ��
			(last_n->left)->right = new_node;//A�� right�� C�� ����Ű���� ��
			last_n->left = new_node;//B�� left�� C�� ����Ű���� ��
			top.top_int += 1;
			top.top_node = new_node;
			break;
		}
		}
	}
	while ((first.right) != &last)
	{
		node* temp = first.right;
		printf("%c", temp->c);
		first.right = temp->right;
		free(temp);
	}

}