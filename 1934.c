/*
 * a와 b의 최대공약수는 b와 r의 최대공약수와 같다.
 */
#include <stdio.h>

int gcc(int a,int b)
{
	if(b==0)
		return a;
	return gcc(b,a%b);
}

int main(void)
{
	int t;
	int i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",(a*b)/gcc(a,b));
	}
	return 0;
}
			
