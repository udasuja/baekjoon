/*
 *등차수열 공식 s=n(a1+an)/2=n(a1+a1+(n-1)d)/2

 이때 연속된 자연수의 합이므로 공차는 1이다.
 즉 s=n(2a1+n-1)/2
 (2s-n^2+n)/(2*n)=a1
 그럼 n은 1부터 늘려가면서 우변의 값이 0이 될 때까지 반복한다.
 a1은 자연수이기에 우변이 자연수 값을 반환하면 그때 가지수를 1증가시킨다.
 *
 */

#include <stdio.h>
#define PRODUCT(s,n) ((2*s)-(n*n)+n)

int main(void)
{
	int s,i,a1,num=0;
	scanf("%d",&s);
	a1=s;
	for(i=1;PRODUCT(s,i)/(2*i)>0;i++)
	{
		if(PRODUCT(s,i)%(2*i)==0)
		{	
	
			num++;
		}
	}
	printf("%d",num);
}
