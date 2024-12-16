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
	int tag = 0;


	//enter key 입력 전까지 반복
	while ((c = getchar()) != '\n')
	{
		if (c == '<')
		{
			pop();
			printf("%c", c);
			tag = 1;	//<문자가 입력됨을 표시
		}
		else if (c == '>')	//이 조건문이 tag==1조건보다 앞에 나와야지만 
							//tag==1일 때 tag를 0값을 갖도록 바꿀 수 있다.
		{
			printf("%c", c);
			tag = 0;
		}
		else if (tag == 1)
		{
			printf("%c", c);
		}
		else if (c == ' ')
		{
			pop();
			printf("%c", c);
		}
		else
		{
			string_s[++top] = c;
		}
	}
	pop();
	return 0;
}