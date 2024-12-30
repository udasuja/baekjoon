/*
풀이
값을 저장하는 모든 변수는 double로 설정(문자는 제외)
출력은 %.2lf로 소숫점 둘째 자리까지 출력한다.

후위표기식에 대한 문자열을 배열에 저장한다. -> A배열
그 후 각 피연산자에 대한 값을 또 다른 배열에 저장한다. -> B배열

A배열에 있는 피연산자를 차례대로 stack에 push한다.
이때 A배열에 있는 피연산자는 문자이므로
B[문자-'A']로 문자인 피연산자에 대한 값을 넣음

그리고 연산자가 나오면 stack에 있는 피연산자를 2개 pop한다.
그 피연산자를 차례대로 각각 변수 a,b에 넣는다.

switch문으로 각 연산자에 대한 연산을 한다(b '연산자' a). 
그리고 이 값을 stack에 push한다.
이 과정을 A배열의 널문자에 다다를 때까지 반복한다.

널문자에 도달하면 stack에는 최종 결과값만 들어있을 것이다.
이 값을 pop하여 결과값을 출력한다.
*/
#include <stdio.h>
#define SIZE 100

double stack[SIZE];	//stack에는 항상 피연산자 값이 들어있다. 피연산자는 항상 연산자 앞에 온다. 
int top = -1;

int main(void)
{
	char arr[SIZE];
	double count[26];	//사용자가 입력한 피연산자의 값
	int n,i;

	scanf_s("%d", &n);
	scanf_s("%s", &arr, SIZE);

	for (i = 0;i < n;i++)
	{
		scanf_s("%lf", &count[i]);
	}

	for (i = 0;arr[i]!='\0';i++)
	{
		if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')	//연산자인 경우
		{
			double b = stack[top--];//나중에 삽입된 값
			double a = stack[top--];//먼저 삽입된 값
			switch (arr[i])
			{
			case'+':
				stack[++top] = a + b;
				break;
			case'-':
				stack[++top] = a - b;
				break;
			case'*':
				stack[++top] = a * b;
				break;
			case'/':
				stack[++top] = a / b;
				break;
			default:
				break;
			}
		}
		else
		{
			stack[++top] = count[arr[i] - 'A'];
		}
	}
	printf("%.2lf", stack[top--]);

	return 0;
}
