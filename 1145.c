/*
ù°�ٿ� 5���� ���� �Է��ϰ� ������δ� �Էµ� �� �� 3�� �̻����� ������ �������� ���� ���� ��
brute force algorithm�̹Ƿ� �׳� ������ ������� ������ �ذ��ϰڴ�.
Ǯ��:5���� �� �� �߰����� ã�� �� �߰� ������ 1�� �������� 3�� �̻����� ������ �������� ���� ���� ���� ���Ѵ�.
*/

#include <stdio.h>
#define MAX(a,b) a>b?a:b

int middle_number(int arr[]);

int main(void)
{
	int arr[5],i;
	int middle;

	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	middle = middle_number(arr);
	while (1)
	{
		int count = 0;
		for (i = 0; i < 5; i++)
		{
			if (middle % arr[i] == 0)
				count++;
		}
		if (count > 2)
			break;
		else
			middle++;
	}
	printf("%d", middle);
	return 0;
}

int middle_number(int arr[])
{
	int replica[5]={arr[0],arr[1],arr[2],arr[3],arr[4]};//arr�迭�� ������ �迭
	int k,j,max_index=0,max;

	for (k = 0; k < 3; k++)//�߰����� ã�� ���̱⿡ 3�� �ݺ��Ͽ� 5���� ���� ū ���� 2��°�� ū ���� �����ϸ� 3��°�� ū ���� ã�´�.
	{
		for (j = 0; j < 5; j++)
		{
			max = MAX(replica[j], replica[max_index]);
			if (max == replica[j])
				max_index = j;
		}
		//�� �ݺ������� ���� �ִ밪�� �ִ� ��ҿ� �����Ͽ� �� ��ҿ� �ִ� ���� 0���� �����.
		if(k<2)
			replica[max_index] = 0;
	}
	return replica[max_index];
	
}