/*
algorithm:

전역변수:
one=0
zero=0
minus=0
이차원 배열

함수(row의 시작 주소값, column의 시작 주소값,n값):
recursive=0;
//모든 원소를 조사한다.
for(r=row;r<row+n;r++)//row+n-1이 matrix의 마지막 row 주소값이므로 row+n바로 이전까지만 접근한다.
	for(c=row;c<col+n;c++)//col+n-1이 matrix의 마지막 col 주소값이므로 col+n바로 이전까지만 접근한다.
		만약 한 개 원소라도 다르면
			recursive=1;
			break;

if(recursive==0) //matrix내의 모든 원소가 다 같으면
	if arr[0]==1
		one+=1;
	else if arr[0]==-1
		minus+=1;
	else
		zero+=1;
	return
//matrix내의 원소가 적어도 1개 다를 경우->
else	
			//matrix를 9등분 했을때 각 submatrix의 row와 col의 주소값은 n/3차이가 난다.
			  그렇기에 다음 submatrix에 접근하기 위해 i와 k에 값에 n/3를 더해 다음 submatrix에 시작 주소값에 접근한다.

	for(i=row;i<row+n;i+=n/3)
		for(k=col;k<col+n;k+=n/3)
		재귀함수(i,k,n/3)
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
	//모든 원소를 조사한다.
	for (; r < row+n; r++)//(n+row혹은 n+col)-1은 matrix의 마지막 row와 col의 주소값를 나타낸다. 
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