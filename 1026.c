/*
a배열은 내림차순
b배열은 오름차순으로 배열후 곱하면 최솟값을 구할 수 있다.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n=0;
	int min=0;
	int* arr1;
	int* arr2;
	int total = 0;
	int* descending;

	scanf_s("%d", &n);
	arr1 = (int*)malloc(sizeof(int) * n);
	arr2 = (int*)malloc(sizeof(int) * n);
	descending = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr2[i]);
	}

	for (int i = 0; i < n; i++)
		//a행렬을 내림차순으로 배열한다.
	{
		for (int k = i; k < n; k++)
		{
			int temp;
			if (arr1[i] < arr1[k])
			{
				temp = arr1[i];
				arr1[i] = arr1[k];
				arr1[k] = temp;
			}
			if (arr2[i] > arr2[k])
			{
				temp = arr2[i];
				arr2[i] = arr2[k];
				arr2[k] = temp;
			}
		}
		total += (arr1[i] * arr2[i]);
	}
	printf("%d", total);
	return 0;
}