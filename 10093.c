/*
두 양의 정수가 주어졌을 때, 두 수 사이에 있는 정수를 모두 출력하는 프로그램을 작성하시오.
long long 자료형을 사용해서 입출력한다.
*/

#include <stdio.h>

int main(void)
{
	long long a, b;
	scanf_s("%lld %lld", &a, &b);
	if (b > a)
	{
		printf("%lld\n", b - a - 1);
		while (a < b - 1)//b까지 출력되는 것을 막기위해 b-1까지 반복한다. a=b-2일때 ++a로 b-1이 출력된다.
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