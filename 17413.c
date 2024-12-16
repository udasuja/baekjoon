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

	//enter key �Է� ������ �ݺ�
	while ((c = getchar()) != '\n')
	{
		if (c == ' ')
		{
			pop();			//���� ���� ��� ���� ���
			printf("%c", c); //���� ���
			continue;	//���� ���ڸ� stack�� ���� �ʱ� ���� continue
		}
		else if (c == '<')
		{
			pop();
			printf("%c", c);	//<���
			while ((c = getchar()) != '>')
			{
				printf("%c", c);
			}
			printf("%c", c);	//>���
			continue;	//>���ڸ� stack�� ���� �ʱ� ���� continue
		}
		string_s[++top] = c;
	}
	pop();
	return 0;
}