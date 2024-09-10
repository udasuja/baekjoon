#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 52

int check(char* paren)
{
	int i,top = -1;
	for (i = 0; paren[i] != '\n'; i++)
	{
		if (paren[i] == '(')
		{
			top += 1;
		}
		else if(paren[i]==')')//i번째 문자가 )인경우 top이 0이상이면 (이 한 번은 나왔다는 것이다.
		{
			if (top == -1)//문자 )를 입력받았지만 앞에 (문자가 없는 경우
				return 0;
			top--;
		}
	}
	return top == -1;//top이 -1이라면 (와 )가 같은 개수라는 뜻이다.
}

int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();

	while (n--)
	{
		char paren[SIZE];
		fgets(paren, SIZE, stdin);

		if (check(paren))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
