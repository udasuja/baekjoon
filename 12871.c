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
 * 예제 입력:
 * aba
 * abaabaabaabaabaabaab
 * 
 * 예제 출력:
 * 0
 * 
 * algorithm:
 * s와 t의 문자열의 길이를 같도록 조정(최소 공배수를 이용)하고 조정한 문자열이 같은지 비교
 * 이때 문자 하나하나 비교하고 최소 공배수 이전에 널문자가 나오면 다시 0번째 요소로 회귀한다. 
 */
#include <stdio.h>
#include <string.h>
#define SIZE 52

int main(void)
{
	char s[SIZE],t[SIZE];
	int len_s,len_t;
	int pro,i,s_l,t_l;
	int check=1;

	scanf("%s %s",s,t);
	len_s=strlen(s);
	len_t=strlen(t);
	pro=(len_s==len_t?len_s:len_s*len_t);//두 문자열의 길이가 같지 않으면 두 문자열의 길이를 곱한 것을 반환
	for(i=0,s_l=0,t_l=0;i<pro;i++,s_l++,t_l++)//pro번 반복한다.
	{
		if(s_l==len_s)//s_l가 s의 널문자를 가리키면 다시 초기화한다.
			s_l=0;
		if(t_l==len_t)//t_l가 t의 널문자를 가리키면 0으로 초기화한다.
			t_l=0;
		if(s[s_l]!=t[t_l])//s와 t가 서로 다르면
		{
			check=0;
			break;
		}
	}
	printf("%d",check);

	return 0;
}
				
					

