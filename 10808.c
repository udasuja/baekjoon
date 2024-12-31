/*
알파벳 갯수를 세는 count[26]배열을 하나 만든다.
단어가 getchar로 하나씩 입력되면서 알파벳의 개수를 센다.
for문으로 각 알파벳이 나온 횟수를 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 26

int main(void)
{
	int* count = (int*)calloc(SIZE, sizeof(int));
	int i;
	char c;

	while ((c = getchar()) != '\n')
	{
		count[c - 'a'] += 1;
	}
	for (i = 0;i < SIZE;i++)
	{
		printf("%d ", count[i]);
	}
	free(count);
	return 0;
}