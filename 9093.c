/*
getchar으로 단어를 하나씩 입력받고 그 단어들을 arr[21]에 순서대로 집어넣는다.
그러다 스페이스바가 입력되면 reverse함수로 이동한다.
	reverse(char *arr)
	int len=strlen(arr)
	for(i=0;i<len/2;i++)
		char temp=arr[i]
		arr[i]=arr[len-i-1]
		arr[len-i-1]=temp
reverse함수 이후 맨 위부터 반복한다.

그러다가 '\n'가 입력되면 reverse함수를 실행하고 그 문장입력을 끊낸다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define SIZE 21

void reverse(char* arr_r)
{
	int len = strlen(arr_r)-1;
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = arr_r[i];
		arr_r[i] = arr_r[len - i - 1];
		arr_r[len - i - 1] = temp;
	}
	printf("%s", arr_r);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();//위 scanf로 인한 널문자 제거

	while (n--)
	{
		char arr[SIZE]={0};
		char c;
		int i;
		for (i=0;i<=SIZE;i++)
		{
			c = getchar();
			arr[i] = c;
			if (c == ' '||c=='\n')
			{
				arr[i+1] = '\0';
				reverse(arr);
				i = c=='\n'?SIZE+1:-1;//c가 널문자를 입력받으면 SIZE+1를 i에 저장해 반복을 종료하고 아니면 -1를 저장해 반복을 초기화한다.
			}
		}
	}
	
}