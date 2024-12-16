/*
스택을 만든 뒤 문자를 스택에 차례대로 저장한다. 
만약 공백 문자가 입력되면 현재 stack에 저장된 모든 문자를 차례대로 pop한다.
만약 <문자가 입력되면 현재 stack에 저장된 모든 문자를 차례대로 pop한다.
그리고 >문자가 입력될 때까지 입력된 모든 문자를 그대로 출력한다.

스택은 top을 1증가시킨 후 push하고
pop할 때는 먼저 stack내의 문자를 꺼내고 top값을 1감소시킨다.
*/
#include <stdio.h>

char string_s[100000];
int top=-1;

void pop(void)
{
	while (top>=0)
	{
		printf("%c", string_s[top--]);
	}
	top = -1;
	return;
}

int main(void)
{
	char c;

	//enter key 입력 전까지 반복
	while ((c = getchar()) != '\n')
	{
		if (c == ' ')
		{
			pop();			//스택 내의 모든 원소 출력
			printf("%c", c); //공백 출력
			continue;	//공백 문자를 stack에 넣지 않기 위해 continue
		}
		else if (c == '<')
		{
			pop();
			printf("%c", c);	//<출력
			while ((c = getchar()) != '>')
			{
				printf("%c", c);
			}
			printf("%c", c);	//>출력
			continue;	//>문자를 stack에 넣지 않기 위해 continue
		}
		string_s[++top] = c;
	}
	pop();
	return 0;
}