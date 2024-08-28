#include <stdio.h>

int main(void)
{
	int n;
	int i,sum=0;
	char arr[7],d;

	scanf("%d %c",&n,&d);
	for(i=1;i<=n;i++)
	{
		int k;
		sprintf(arr,"%d",i);
		for(k=0;arr[k]!='\0';k++)
		{
		
			if(arr[k]==d)
				sum+=1;
		}
	}
	printf("%d",sum);

	
}
