/*
��� A�� N�� ��¥ ����� �Ƿ���, N�� A�� ����̰�, A�� 1�� N�� �ƴϾ�� �Ѵ�
ù° �ٿ� N�� ��¥ ����� ������ �־�����. �� ������ 50���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� N�� ��¥ ����� �־�����.=>�̶� N�� ���Ͻÿ�
���� ���� ���� ���� ū ���� ���� ���Ѵ�.
*/

#include <stdio.h>

#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a

int main(void)
{
	int n, i,a;
	int max, min;
	scanf_s("%d", &n);
	scanf_s("%d", &a);
	max = min = a;
	for (i = 1; i < n; i++)
	{
		scanf_s("%d", &a);
		max = MAX(max, a);
		min = MIN(min, a);
	}
	printf("%d", max * min);
	return 0;
}