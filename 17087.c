/*
���� ��ġ, ģ���� ��ġ�� �ϳ��� �迭�� �ְ� �������� �����Ѵ�.
n=1...�� �� n��° ���� n+1���� ���̸� ���ϰ�
n��° ���̿� n+1��° ���� �ֵ��� gcd�� ���� ū ���� ���Ѵ�.

1.�Է� �迭���� �������� �����ϰ�(���� ��ġ+ģ���� ��ġ=1+n��ŭ�� ũ�⸦ ���´�.)
2.���� ����� ���ҵ鳢�� �� ���� �迭�� �����Ѵ�. �̶� �� ���� �����ϴ� �迭�� ũ��� �Է� �迭�� ũ�⺸�� 1�۴�
3.�� �� ���� ����� �迭�� �������� �����Ѵ�.
4.�� ���� ���� ���� ���� �������� �� ���� ��� gcd�� ���ϰ� ���� ���� ���� ���Ѵ�.

4.�� �ٰŴ� ������ ����.
���� �Է��� �迭�� 1 3 7 11�϶� ���� ����� ���ҵ��� ���� ������ ����.
3-1=2
7-3=4
11-7=4
���� ��ġ�� 3�� ��
���� ���� ���� ���� �ƴ� ������ ���� �������� �ϸ� �� 4�� �������� �ϸ�
3-4=-1�̹Ƿ� ���� 1��ġ�� �� �� ���� �׷��⿡ ���� ���� ���� �������� �Ѵ�.
�׸��� gcd�� ���ϴ� ������ A_n�� A_n+1�� ���̰� 5�� �� d=2�δ� �� �� ����.
�׷��⿡ ���� 5�� ���� 2�� �ִ������� ���ϴ� ���̴�.

�� ������ �� �� ���� ���� ���� �������� ��� ������ ���� gcd�� ���ϴ� �� �� ���� ���� ���� ���ϸ� ���� ���� �� �ִ�.


*/


#include <stdio.h>
#include <stdlib.h>
#define MIN(A,B) (A<B?A:B)

int compare(void const* a, void const* b);
int gcd(int, int);

int main(void)
{
	int n;
	int* seq,*dis;
	int i,k;
	int co ;

	scanf_s("%d", &n);
	seq = (int*)malloc(sizeof(int) * (n + 1));
	dis = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i < n+1; i++)
		scanf_s("%d", &seq[i]);
	
	qsort(seq, n + 1, sizeof(int), compare);//1
	
	for (k=0; k<n; k++)//2
		dis[k] = seq[k+1] - seq[k];
	
	qsort(dis, n, sizeof(int), compare);//3


//4
	co = dis[0];
	for(k=1;k<n;k++)
	{
		co = MIN(co, gcd(dis[0], dis[k]));
	}
	printf("%d\n", co);
	return 0;
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