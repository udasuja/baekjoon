/*
입력한 문자값에 13을 더한 ascii값이 z를 넘어가면 그것을 조정하여 출력한다.
*/

#include <stdio.h>

void upper(unsigned char c);//대문자
void lower(unsigned char c);//소문자

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
	unsigned char rot13 = c + 13;	//rot13를 char형으로 하면 'u'+13의 값은 130으로 signed char의 범위를 넘기에 unsigned char형으로 함
	if(rot13 > 'z')
		rot13 = 'a' + (rot13 - 'z')-1;
	printf("%c", rot13);
	return;
}