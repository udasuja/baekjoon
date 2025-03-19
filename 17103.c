/*
�����佺�׳׽��� ü�� n���� �̳��� �Ҽ��� �Ǻ��Ѵ�. 
�Ҽ��� 1�� ���� �˻����� �ʴ� ���� 0���� 
�Ҽ� �̿��� ���� -1�̻����� �д�.
�Ҽ��� �Ǻ��� �� 2���� �����Ͽ� n�� �� �� 
�� ���� �Ҽ��� ��� ���� 1������Ų��. 
�̷� ������ ��°��� ã�� �� �ִ�.


�� textcase�� ������ n�� �Է¹ް� �� n������ �Ҽ��� �����佺�׳׽��� ü�� �Ǻ��ϴ� �ͺ���
�ѹ��� ������ ���� ���� �Ҽ��� �Ǻ��ϴ� ���� �ξ� �ð� ���⵵ ���鿡�� �̵��̴�.
*/

#include <stdio.h>
#include <stdlib.h>
#define PRI 1
#define SIZE 1000000

int arr[SIZE+1];

void prime_number(void)
{
	int i;	
	for (i = 2; i <= SIZE; i++)
		arr[i] = 0;	//�ϴ� 0���� �ʱ�ȭ
					//�� �ڵ�� �ʿ���� �ϴ� arr�� ���������̹Ƿ� ������ 0���� �ʱ�ȭ�ȴ�.
					
	//�Ҽ� �Ǻ�
	for (i = 2; i < SIZE + 1; i++)
	{
		int k;
		arr[i] = arr[i] == 0 ? PRI : arr[i];//arr[i]�� �Ҽ���, �Ҽ��� �ƴ� ����(arr[i]==0) PRI�� ����
										//arr[i]!=0�̸� ���� �ݺ����� ���� -1�� ������ ���̴�.
		for (k = i + i; arr[i]==PRI && k < SIZE + 1; k += i)
		{
			arr[k] = -1;	//�Ҽ��� �ƴ� ��
		}
	}
	return;
}

int main(void)
{
	int t;
	prime_number();//�Ҽ� �Ǻ�
	scanf_s("%d", &t);
	while (t--)
	{
		int i,n;
		int sum = 0;

		scanf_s("%d", &n);

		//������ ��Ƽ��
		for (i = 2; i <= n /2; i++)
		{
			if (arr[i] == PRI&&arr[n-i]==PRI)
			{
				sum+=1;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}