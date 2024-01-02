/*
입력 받은 n에 100으로 나눈 나머지로 n+1을 나눴을 때 나오는 나머지가 0이면 Good출력 아니면 Bye출력 
*/

#include <stdio.h>

int main(void)
{
	int n, t,i;
	int hundred;

	scanf_s("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf_s("%d", &n);
		hundred = n % 100;
		if ((n + 1) % hundred == 0)
			printf("Good\n");
		else
			printf("Bye\n");
	}
	return 0;
}