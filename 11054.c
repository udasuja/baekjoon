/*
���� S�� � �� Sk�� �������� S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN�� �����Ѵٸ�, �� ������ ������� �����̶�� �Ѵ�.

���� ���, {10, 20, 30, 25, 20}�� {10, 20, 30, 40}, {50, 40, 25, 10} �� ������� ����������, 
{1, 2, 3, 2, 1, 2, 3, 2, 1}�� {10, 20, 30, 40, 20, 30} �� ������� ������ �ƴϴ�.
���� A�� �־����� ��, �� ������ �κ� ���� �� ������� �����̸鼭 ���� �� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
Ŀ���ٰ� �߰��� �������� �۾����ߵȴ�.
�������� ���� ������ ¦���� n/2�� (n/2)+1�߿��� n/2�� �� Ŀ�ߵȴ�.
Ȧ���� n+1/2�� �������� ���������� �� ���� �� ĭ ���ʺ��� �� �۾ƾߵȴ�.
�Է�:ù°��=>������ ũ��
	 ��°��=> ����

���ڸ� �Է¹ް�
��� ���ڸ� �˻��Ѵ�.
�����̳� ���������� ���� ������ �Ǵ� ���ں��� ������ �� �߿��� ���� ū ���� ã�� ū ���� �ΰ��� ������ �Ǵ� ���ڿ� ����� ������ ���̸� ����
�׸��� ������ �Ǵ� ���ڸ� ��� ã�� �� ���ڷ� ��ü�Ѵ� �ٽ� ���κ��� �ݺ��� �������δ� 
�迭 ��Ұ� 0�� �ɶ����� ���������δ� �迭 ��Ұ� n-1�� �ǵ��� �Ѵ� �Ǵ� ��½ ������ ��� �ּҰ��� �� ã�� ��쿡 ���̸� ���� ���� ����
Ʋ������=> �Է�:(7, 1 6 7 2 3 4 5) �� :4 �� ���α׷�: 5��� 

*/
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b

int L_check(int, int*,int);//���ʸ� �˻��Ѵ�.(�̶� �Լ��� arr�迭 �̸��� �ش��ϴ� �ּҰ��� �༭ �Լ��������� arr�迭�� �̿��� �� �ֵ��� �Ѵ�.)
int R_check(int, int*,int,int);//�����ʸ� �˻��Ѵ�.

int main(void)
{
	int n, i, max1 = 0, max2 = 0;
	int* arr;

	scanf_s("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		int lengh = 1;
		lengh += L_check(arr[i], arr, i);
		printf("<=left\n");
		lengh += R_check(arr[i], arr, i, n);
		printf("<=right\n");
		
		max2 = max(max2, lengh);
	}
	printf("\n%d", max2);
}

int L_check(int max_l, int* arr,int i)
{
	int k,num=0,element=0,lengh=0;
	int num1 = 0;
	int left = i;
	while (1)
	{
		for (k = left-1; k >= 0; k--)
		{
			num = arr[k] < max_l ? max(arr[k], num) : num;//max_l(������ �Ǵ� ����)���� �����鼭 ������ �Ǵ� ���ڸ� �����ϰ� ���� ū ��
			element = num == arr[k]&&arr[k] != arr[element] ? k : element;//�׸��� max�� ��� ���� ��num���� arr[k]���� ũ�� num==arr[k]�� �ǹǷ� element�� k�� ����ִ´�.
		}
		if ((num1!=0 && left == element)||num==0)
		{
			break;
		}
		else
		{

			printf("%d", num);
			max_l = num;
			left = element;
			num =  0;
			num1 = 1;
			lengh++;
		}
	}
	return lengh;
}
int R_check(int max_r, int* arr, int i,int n)
{
	int k, num = 0, element = 0, lengh = 0;
	int num1 = 0;
	int right = i;
	while (1)
	{
		for (k = right + 1; k<n; k++)
		{
			num = arr[k] < max_r ? max(arr[k], num) : num;//max_r(������ �Ǵ� ����)���� �����鼭 ������ �Ǵ� ���ڸ� �����ϰ� ���� ū ��
			element = num == arr[k]&& arr[k]!=arr[element] ? k : element;//�׸��� max�� ��� ���� ��num���� arr[k]���� ũ�� num==arr[k]�� �ǹǷ� element�� k�� ����ִ´�.
			//arr[k]!=arr[element]�� arr[k]�ִ밪���� �Ǿ����� ���� �ִ밪�� arr[element]�� ������ ���� ���� ���� �����ϱ� ���ؼ� �� �ڵ��.
		}
		if ((num1 != 0 && right == element)||num==0)
		{
			break;
		}
		else
		{	
			printf("%d", num);
			max_r = num;
			right = element;
			num = 0;
			num1 = 1;
			lengh++;
		}
	}
	return lengh;
}