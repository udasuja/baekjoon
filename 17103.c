/*
�����佺�׳׽��� ü�� n���� �̳��� �Ҽ��� �Ǻ��Ѵ�. 
�Ҽ��� -1�� ���� �˻����� �ʴ� ���� 0���� 
�Ҽ� �̿��� ���� 1�̻����� �д�.
�Ҽ��� �Ǻ��� �� 2���� �����Ͽ� n�� �� �� 
�� ���� �Ҽ��� ��� ���� 1������Ų��. 
�̷� ������ ��°��� ã�� �� �ִ�.
*/

#include <stdio.h>
#include <stdlib.h>
#define PRI -1


int main(void)
{
	int t;

	scanf_s("%d", &t);

	while (t--)
	{
		int i,n;
		int *arr;
		int sum = 0;

		scanf_s("%d", &n);

		arr = (int*)calloc(n+1, sizeof(int));
		//�Ҽ� �Ǻ�
		for (i = 2; i < n + 1; i++)
		{
			int k;
			int j=1;

			if (arr[i] == 0)
			{
				arr[i] = PRI;
			}

			for (k = i * (1 + j); arr[i]==PRI && k < n + 1; k =i*(1+ j))
			{
				arr[k] += 1;
				j++;
			}
		}

		//������ ��Ƽ��
		for (i = 2; i < n + 1; i++)
		{
			if (arr[i] == PRI)
			{
				int diff = n - i;
				sum+=arr[diff] = arr[diff] == PRI ? 1 : 0;
				
			}
		}
		printf("%d\n", sum);
		free(arr);
	}
}