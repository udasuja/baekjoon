/*
���� ��ġ, ģ���� ��ġ�� �ϳ��� �迭�� �ְ� �������� �����Ѵ�.
n=1...�� �� n��° ���� n+1���� ���̸� ���ϰ�
n��° ���̿� n+1��° ���� �ֵ��� gcd�� ���� ū ���� ���Ѵ�.
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX(A,B) (A>B?A:B)

int compare(void const* a, void const* b);
int gcd(int, int);

int main(void)
{
	int n;
	int* seq,*dis;
	int i,k;
	int co = -1;

	scanf_s("%d", &n);
	seq = (int*)malloc(sizeof(int) * (n + 1));
	dis = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i < n+1; i++)
		scanf_s("%d", &seq[i]);
	qsort(seq, n + 1, sizeof(int), compare);
	for (i = 0; i < n; i++)
		dis[i] = seq[i + 1] - seq[i];

	for(i-=1;i>0;i--)
	{
		co = MAX(co, gcd(dis[i - 1], dis[i]));
	}
	printf("%d", co);
}

int gcd(int oper, int re)
{
	if (oper % re == 0)
		return re;
	return gcd(re, oper % re);
}

int compare(void const* a, void const* b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	else if (*(int*)a > *(int*)b)
		return 1;
	else
		return 0;
}