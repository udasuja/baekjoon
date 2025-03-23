/*
n을 입력받고 b를 입력받는다.
n을 b로 나머지 연산을 진행한다.
나머지를 역순으로 출력한다. 그러기 위해 stack구현이 필요하다.
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