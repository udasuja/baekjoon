/*
Ǯ��:
	getchar()�Լ��� ���� �ϳ��� �Է¹ް� 0�� �ƽ�Ű�ڵ尪 ��ŭ �� ���� �����ش�.
*/

#include <stdio.h>

int main(void)
{
	int sum = 0;
	int t, c,i;

	scanf_s("%d", &t);
	c = getchar();//scanf�� ���� �Է¹��ۿ� ���� ����Ű ���� �����ϱ� ���� �ڵ�
	for (i = 0; i < t; i++)
	{
		c = getchar();
		sum += c - '0';
	}
	printf("%d", sum);
}
