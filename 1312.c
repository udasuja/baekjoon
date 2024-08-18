/*
 * A와 B를 나누고 나머지를 구한다. 만약 나머지가 B로 나누어 진다면 바로 나누는데 
 * 그것이 아니라면 나머지를 10곱하고 B로 나누어 본다. 
 * 만약 또 안나눠진다면 10을 곱하고 나눈다.(이때 자리수 1추가된다.)
 * 나머지가 0이라면 0을 출력 아니면 N번째 수까지 반복한다.
 */
#include <stdio.h>

int main(void)
{
	int a,b,n;
	long long re;
	int result=0;

	scanf("%d %d %d",&a,&b,&n);
	re=a%b;
	while(n--)
	{
		
		if(re==0)
			break;
		
		re*=10;//만약 나머지가 0이 아닌 경우 이때 당연하게도 나머지는 b보다 작을 것이다. 
		      //그렇기에 나머지에 10을 곱한다.
		if(re<b)
		{
			int re1=re;
			while(n>0)
			{
				if(re1>b)
				{
					re=re1;
					break;
				}
				re1*=10;
				re=0;
				n--;//앞의 반복문과 다르게 여기에 n--를 쓰는 이유는
				    //이때 반복문의 조건문에 n--을 쓰면 break로 인해 반복문을 탈출했을때 
				    //겉 반복문에 의해 이중으로 n--가 발동되기 때문이다.
			}
		}
		result=re/b;//나머지를 b로 나누면 k번째 자리수를 구할 수 있다.
		re=re%b;
	}
	printf("%d",result);
}
