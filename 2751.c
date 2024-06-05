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

	qsort(arr, n, sizeof(int), compare);//qsort�Լ��� �迭,����,�� ������ �޸�ũ��,���Լ��� ���ڷ� ���µ�
	//sizeof(arr)/sizeof(int)�� ���� arr�� ũ��� *arr�� ũ���� 4�� ������ �װ��� int�� �ڷ������� ������ ���� 1�̵ȴ�.
	//�׷��⿡ ���̴� n�� �ؾ� ��Ȯ�ϰ� qsort�Լ��� ��밡���ϴ�.
	for (i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}