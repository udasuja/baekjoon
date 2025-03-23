/*
N을 문자열 배열에다가 저장한다. 배열의 크기는 10000라 하자
배열의 마지막 요소부터 차례대로 B^n을 곱하고 다 더한다. 
이때 n은 요소의 번호이다.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 10000


char arr[SIZE];

int main(void)
{
	int b, n,i=0;
	long long sum = 0;
	scanf_s("%s", arr,SIZE);
	scanf_s("%d", &b);
	
	n = strlen(arr);
	printf("%d\n", n);
	do
	{
		int value;
		if (arr[n] >= '0' && arr[n] <= '9')
			value = arr[n] - '0';
		else
			value = (arr[n] - 'A')+10;
		sum += value * (int)pow(b, i);
		i++;
	} while (n--);
	printf("%lld", sum);
}

