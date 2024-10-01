/*
algorithm:

��������:
one=0
zero=0
minus=0
������ �迭

�Լ�(row�� ���� �ּҰ�, column�� ���� �ּҰ�,n��):
recursive=0;
//��� ���Ҹ� �����Ѵ�.
for(r=row;r<row+n;r++)//row+n-1�� matrix�� ������ row �ּҰ��̹Ƿ� row+n�ٷ� ���������� �����Ѵ�.
	for(c=row;c<col+n;c++)//col+n-1�� matrix�� ������ col �ּҰ��̹Ƿ� col+n�ٷ� ���������� �����Ѵ�.
		���� �� �� ���Ҷ� �ٸ���
			recursive=1;
			break;

if(recursive==0) //matrix���� ��� ���Ұ� �� ������
	if arr[0]==1
		one+=1;
	else if arr[0]==-1
		minus+=1;
	else
		zero+=1;
	return
//matrix���� ���Ұ� ��� 1�� �ٸ� ���->
else	
			//matrix�� 9��� ������ �� submatrix�� row�� col�� �ּҰ��� n/3���̰� ����.
			  �׷��⿡ ���� submatrix�� �����ϱ� ���� i�� k�� ���� n/3�� ���� ���� submatrix�� ���� �ּҰ��� �����Ѵ�.

	for(i=row;i<row+n;i+=n/3)
		for(k=col;k<col+n;k+=n/3)
		����Լ�(i,k,n/3)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 2200//3^7

int one = 0, minus = 0,zero=0;
int arr[SIZE][SIZE];

void matrix(int row, int col, int n)
{
	int	recursive = 0;
	int r=row, c=col, i, k;
	int before = arr[r][c];
	//��� ���Ҹ� �����Ѵ�.
	for (; r < row+n; r++)//(n+rowȤ�� n+col)-1�� matrix�� ������ row�� col�� �ּҰ��� ��Ÿ����. 
	{
		for (c=col; c < col+n; c++)
		{
			if (before != arr[r][c])
			{
				recursive = 1;
				break;
			}
			before = arr[r][c];
		}
		if (recursive == 1)
			break;
	}
	if (recursive == 0)
	{
		if (arr[row][col] == 0)
		{
			zero += 1;
		}
		else if (arr[row][col] == -1)
		{
			minus += 1;
		}
		else
		{
			one += 1;
		}
		return;
	}
	else
	{
		for (i = row; i < row+n; i += n/3)
		{
			for (k = col; k < col+n; k += n/3)
				matrix(i, k, n / 3);
		}
	}
}

int main(void)
{
	int n;
	int i, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
			scanf("%d", &arr[i][k]);
	}
	matrix(0, 0, n);
	printf("%d\n%d\n%d\n", minus, zero, one);
}