/*
https://www.acmicpc.net/board/view/30006 참고했음
우선 그냥 2진수 변환하듯이 -2로 나눠주시면 됩니다

다만 -13을 기준으로 숫자가  7 -> -3  -> 2  -> -1 -> 1  이런식으로 바뀝니다.

나머지는 항상 1 아니면 0이 되어야합니다.

-2로 나누면 나머지는 -1 0 1중 하나가 된다.
만약 나머지가 -1이 나오면 몫을 1증가시키면 나머지는 1이 나오게 된다.
왜냐, 나머지=나눠지는 수-(-2*몫) 으로 구해지는데, 이때 몫에 1를 증가시킨다는 것은 다음과 같이 된다.
나눠지는 수-(-2*(몫+1))=나눠지는 수-(-2*몫)-(-2)=나머지+2 가 된다. 나머지는 -1이므로 몫에 1를 더한 뒤의 나머지는 1이다.
*/

#include <stdio.h>

#define DIV -2

void recu(int);


int main(void)
{
	long long n;

	scanf_s("%lld", &n);
	if (n == 0)	//n이 0일 경우 recu는 시작하자마자 끝나기에 
		printf("%d", 0);
	else
		recu(n);	//n값이 0이 될 때까지 -2로 나눈다.

	return 0;
}

void recu(int n)
{
	if (n == 0)	//degeration case --나눠지는 수가 0일 때 재귀 호출 종료
	{
		return;
	}
	
	int oper = n;
	n /= DIV;
	if (oper % DIV == -1)	//나머지가 -1이면 몫에 1더하여 나머지를 1로 만든다.
	{
		n += 1;
		recu(n);
		printf("%d", 1);
	}
	else
	{
		recu(n);
		printf("%d", oper % DIV);
	}
	return;
}