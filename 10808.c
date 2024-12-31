/*
���ĺ� ������ ���� count[26]�迭�� �ϳ� �����.
�ܾ getchar�� �ϳ��� �ԷµǸ鼭 ���ĺ��� ������ ����.
for������ �� ���ĺ��� ���� Ƚ���� ����Ѵ�.
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