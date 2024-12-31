/*
count �迭�� �̿��Ͽ� �� ���ĺ��� ó�� ���� ������ ����(0���� �ʱ�ȭ).
�̶� ���� n�� 1�� �ʱ�ȭ�Ͽ�
�ܾ� �Է� �ݺ����� ���� �����ϸ� count�迭�� ���Ұ��� 0�̸� n���� ���Ұ����� ����
���� 0���� ũ�� ���д�.

����� count�迭�� ���Ұ�-1�� �Ͽ� ����Ѵ�.
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