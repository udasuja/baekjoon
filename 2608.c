/*
I	V	X	L	C	D	M
1	5	10	50	100	500	1000
V, L, D는 한 번만 사용할 수 있고 I, X, C, M은 '연속'해서 세 번까지만 사용할 수 있다.
=>연속 세 번은 이전 것과 현재 것을 비교하여 변수에 숫자를 세는데 그 숫자가 3이상이면 프로그램을 종료한다.
만약 이전 것과 현재 것을 비교하여 다른 문자가 나오면 변수를 0으로 초기화 한다.
작은 숫자가 큰 숫자의 왼쪽에 오는 경우는 다음과 같다.
IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900 을 나타낸다. 이들 각각은 한 번씩만 사용할 수 있다.

입력:로마 숫자로 이루어진 두 수를 입력받아 그 둘을 더한 값을 아라비아 숫자와 로마 숫자로 출력하는 프로그램을 작성하시오.
	왼쪽부터 큰 수에 해당하는 문자를 차례대로 입력한다.
출력:그에 해당하는 아라비아 숫자와 로마 숫자를 출력한다.

switch문을 이용하여 i v x l c d m에 따른 case로 이동하고 i x c 로 이동할 때 그 뒤에 각각 v x ,l c, d m이 붙는지를 확인한다.
그리고 로마 숫자를 계산하여 합계를 계산한다.
아라비아 숫자 출력후 그 숫자를 로마 숫자로 출력한다.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char compar[7][5] =
	{
		{"IIII"},
		{"XXXX"},
		{"CCCC"},
		{"MMMM"},
		{"L"},
		{"V"},
		{"D"}

	};//문자열은 널문자를 포함하기에 열의 개수는 5가 된다.
	char arr[50];
	int i;

	for (i = 0; i < 2; i++)
	{
		int len,j;
		fgets(arr, sizeof(arr), stdin);
		len=strlen(arr);
		for (j = 0; j < 7; j++)
		//입력한 문자열 중 4개 이상 입력받았는지 2개 이상 입력받았는지를 찾는다.
		{
			int check = 0;
			char* ptr = strstr(arr, compar[j]);
			while (ptr != NULL)
			{
				ptr = strstr(ptr + 1, compar[j]);				
				check++;
			}
			if (j < 4 && check>0)
			{
				return 0;
			}
			else if (j >= 4 && check > 1)
			{
				return 0;
			}			
		}
	}
}