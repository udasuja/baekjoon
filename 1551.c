/*
ũ�Ⱑ N�� ���� A�� �־����� ��, �����̴� ������ �� ������ ���̸� �̿��ؼ� ũ�Ⱑ N-1�� ���� B�� ���� �� �ִ�.
���� ���, A = {5, 6, 3, 9, -1} �̾��� ��, B = {6-5, 3-6, 9-3, -1-9} = {1, -3, 6, -10}�� �ȴ�. ��, B[i] = A[i+1]-A[i]�� �ȴ�.
�� ���� k�� ���� ���� ���� B�� ����Ͻÿ�
�Է�: A������ ����, k�� �ݺ�
	  A����(�̶� ������ ���ڴ� ,(��ǥ)�� ���еȴ�.)=>�� �ڵ忡���� ������ �������� ���ߴ�.

Ǯ��:
���ڿ��� �Է¹ް� ,�� �������� ���ڿ��� �ɰ��� �� ���ڸ� ���� ���ڿ��� atoi()�Լ��� �������·� �ٲ۴�.
atoi("100")�̸� ����100�� ��ȯ�ȴ�.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(int* arr,int,int);

int main(void)
{
	int n,num_r;
	int* arr;
	int i,j=0;
	int last_comma=0;//���������� ���� ��ǥ�� ��ġ�� ������
	char arr_str[2020];//20���� ���ڰ� ��� 100�϶� ,�� �ι��� �����ؼ� �ִ� 2020���� char�޸𸮰� �־�ߵ�


	scanf_s("%d %d", &n, &num_r);
	arr = (int*)malloc(sizeof(int) * n);
	scanf_s("%s", arr_str,sizeof(arr_str));
	
	for (i = 0; arr_str[i] != '\0'; i++)//�ι��ڰ� ������ ������ �ݺ��Ѵ�.
	{
		char num_str[5];//-100�̶�� ���ڱ��� Ŀ��ġ�� ���ؼ��� ���� ������ ������ ������ 5���� �Ǿߵȴ�.(�ι��� ����)
		if (arr_str[i] == ',')//i��° ���ڰ� ,�϶� last_comma������ i-1�������� ���������ڸ� num_str�� �����Ѵ�.
		{
			int k;
			for (k = 0; last_comma < i; k++,last_comma++)
			{
				num_str[k] = arr_str[last_comma];
			}
			num_str[k] = '\0';//���ڿ��� �Ǳ����� �ǿ����ʿ� �ι��ڸ� �����Ͽ���.
			last_comma++;//,������ �����ϴ� ������ �� ������ ���ڸ� ����Ų��.
			arr[j++] = atoi(num_str);
		}
		else if (arr_str[i + 1] == '\0')//�������ڰ� �ι��ڶ��
		{
			int k = 0;
			while (last_comma < i + 1)
			{
				num_str[k++] = arr_str[last_comma++];
			}
			num_str[k] = '\0';
			arr[j] = atoi(num_str);
		}
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