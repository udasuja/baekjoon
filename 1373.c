/*
어떤 수를 2진수를 입력했을 때 8진수로 출력하는 프로그램
예를 들어:100이 있을때 오른쪽부터 2^0*0+2^1*0+2^2*1의 값은 100를 10진수로 표현했을 때의 수이고
서식문자 %o로 이 수를 8진수로 출력할 수 있다.
2진수로 표현된 수를 오른쪽부터 3글자씩 끊어 위에 처럼 계산해주고 그 값을 하드코딩 방식으로 출력한다.=>그리고 그 수들을 선입후출 방식으로 출력한다. 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>


void binary_octal(char* arr,int len);

int main(void)
{
	char arr[1000001];
	int len;
	scanf_s("%s", arr, sizeof(arr));
	len = strlen(arr);
	binary_octal(arr,len);

	return 0;
}
void binary_octal(char* arr,int len)
{
	int i,j=2;
	char arr_c[4]={'0','0','0'};
	//11001100같은 수를 입력할 때11/001/100으로 쪼갤 수 있다. 이때 11을 계산할 때 arr_c[0]의 값이 0이라는 정수가 저장되었다면
	//아니면 임의의 정수가 저장되었다면 atoi함수(문자열=>정수)을 사용할 수가 없다. 그렇기에 2번째 요소까지 '0'으로 초기화 해준다.
	if (len <= 0)
	{
		return;
	}
	else
	{
		for (i = len-1; i >= 0 && j >=0; i--,j--)//arr_c함수에 뒤에서부터 문자를 채우고 0번째 요소 이후(예를 들면:-1번째)에 저장할 수 없도록 함
		{
			arr_c[j] = arr[i];
		}
		binary_octal(arr, len - 3);//선입후출이기에 재귀함수를 사용하여싿.
		switch (atoi(arr_c))
		{
		case 0:
			printf("0");
			break;
		case 1://001도 여기에서 걸린다.
			printf("1");
			break;
		case 10://010도 여기에서 걸린다.
			printf("2");
			break;
		case 11:
			printf("3");
			break;
		case 100:
			printf("4");
			break;
		case 101:
			printf("5");
			break;
		case 110:
			printf("6");
			break;
		case 111:
			printf("7");
		}
	}
	return;
}