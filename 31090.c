/*
�Է� ���� n�� 100���� ���� �������� n+1�� ������ �� ������ �������� 0�̸� Good��� �ƴϸ� Bye��� 
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