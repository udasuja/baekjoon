#include <stdio.h>
#include <stdlib.h>

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
	int *arr;

	scanf_s("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);//qsort함수는 배열,길이,각 원소의 메모리크기,비교함수를 인자로 갖는데
	//sizeof(arr)/sizeof(int)라 쓰면 arr의 크기는 *arr의 크기인 4로 나오고 그것을 int의 자료형으로 나누니 값은 1이된다.
	//그렇기에 길이는 n을 해야 정확하게 qsort함수를 사용가능하다.
	for (i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}