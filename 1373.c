/*
어떤 수를 2진수를 입력했을 때 8진수로 출력하는 프로그램
예를 들어:100이 있을때 오른쪽부터 2^0*0+2^1*0+2^2*1의 값은 100를 10진수로 표현했을 때의 수이고
서식문자 %o로 이 수를 8진수로 출력할 수 있다.
2진수로 표현된 수를 오른쪽부터 3글자씩 끊어 위에 처럼 계산해준다.=>그리고 그 수들을 선입후출 방식으로 출력한다. 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void binary_octal(char* arr);

int main(void)
{
	char arr[1000001];
	
	scanf_s("%s", arr, sizeof(arr));
	binary_octal(arr);

	return 0;
}
void binary_octal(char* arr)
{
	int i;
	double j = 0;
	int sum = 0;
	int len = strlen(arr);
	for (i = len - 1; i >= len - 3 && i >= 0; i--)
	{
		int num = arr[i] - '0';
		sum += (int)(pow(2, j) * num);
		arr[i] = '\0';
		j++;
	}
	if (i < 0)
	{
		printf("%d", sum);
		return;
	}
	else
		binary_octal(arr);
	printf("%d", sum);
	return;
}