/*
�ټ����� ��ȣ1��
�ټ��̸� ������ �ٸ� �ĺ����� ��ǥ���� �������� �̿��Ͽ� ������������ �����Ѵ�.

*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)//*a�� *b���� ������
	{
		return -1;
	}
	else if (num1 < num2)//*a�� *b���� Ŭ��
	{
		return 1;
	}
	else//���� ������
		return 0;
}

int main(void)
{
	int n,i;
	int* arr;
	int dasom,least=0;

	scanf_s("%d", &n);
	arr = (int*)malloc(sizeof(int) * (n-1));//�ټ��̸� ������ �ٸ� �ĺ����� ��ǥ���� ����
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
	} while (dasom <= arr[0]);//�ټ��̰� ��ǥ���� ���� ���� �ĺ��� �ƴҶ� �ݺ��Ѵ�.
	printf("%d", least);
}