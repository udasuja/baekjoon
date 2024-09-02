/*
 * 문자열의 길이가 n이라면 0부터 n-2번째까지 탐색하면서 가장 작은 아스키 값을 갖는 문자의 인덱스 번호를 저장한다.
 * 그리고 저장된 인덱스 번호가 k라 하면 k부터 n-1까지 탐색하면서 가장 작은 아스키 값을 갖는 문자의 인덱스 번호를 저장한다.
 * 그 저장된 인덱스 번호를 j라 한다.
 * k부터 0까지 출력, j부터 k까지 출력, n-1부터 j까지 출력
 * 만약 탐색을 하다가 0또는 k와 같은 문자가 나오면 저장을 하지않고 넘어간다.
 * 하지만 범위내에서 가장 작은 아스키 값 중 중복되는 것이 있으면 더 먼 것을 저장한다. 
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[51];
	int first=0,second;//만약 arr[0]보다 작은 아스키 값이 없으면 first에는 0을 저장한다.
	int i,len;

	scanf("%s",arr);
	len=strlen(arr);


	for(i=1;i<len-2;i++)
	{
		if(arr[first]>=arr[i]&&arr[i]!=arr[0])//0부터 len-2까지 문자중 가장 작은 아스키값을 찾는 것이다.
		{
			first=i;
		}
	}
	second=first+1;//만약 arr[first+1]보다 작은 아스키 값이 없으면 second에는 first+1을 저장한다.
	for(i=first+2;i<len-1;i++)//k다음의 문자부터 비교분석한다.
	{
		if(arr[second]>=arr[i])
		{
			second=i;
		}
	}
	for(i=first;i>=0;i--)
	{
		printf("%c",arr[i]);
	}
	for(i=second;i>first;i--)
	{
		printf("%c",arr[i]);
	}
	for(i=len-1;i>second;i--)
	{
		printf("%c",arr[i]);
	}

}
