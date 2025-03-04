/*
�Է��� ���ڰ��� 13�� ���� ascii���� z�� �Ѿ�� �װ��� �����Ͽ� ����Ѵ�.
*/

#include <stdio.h>

void upper(unsigned char c);//�빮��
void lower(unsigned char c);//�ҹ���

int main(void)
{
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c >= 'a' && c <= 'z')
			lower(c);
		else if (c >= 'A' && c <= 'Z')
			upper(c);
		else
			printf("%c", c);
	}
	return 0;
}

void upper(unsigned char c)
{
	unsigned char rot13 = c + 13;
	if(rot13 > 'Z')
		rot13 = 'A'+(rot13 - 'Z')-1;
	printf("%c", rot13);
	return;
}

void lower(unsigned char c)
{
	unsigned char rot13 = c + 13;	//rot13�� char������ �ϸ� 'u'+13�� ���� 130���� signed char�� ������ �ѱ⿡ unsigned char������ ��
	if(rot13 > 'z')
		rot13 = 'a' + (rot13 - 'z')-1;
	printf("%c", rot13);
	return;
}