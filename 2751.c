#include <stdio.h>
#include <stdlib.h>

void select(int* arr,int);

int main(void)
{
	int n, i;
	int* arr;

	scanf_s("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	select(arr, n);
	for (i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}

void select(int* arr,int n)
{
	int i, k;

	for (i = 0; i < n; i++)
	{
		int temp = i, swap = arr[i];
		for (k = i; k < n; k++)
		{
			if (arr[temp] > arr[k])
			{
				temp = k;
			}
		}
		arr[i] = arr[temp];
		arr[temp] = swap;
	}
}