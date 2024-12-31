/*
count 배열을 이용하여 각 알파벳의 처음 나온 순서를 센다(0으로 초기화).
이때 변수 n를 1로 초기화하여
단어 입력 반복문에 따라 증가하며 count배열의 원소값이 0이면 n값을 원소값으로 설정
만약 0보다 크면 냅둔다.

출력은 count배열의 원소값-1을 하여 출력한다.
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 26


int main(void)
{
	int* count = (int*)calloc(SIZE, sizeof(int));
	int n = 1;
	int i;
	char c;

	while ((c = getchar()) != '\n')
	{
		if (count[c - 'a'] == 0)
		{
			count[c - 'a'] = n;
		}
		n++;
	}
	for (i = 0; i < SIZE;i++)
	{
		printf("%d ", count[i] - 1);
	}
	free(count);
	return 0;
}