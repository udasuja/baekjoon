/*
양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다
첫째 줄에 N의 진짜 약수의 개수가 주어진다. 이 개수는 50보다 작거나 같은 자연수이다. 둘째 줄에는 N의 진짜 약수가 주어진다.=>이때 N를 구하시오
가장 작은 값과 가장 큰 값을 구해 곱한다.
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