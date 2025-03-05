/*
�ִ�����(gcd)�� ��
ù° �ٿ� �׽�Ʈ ���̽��� ���� t (1 �� t �� 100)�� �־�����. 
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. 
�� �׽�Ʈ ���̽��� ���� ���� n (1 < n �� 100)�� �־�����, 
�������� n���� ���� �־�����


�������� ���� �� �� ��ҵ��� ������ ����� gcd�� ���ϰ� �� ���� ���� ���Ѵ�. -> ������ ���� �ʿ�����Ƿ� ���ܵǾ���.
��Ŭ���� ȣ���� �����Ͽ� Ǭ��.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int* arr;
	int cnum;
}test_case;

//int compare(const void* a, const void* b);
int gcd(int ,int );


int main(void)
{
	int k;

	scanf_s("%d", &k);

	while (k--)
	{
		test_case t;
		int i,j;
		long long sum = 0;

		scanf_s("%d", &t.cnum);
		t.arr = (int*)malloc(sizeof(int) * t.cnum);
		for(i=0;i<t.cnum;i++)
			scanf_s("%d", &t.arr[i]);
//		qsort(t.arr, t.cnum, sizeof(int), compare);
		for (i = 0; i < t.cnum - 1; i++)//������ ��� �ٷ� �������� �ݺ�
			for (j = i; j < t.cnum - 1; j++)
				sum += gcd(t.arr[i], t.arr[j + 1]);
			

		printf("%ld\n", sum);
		free(t.arr);
	}
}

int gcd(int oper,int re)
{
	if (oper % re == 0)
		return re;
	return gcd(re,oper%re);
}

/*
int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	else if (*(int*)a > *(int*)b)
		return 1;
	else
		return 0;
}
*/