/*
 * 문자열 s가 있을 때, f(s)는 s를 무한번 붙인 문자열로 정의한다.
 * 예를 들어, s = "abc" 인 경우에 f(s) = "abcabcabcabc..."가 된다.
 * 다른 문자열 s와 t가 있을 때, f(s)와 f(t)가 같은 문자열인 경우가 있다.
 * 예를 들어서, s = "abc", t = "abcabc"인 경우에 f(s)와 f(t)는 같은 문자열을 만든다.
 * s와 t가 주어졌을 때, f(s)와 f(t)가 같은 문자열을 만드는지 아닌지 구하는 프로그램을 작성하시오.
 *
 * 입력
 * 첫째 줄에 s, 둘째 줄에 t가 주어진다.
 * 두 문자열 s와 t의 길이는 50보다 작거나 같은 자연수이고,
 * 알파벳 소문자로만 이루어져 있다.
 *
 * 출력
 * 첫째 줄에 f(s)와 f(t)가 같으면 1을, 다르면 0을 출력한다.
 *
 * algorithm:
 * s와 t문자열의 길이를 개산 후 길이가 적은 문자열을 길이가 큰 문자열 만큼 늘린다.
 * 그리고 두 문자열을 비교한다.
 */
#include <stdio.h>
#include <string.h>
#define SIZE 52

int main(void)
{
	char s[SIZE], t[SIZE], * com;
	unsigned int len_s, len_t;
	int i;

	scanf("%s %s", s, t);
	len_s = strlen(s);
	len_t = strlen(t);
	if (len_s < len_t)
	{
		com = s;
		while (len_s < len_t)
		{
			strcat(s, com);//배열 이름은 가르키는 주소값을 바꾸지 못한다.
			//하지만 포인터 변수는 그것이 가능하다.
			//즉 strcat가 반환하는 문자열의 주소값은 포인터 변수만 저장 가능하다.
			len_s = strlen(s);
		}
	}
	else
	{
		com = t;
		while (len_t < len_s)
		{
			strcat(t, com);
			len_t = strlen(t);
		}
	}
	i = strcmp(s, t);
	if (i == 0)
		printf("1");
	else
		printf("0");
	return 0;
}