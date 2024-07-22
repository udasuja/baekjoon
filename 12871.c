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
 */
#include <stdio.h>
#include <string.h>
#define SIZE 51

int string_len(char*s,char*t,int len_s,int len_t)
{
	int k=0,i;
	if(len_s<len_t)//s의 길이가 t보다 작을때 
	{
		while(k<=len_t)
		{
			for(i=0;i<len_s&&k<=len_t;i++)
			{
				if(s[i]!=t[k])//t는 i+len_s번째 요소와 s의 i번째 요소를 검사한다.
					      //(i는 0부터 len_s까지) 				
					return 0;		
				k++;
			}
		}
	}
	else
	{
		while(k<=len_s)
		{
			for(i=0;i<len_t&&k<=len_s;i++)
			{
				if(t[i]!=s[k])					
					return 0;		
				k++;
			}
		}

	}
	return 1;
}

int main(void)
{
	char s[SIZE],t[SIZE];
	int len_s,len_t;


	scanf("%s %s",s,t);
	len_s=strlen(s);//널문자를 포함하지 않는 s의 길이
	len_t=strlen(t);
	printf("%d",string_len(s,t,len_s,len_t));
}

					
				
					

