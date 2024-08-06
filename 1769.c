#include <stdio.h>

void change(char*x,int n)
{
	char stack[1000001];
	int i,k;
	for(i=0;n>0;i++,n=n/10)//스택에다가 n을 10으로 나눈 나머지 값을 순서대로 저장
	{
		int re=n%10;
		stack[i]=re+'0';
	}
	x[i]='\0';//stack의 길이에 해당하는 요소에 널문자을 넣는다.
	for(i-=1,k=0;i>=0;i--,k++)//x는 널문자를 제외하고 맨 뒤에서부터 stack의 값을 받아들인다.
	{
		x[i]=stack[k];
	}
	return;
}



int main(void)
{
	char i=0,count=0;
	char x[1000001];
	scanf("%s",x);
	while(x[1]!='\0')//만약 x가 1의 자리밖에 안 남으면 반복을 종료한다.
	{
		int k,sum=0;
		for(k=0;x[k]!='\0';k++)//각 자리수를 더한다.
			sum+=x[k]-'0';
		sprintf(x,"%d",sum);	
		count++;
	}

	printf("%d\n",count);
	if((x[0]-'0')%3==0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
