/*
getchar���� �ܾ �ϳ��� �Է¹ް� �� �ܾ���� arr[21]�� ������� ����ִ´�.
�׷��� �����̽��ٰ� �ԷµǸ� reverse�Լ��� �̵��Ѵ�.
	reverse(char *arr)
	int len=strlen(arr)
	for(i=0;i<len/2;i++)
		char temp=arr[i]
		arr[i]=arr[len-i-1]
		arr[len-i-1]=temp
reverse�Լ� ���� �� ������ �ݺ��Ѵ�.

�׷��ٰ� '\n'�� �ԷµǸ� reverse�Լ��� �����ϰ� �� �����Է��� ������.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define SIZE 21

void reverse(char* arr_r)
{
	int len = strlen(arr_r)-1;
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = arr_r[i];
		arr_r[i] = arr_r[len - i - 1];
		arr_r[len - i - 1] = temp;
	}
	printf("%s", arr_r);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();//�� scanf�� ���� �ι��� ����

	while (n--)
	{
		char arr[SIZE]={0};
		char c;
		int i;
		for (i=0;i<=SIZE;i++)
		{
			c = getchar();
			arr[i] = c;
			if (c == ' '||c=='\n')
			{
				arr[i+1] = '\0';
				reverse(arr);
				i = c=='\n'?SIZE+1:-1;//c�� �ι��ڸ� �Է¹����� SIZE+1�� i�� ������ �ݺ��� �����ϰ� �ƴϸ� -1�� ������ �ݺ��� �ʱ�ȭ�Ѵ�.
			}
		}
	}
	
}