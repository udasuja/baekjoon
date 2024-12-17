/*
레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 ‘( ) ’ 으로 표현된다. 또한, 모든 ‘( ) ’는 반드시 레이저를 표현한다.
쇠막대기의 왼쪽 끝은 여는 괄호 ‘ ( ’ 로, 오른쪽 끝은 닫힌 괄호 ‘) ’ 로 표현된다.
----------
<막대의 시작>
스택을 이용하여 문자를 순서대로 저장한다.
(가 입력되면 스택에 무조건 집어넣는다. 그리고 o_count값을 1 증가시켜 스택내에 (가 얼마나 입력되었는지를 나타낸다.

<레이저>
)가 입력되면 현재 stack에 저장된 값이 (이라면 o_count값을 1감소시키고 sum에 o_count값만큼 더한다. 
그리고 스택에 )를 넣는다. 

<막대의 끝>
)가 입력되었는데 현재 stack에 저장된 값이 )이면 o_count값을 1감소시키고 sum에 1를 더한다.
이를 반복한다.
*/
#include <stdio.h>

int main(void)
{
	char stack;
	int sum = 0, o_count = 0;
	char c;

	while ((c = getchar()) != '\n')
	{
		if (c == '(')
		{
			stack = c;
			o_count++;
			
		}
		else if (c == ')'&&stack=='(')	//레이저
		{
			o_count--;
			sum += o_count;
			stack = c;
		}
		else if (c == ')' && stack == ')')	//막대의 끝
		{
			o_count--;
			sum += 1;
		}
	}
	printf("%d", sum);
	return 0;
}