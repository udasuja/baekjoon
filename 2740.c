#include <stdio.h>
#define SIZE 100

int main(void)
{
	int A[SIZE][SIZE];
	int B[SIZE][SIZE];
	int n,k,m;
	int i,j,h;
	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;i++)//A에 원소 삽입
	{
		for(j=0;j<k;j++)
		{
			scanf("%d",&A[i][j]);
		}

	}
	scanf("%d %d",&k,&m);
	for(i=0;i<k;i++)//B에 원소 삽입
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	for(i=0;i<n;i++)//행렬 곱 시작 A의 row vector와 B의 column vector를 내적한다.
			//그러기 위해 A의 row vector의 번호를 고정시키고
			//B의 column vector의 번호만을 움직이여 A의 row vector에서의 각각의 원소와
			//그에 해당하는 B의 column vector에서의 각각의 원소를 곱하여 더함으로써 내적을 한다.
	{
		for(h=0;h<m;h++)//B의 column vector의 번호를 증가시킴
		{
			int sum=0;
			for(j=0;j<k;j++)//B의 column vector내의 각각의 원소와 A의 row vector의 각각의 원소를 곱하고 더한다.
			{
				sum+=(A[i][j]*B[j][h]);
			}
			printf("%d ",sum);
		}
		printf("\n");
	}

}
