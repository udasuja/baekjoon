/*
���� ��ġ, ģ���� ��ġ�� �ϳ��� �迭�� �ְ� �������� �����Ѵ�.
n=1...�� �� n��° ���� n+1���� ���̸� ���ϰ�
n��° ���̿� n+1��° ���� �ֵ��� gcd�� ���� ū ���� ���Ѵ�.

1.�Է� �迭���� �������� �����ϰ�(���� ��ġ+ģ���� ��ġ=1+n��ŭ�� ũ�⸦ ���´�.)
2.���� ����� ���ҵ鳢�� �� ���� �迭�� �����Ѵ�. �̶� �� ���� �����ϴ� �迭�� ũ��� �Է� �迭�� ũ�⺸�� 1�۴�
3.��� �� ���� ���Ǵ� �ִ������� ã���� �ȴ�. �� ��� �� ���� ����� ����̸鼭 �ִ밪�� ã���� �ȴ�.
*/


#include <stdio.h>
#include <stdlib.h>
#define MIN(A,B) (A<B?A:B)

int compare(void const* a, void const* b);
int gcd(int, int);

int main(void)
{
	int n;
	int* seq;
	int i,k;
	int co ;

	scanf_s("%d", &n);
	seq = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i < n+1; i++)
		scanf_s("%d", &seq[i]);
	
	qsort(seq, n + 1, sizeof(int), compare);//1

//2,3
	co = seq[1]-seq[0];
	for(k=1;k<n;k++)
	{
		co = gcd(co,seq[k+1]-seq[k]);
	}
	free(seq);
	printf("%d\n", co);
	return 0;
}

//stack overflow�� �����ϱ� ���� ����Լ� ��� �ݺ������� gcd�� ����
int gcd(int oper, int re)
{
	while (re)//�������� 0�̸� �ݺ�����
	{
		int temp = oper % re;
		oper = re;
		re = temp;
	}
	return oper;

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