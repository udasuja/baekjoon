/*
������ ���� �� ���ڸ� ���ÿ� ���ʴ�� �����Ѵ�. 
���� ���� ���ڰ� �ԷµǸ� ���� stack�� ����� ��� ���ڸ� ���ʴ�� pop�Ѵ�.
���� <���ڰ� �ԷµǸ� ���� stack�� ����� ��� ���ڸ� ���ʴ�� pop�Ѵ�.
�׸��� >���ڰ� �Էµ� ������ �Էµ� ��� ���ڸ� �״�� ����Ѵ�.

������ top�� 1������Ų �� push�ϰ�
pop�� ���� ���� stack���� ���ڸ� ������ top���� 1���ҽ�Ų��.
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


	//enter key �Է� ������ �ݺ�
	while ((c = getchar()) != '\n')
	{
		if (c == '<')
		{
			pop();
			printf("%c", c);
			tag = 1;	//<���ڰ� �Էµ��� ǥ��
		}
		else if (c == '>')	//�� ���ǹ��� tag==1���Ǻ��� �տ� ���;����� 
							//tag==1�� �� tag�� 0���� ������ �ٲ� �� �ִ�.
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