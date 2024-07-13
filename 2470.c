/*
 * N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.
 *
 * 입력
 * 첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 
 * 그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 
 * 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다. 
 * N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.
 *
 * 출력
 * 첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.
 *
 * 예제 입력  
 * 3 2
 * 1 2
 * 3 4
 * 5 6
 * 2 3
 * -1 -2 0
 *  0 0 3
 *  예제 출력  
 *  -1 -2 6
 *  -3 -6 12
 *  -5 -10 18
 *
 *  행렬 곱은 A의 ROW VECTOR들과 B의 COLUMN VECTOR들의 내적으로 구한다.
 *  즉   ___________________
 *  	 |A1*B1 A1*B2 A1*B3|
 *    P= |A2*B1 A2*B2 A2*B3|
 *  	 |A3*B1 A3*B2 A3*B3|이다.
 *  	 |_________________|
 *  이때 A와 B를 stack으로 구현한다.
 *  malloc으로 A의 벡터들과 B의 벡터들을 구현한다. 이때 A는 ROW로 B는 COLUMN으로 저장한다.
 *  stack형태로 B1 B2 B3를 차례대로 불어온다.
 * 
 */


#include <stdio.h>
#define size 100

void inseart(int (*ma)[size])
{
	int row,col;
	int i,k;

	scanf("%d %d",&row,&col);
	for(i=0;i<row;i++)
	{
		for(k=0;k<col;k++)
		{
			scanf("%d",&ma[i][k]);
		}
	}
}

void matrix_product(int (*A)[size],int(*B)[size])
{

}		

int main(void)
{
	int A[size][size]={0};
	int B[size][size]={0};
	
	
	inseart(A);
	inseart(B);
	
	
}
