/*
dir a?b.exe�� �Է��ϸ� ù���ڰ� a�̰� ����° ���ڰ� b�̸� Ȯ���ڰ� exe�� ���� ��� ����̵ǰ� ?�� �ι�° ���ڴ� �ƹ��ų� ����
��µǴ� ���� ���̴� �� ���̴�.

�Է�: ���� �̸��� ���� n
	  n���� �ٿ��� ���� �̸�(�ִ�50)�� �־���
		 
���: ������ ����Ѵ�.

ex) �Է�:3
		config.sys
		config.inf
		configures
	
	���:3���� �����̸��� config�� ����Ǳ⿡
		 config????�� ��µȴ�.

Ǯ��: arr1�� ���ڿ��ν� �Է��ϰ� ���ڸ� �ϳ��� �Է¹޾� arr1���ڿ��� ���ڿ� ���Ѵ�.
�׸��� ���ڰ� �ٸ��� arr2�� �� ���� ��ȣ�� �ش��ϴ� �ε����� ?�� �����Ѵ�.
*/

#include <stdio.h>
#include <string.h>
#define MIN(a,b) a>b?b:a

typedef struct
{
	char arr1[51];
	char arr2[51];
}FI;

int main(void)
{
	int n,i,c,k,len;
	FI file;

	scanf_s("%d", &n);
	scanf_s("%s", file.arr1,51);
	c = getchar();
	len = strlen(file.arr1);
	for (i = 1; i < n; i++)
	{
		for (k = 0; k <= len; k++)
		{
			c = getchar();
			if ((file.arr1[k] != c) && c != '\n')
			{
				file.arr2[k] = '?';
			}
			else if (c == '\n')
				break;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (file.arr2[i] != '?')
		{
			printf("%c", file.arr1[i]);
		}
		else
			printf("%c", file.arr2[i]);
	}
}