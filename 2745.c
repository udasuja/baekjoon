/*
N�� ���ڿ� �迭���ٰ� �����Ѵ�. �迭�� ũ��� 10000�� ����
�迭�� ������ ��Һ��� ���ʴ�� B^n�� ���ϰ� �� ���Ѵ�. 
�̶� n�� ����� ��ȣ�̴�.
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

