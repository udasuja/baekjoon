/*
��ü ���ڿ��� fgets�Լ��� ���� �Է¹ް�
���鹮�� Ž���� �� ���鹮�ڰ� �ִ� ��ġ�� �����ϰ� ���ڸ� �����´�. 
�̸� '\n'�� ���� ������ �ݺ��Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 1001

void reverse(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;//start�� ����Ű�� �ּҿ� ����� ���ڸ� temp�� ����
		*start = *end;//end�� ����Ű�� �ּҿ� ����� ���ڸ� start�� ����Ű�� �ּҿ� ����� ���ڿ� ��ȯ
		*end = temp;
		start++;//start�� ����Ű�� �ּҸ� �� ĭ ������ �̵�
		end--;//end�� ����Ű�� �ּҸ� �� ĭ �ڷ� �̵�
	}
}


int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();//���� ���� ����

	while (n--)
	{
		char arr[SIZE];
		int i,len;
		char* start;

		fgets(arr, SIZE, stdin);
		start = arr;
		len = strlen(arr);
		for (i = 0; i < len; i++)
		{
			if (arr[i] == '\n' || arr[i] == ' ')
			{
				reverse(start, &arr[i - 1]);//arr[i-1]�� ���鹮�� ������ �ּҰ��� �����Ѵ�.
				start = &arr[i + 1];//���鹮�� �������� start�� ����
			}
		}
		arr[len] = '\0';//fgets�Լ��� �ι��ڸ� ���Խ�Ű�� �ʱ⿡ �� �ڿ� �ι��� ����
		printf("%s", arr);
	}
}
