/*
dir a?b.exe라 입력하면 첫글자가 a이고 세번째 글자가 b이며 확장자가 exe인 것이 모두 출력이되고 ?인 두번째 글자는 아무거나 가능
출력되는 파일 길이는 세 개이다.

입력: 파일 이름의 개수 n
	  n개의 줄에는 파일 이름(최대50)이 주어짐
		 
출력: 패턴을 출력한다.

ex) 입력:3
		config.sys
		config.inf
		configures
	
	출력:3개의 파일이름중 config만 공통되기에
		 config????가 출력된다.

풀이: arr1를 문자열로써 입력하고 문자를 하나씩 입력받아 arr1문자열의 문자와 비교한다.
그리고 문자가 다르면 arr2에 그 문자 번호에 해당하는 인덱스에 ?를 삽입한다.
*/

#include <stdio.h>
#include <string.h>
#define MIN(a,b) a>b?b:a

typedef struct
{
	char arr1[51];
	char arr2[51];
}FI;

int main(void)
{
	int n,i,c,k,len;
	FI file;

	scanf_s("%d", &n);
	scanf_s("%s", file.arr1,51);
	c = getchar();
	len = strlen(file.arr1);
	for (i = 1; i < n; i++)
	{
		for (k = 0; k <= len; k++)
		{
			c = getchar();
			if ((file.arr1[k] != c) && c != '\n')
			{
				file.arr2[k] = '?';
			}
			else if (c == '\n')
				break;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (file.arr2[i] != '?')
		{
			printf("%c", file.arr1[i]);
		}
		else
			printf("%c", file.arr2[i]);
	}
}