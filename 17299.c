/*
Ai�� ���� A���� ������ Ƚ���� F(Ai)��� ���� ��
Ai�� ����ū���� �����ʿ� �����鼭
���� A���� ������ Ƚ���� F(Ai)���� ū �� �߿���
���� ���ʿ� �ִ� ���� �ǹ��Ѵ�. 
�׷��� ���� ���� ��쿡 ����ū���� -1�̴�.

�׷� 17298ó�� ������ Ǯ��
stack�� ���� �� stack�� top�� ���ϴ� ���� ������ ���Ұ��� ���� �迭�� �ƴ�
F(Ai)�� ���� �迭�� ���ҿ� ���ϸ� �ȴ�.

�Է� �迭�� ���Ұ��� top�� ����Ű�� stack�� ���Ұ��� count�迭�� index�� �Ͽ� �� ������ F(Ai)���� �����Ѵ�. �׸��� ���� ���Ѵ�.

*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000

int stack[SIZE];
int sequ[SIZE];
int top = -1;

int empty(int top)
{
	return top == -1;
}

int main(void)
{
	int n, i;
	int* count = (int*)calloc(SIZE,sizeof(int));	//��� ���Ҹ� 0���� �ʱ�ȭ
	int s_ind;	//stack���� ������ ���� ���� ����Ǿ��Ѵ�. 

	scanf_s("%d", &n);
	for (i = 0;i < n;i++)
	{
		int ind;
		scanf_s("%d", &sequ[i]);
		ind = sequ[i];
		count[ind]++;	//�Է°��� Ƚ���� ����.
	}

	for (i = n - 1;i >= 0;i--)
	{
		int ind=sequ[i];	//i��° �Է°��� ind�� �־� count�� index�� Ȱ���Ѵ�.
		int result;

		while (!empty(top))
		{
			if (count[s_ind] > count[ind])	//����ū���� �߰��ϴ� ����
				break;
			top--;	//pop����
			s_ind = stack[top];	
		}

		if (empty(top))
//stack�� �� ����ٴ� ���� ���� ������ Ƚ���� ��� stack���� ����� ������ Ƚ������ ũ�ٴ� ���̴�.
		{
			result = -1;	
		}
		else
		{
			result = stack[top];	//����ū�� (stack�� top�� ���ǿ� �´� �Է� �迭�� ���Ҹ� ����Ű�Ƿ�)
		}

		stack[++top] = sequ[i];
		sequ[i] = result;	//������ sequ[i]�� stack�� �־������� sequ�� ������� �����ϴ� �迭�� ����.
		s_ind = stack[top];	//stack�� top�� ����Ű�� ���ҿ� ���� count���� ��� ���� stack�� top�� ����Ű�� ���Ҹ� index�� ��
	}
	for (i = 0;i < n;i++)
	{
		printf("%d ", sequ[i]);
	}

	free(count);
	return 0;
}