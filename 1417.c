/*
다솜이의 기호1번
다솜이를 제외한 다른 후보들의 득표수를 퀵정렬을 이용하여 내림차순으로 정렬한다.

*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)//*a가 *b보다 작을때
	{
		return -1;
	}
	else if (num1 < num2)//*a가 *b보다 클때
	{
		return 1;
	}
	else//서로 같을때
		return 0;
}

int main(void)
{
	int n,i;
	int* arr;
	int dasom,least=0;

	scanf_s("%d", &n);
	arr = (int*)malloc(sizeof(int) * (n-1));//다솜이를 제외한 다른 후보들의 득표수를 저장
	scanf_s("%d", &dasom);
	for (i = 0; i < n-1; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	do
	{
		
		qsort(arr, n-1, sizeof(int), compare);
		if (dasom <= arr[0])
		{
			least += 1;
			dasom += 1;
			arr[0] -= 1;
			qsort(arr,n-1, sizeof(int), compare);
		}
	} while (dasom <= arr[0]);//다솜이가 득표수가 가장 많은 후보가 아닐때 반복한다.
	printf("%d", least);
}