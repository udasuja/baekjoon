/*
 * 이 문제처럼 타일이 붙여지면 가로축이 증가한뒤 세로축이 증가한다.
 * 즉 palindrome으로 가로축을 증가시키고 그 다음 세로축을 증가시킨다.
 * 이는 홀수면 세로축 짝수면 가로축을 증가시킨다. 
 *
 */

#include <stdio.h>

unsigned long long palindrome(int i)
{
	unsigned long long n0=0,n1=1,n2;//n0은 이전값, n1은 현재값, n2는 n1에 저장할 값을 임시 저장
	int k;
	unsigned long long row=1,cal=1;

	for(k=1;k<i;k++)
	{
		n2=n1+n0;//현재 시행에 대한 값을 임시 저장
		n0=n1;//이때 n1의 값은 이전 시행이 되었기에 n0에 저장
		n1=n2;//현재 시행에 대한 값 저장
		if(k%2==0)
			row+=n1;
		else
			cal+=n1;
	}
	return ((row*2)+(cal*2));
}

int main(void)
{
	int n;
	unsigned long long result;
	scanf("%d",&n);
	result=palindrome(n);
	printf("%llu",result);
	return 0;
}
