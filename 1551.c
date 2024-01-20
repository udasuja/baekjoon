/*
ũ�Ⱑ N�� ���� A�� �־����� ��, �����̴� ������ �� ������ ���̸� �̿��ؼ� ũ�Ⱑ N-1�� ���� B�� ���� �� �ִ�.
���� ���, A = {5, 6, 3, 9, -1} �̾��� ��, B = {6-5, 3-6, 9-3, -1-9} = {1, -3, 6, -10}�� �ȴ�. ��, B[i] = A[i+1]-A[i]�� �ȴ�.
�� ���� k�� ���� ���� ���� B�� ����Ͻÿ�
�Է�: A������ ����, k�� �ݺ�
	  A����(�̶� ������ ���ڴ� ,(��ǥ)�� ���еȴ�.)

Ǯ��:
scanf�� �ϳ��� ���ڸ� �Է¹ް� getchar()�� �̿��Ͽ� ,�ϳ� �Է¹ް� �̰��� �ݺ��ϸ� n���� ���ڸ� �迭�� �����Ѵ�.
����Լ��� �̿��Ͽ� ���� B�� ����� ����Ѵ�.
*/

#include <stdio.h>
#include <stdlib.h>

void func(int* arr,int,int);

int main(void)
{
	int n,num_r;
	int* arr;
	int i;
	char c;
	scanf_s("%d %d", &n, &num_r);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
		c = getchar();
	}
	func(arr,n,num_r);
	free(arr);
	return 0;
}

void func(int* arr,int n,int num_r)
{
	int i = 0;
	if (num_r == 0)
	{
		printf("%d", arr[i++]);
		while (i < n)
		{
			printf(",%d", arr[i++]);
		}
		return;
	}

	while (i < n-1)//�迭�� 0���� �����ϹǷ� n���� ������ ����ϰ� ������ n-1���� �ݺ��Ǿߵȴ�.
	{
		arr[i] = arr[i + 1] - arr[i];
		i++;
	}
	arr[i] = 0;//�ݺ����� ������ i�� n-1�� �� ���̰� �� ����� ���� 0���� �����.(���� B�� ���� A���� ���̰� 1��ŭ ª���Ƿ�)
	func(arr, n - 1, num_r - 1);//num_r�� 0�� �� �� ���� B�� ����� �ݺ��Ѵ�.
}