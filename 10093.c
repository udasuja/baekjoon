/*
�� ���� ������ �־����� ��, �� �� ���̿� �ִ� ������ ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
long long �ڷ����� ����ؼ� ������Ѵ�.
*/

#include <stdio.h>

int main(void)
{
	long long a, b;
	scanf_s("%lld %lld", &a, &b);
	if (b > a)
	{
		printf("%lld\n", b - a - 1);
		while (a < b - 1)//b���� ��µǴ� ���� �������� b-1���� �ݺ��Ѵ�. a=b-2�϶� ++a�� b-1�� ��µȴ�.
		{
			printf("%lld ", ++a);
		}
	}
	else if (b<a)
	{
		printf("%lld\n", a - b - 1);
		while (b < a - 1)
		{
			printf("%lld ", ++b);
		}
	}
	else if(a==b)
		printf("0");
}