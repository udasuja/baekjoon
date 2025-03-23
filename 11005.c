/*
n�� �Է¹ް� b�� �Է¹޴´�.
n�� b�� ������ ������ �����Ѵ�.
�������� �������� ����Ѵ�. �׷��� ���� stack������ �ʿ��ϴ�.
*/

#include <stdio.h>
#define SIZE 10000

typedef struct
{
	int stack[SIZE];
	int top;
}STACK;

int main(void)
{
	int n, b;
	STACK s;

	s.top = -1;
	scanf_s("%d %d", &n, &b);

	while (n)
	{
		s.stack[++(s.top)] = n % b;
		n /= b;
	}
	while (s.top>-1)
	{
		int value = s.stack[(s.top)--];
		if (value < 10)
			printf("%d", value);
		else
			printf("%c",value+55);
	}
}