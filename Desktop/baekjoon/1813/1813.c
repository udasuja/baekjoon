#include <stdio.h>
#define MAX(a,b) a>b?a:b

int main(void)
{
	int n;
	int i=0,max=-1;
	int arr[51]={0};
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		arr[k]+=1;
	}
	for(i=0;i<52;i++)
	{
		if(arr[i]==i)
			max=MAX(max,i);
	}
	printf("%d",max);
	return 0;
}
