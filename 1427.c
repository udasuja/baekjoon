#include <stdio.h>
#include <stdlib.h>

int compare(const void*a,const void *b)
{
	if((*(int*)a)>(*(int*)b))
		return -1;
	else if((*(int*)a)<(*(int*)b))
		return 1;
	else
		return 0;
}

int main(void)
{
	char c;
	int arr[11];
	int n,i;
	for(n=0;(c=getchar())!='\n';n++)
		arr[n]=c-'0';
	qsort(arr,n,sizeof(int),compare);
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
}


