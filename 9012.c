#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 52

int check(char* paren)
{
	int i,top = -1;
	for (i = 0; paren[i] != '\n'; i++)
	{
		if (paren[i] == '(')
		{
			top += 1;
		}
		else if(paren[i]==')')//i��° ���ڰ� )�ΰ�� top�� 0�̻��̸� (�� �� ���� ���Դٴ� ���̴�.
		{
			if (top == -1)//���� )�� �Է¹޾����� �տ� (���ڰ� ���� ���
				return 0;
			top--;
		}
	}
	return top == -1;//top�� -1�̶�� (�� )�� ���� ������� ���̴�.
}

int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();

	while (n--)
	{
		char paren[SIZE];
		fgets(paren, SIZE, stdin);

		if (check(paren))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
