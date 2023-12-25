#include <stdio.h>
#include <stdlib.h>
#define NUMBER 1000000

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
	{
		return 1;
	}
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int n, i;
	int arr[1000000]={0};

	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	qsort(arr, (sizeof(arr) - sizeof(int) * n) / sizeof(int), sizeof(int), compare);
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}