#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long n,i,result;
	int *arr;
	scanf("%d",&n);
	result=n;
	arr=(int*)calloc(n+1,sizeof(int));
	for(i=2;i<=n;i++)
	{
		unsigned long num=n;
		while(num>0)
		{
			if(num%i==0)
			{
				num/=i;
				if((arr[num]==0))
				{
					arr[num]=1;
					result--;
				}
			}
			num/=i;	
		}
		printf("%ld\n",i);
	}
	printf("%ld",result);
	free(arr);

}
