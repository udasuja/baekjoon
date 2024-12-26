/*
�迭�� ������ ���Һ��� for���� �����Ͽ� ���� stack�� top�� ����Ű�� ���� ���Ѵ�. 
���� ����Ű�� ������ ������ �迭�� ���� ���� �� ũ�� pop������ �ϰ� 
������ �� ���� ������ �迭�� ������ ��ū���� �ȴ�(�̶��� pop������ ���� ����). 
���� stack�� ��������� ������ ������ ��ū���� -1�� �ȴ�. 
(������ �迭�� ���Ұ����� ���� ���� pop������ ������ ��ū���� ��Ȱ���� �� �ִ�.
�� 3 2 7�� �� 2�� ��ū���� ���ѵ� pop������ ���ϱ� ������
2�� ��ū���� 7�� �� �� �ְ�, 3�� ��ū���� 7�� �� �� �ִ�.)
�׸��� ���� i�� ���� for���� ������ ����� ������ �迭�� ���Ұ��� push�ϴ� ���̴�.

*/

#include <stdio.h>
#define SIZE 1000000

int stack[SIZE];//���� ������ ������ ���ҵ��� stack�� ����
int sequ[SIZE];
int resu[SIZE];//���(��ū��) ����
int top = -1;

int empty(int top)
{
	return top == -1;
}

int main(void)
{
	int n, k;

	scanf_s("%d", &n);
	for (k = 0;k < n;k++)
	{
		scanf_s("%d", &sequ[k]);
	}

	for (k = n - 1;k >= 0;k--)
	{
		while (!empty(top) && stack[top] <= sequ[k])	
		//stack�� top���� ���� ���Һ��� �۰ų� ������ �� ���� pop�Ѵ�.
		{
			top--;//pop����
		}
		if (empty(top))
		{
			resu[k] = -1;	//��ū���� ���� ���
		}
		else
		{
			resu[k] = stack[top];	//stack�� top�� ��ū���� ���
		}

		stack[++top] = sequ[k];	//������ ���Ұ� push
	}
	for (k = 0;k < n;k++)
		printf("%d ", resu[k]);
	return 0;
}