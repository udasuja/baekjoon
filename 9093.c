/*
전체 문자열을 fgets함수를 통해 입력받고
공백문자 탐색후 그 공백문자가 있는 위치를 저장하고 문자를 뒤집는다. 
이를 '\n'가 나올 때까지 반복한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 1001

void reverse(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;//start가 가리키는 주소에 저장된 문자를 temp에 저장
		*start = *end;//end가 가리키는 주소에 저장된 문자를 start가 가리키는 주소에 저장된 문자와 교환
		*end = temp;
		start++;//start가 가리키는 주소를 한 칸 앞으로 이동
		end--;//end가 가리키는 주소를 한 칸 뒤로 이동
	}
}


int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();//개행 문자 제거

	while (n--)
	{
		char arr[SIZE];
		int i,len;
		char* start;

		fgets(arr, SIZE, stdin);
		start = arr;
		len = strlen(arr);
		for (i = 0; i < len; i++)
		{
			if (arr[i] == '\n' || arr[i] == ' ')
			{
				reverse(start, &arr[i - 1]);//arr[i-1]은 공백문자 이전의 주소값을 전달한다.
				start = &arr[i + 1];//공백문자 다음으로 start를 설정
			}
		}
		arr[len] = '\0';//fgets함수는 널문자를 포함시키지 않기에 맨 뒤에 널문자 삽입
		printf("%s", arr);
	}
}
