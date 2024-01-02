/*
풀이:
	getchar()함수로 문자 하나씩 입력받고 0의 아스키코드값 만큼 뺀 값을 합해준다.
*/

#include <stdio.h>

int main(void)
{
	int sum = 0;
	int t, c,i;

	scanf_s("%d", &t);
	c = getchar();//scanf로 인해 입력버퍼에 생긴 엔터키 값을 제거하기 위한 코드
	for (i = 0; i < t; i++)
	{
		c = getchar();
		sum += c - '0';
	}
	printf("%d", sum);
}
