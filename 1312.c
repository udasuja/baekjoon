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
		
		//어차피 n이 다하면 끝나는 반복문이므로 전에 있던 조건문은 필요가 없다.
		//re<b이면 나머지는 어차피 0이 나오기 때문이다.
		result=re/b;//나머지를 b로 나누면 k번째 자리수를 구할 수 있다.
		re=re%b;
	}
	printf("%d",result);
}