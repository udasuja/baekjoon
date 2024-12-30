/*
Ǯ��
���� �����ϴ� ��� ������ double�� ����(���ڴ� ����)
����� %.2lf�� �Ҽ��� ��° �ڸ����� ����Ѵ�.

����ǥ��Ŀ� ���� ���ڿ��� �迭�� �����Ѵ�. -> A�迭
�� �� �� �ǿ����ڿ� ���� ���� �� �ٸ� �迭�� �����Ѵ�. -> B�迭

A�迭�� �ִ� �ǿ����ڸ� ���ʴ�� stack�� push�Ѵ�.
�̶� A�迭�� �ִ� �ǿ����ڴ� �����̹Ƿ�
B[����-'A']�� ������ �ǿ����ڿ� ���� ���� ����

�׸��� �����ڰ� ������ stack�� �ִ� �ǿ����ڸ� 2�� pop�Ѵ�.
�� �ǿ����ڸ� ���ʴ�� ���� ���� a,b�� �ִ´�.

switch������ �� �����ڿ� ���� ������ �Ѵ�(b '������' a). 
�׸��� �� ���� stack�� push�Ѵ�.
�� ������ A�迭�� �ι��ڿ� �ٴٸ� ������ �ݺ��Ѵ�.

�ι��ڿ� �����ϸ� stack���� ���� ������� ������� ���̴�.
�� ���� pop�Ͽ� ������� ����Ѵ�.
*/
#include <stdio.h>
#define SIZE 100

double stack[SIZE];	//stack���� �׻� �ǿ����� ���� ����ִ�. �ǿ����ڴ� �׻� ������ �տ� �´�. 
int top = -1;

int main(void)
{
	char arr[SIZE];
	double count[26];	//����ڰ� �Է��� �ǿ������� ��
	int n,i;

	scanf_s("%d", &n);
	scanf_s("%s", &arr, SIZE);

	for (i = 0;i < n;i++)
	{
		scanf_s("%lf", &count[i]);
	}

	for (i = 0;arr[i]!='\0';i++)
	{
		if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')	//�������� ���
		{
			double b = stack[top--];//���߿� ���Ե� ��
			double a = stack[top--];//���� ���Ե� ��
			switch (arr[i])
			{
			case'+':
				stack[++top] = a + b;
				break;
			case'-':
				stack[++top] = a - b;
				break;
			case'*':
				stack[++top] = a * b;
				break;
			case'/':
				stack[++top] = a / b;
				break;
			default:
				break;
			}
		}
		else
		{
			stack[++top] = count[arr[i] - 'A'];
		}
	}
	printf("%.2lf", stack[top--]);

	return 0;
}
