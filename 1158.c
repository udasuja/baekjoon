#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,k,count,index;
	int* data;
	int i;

	scanf("%d %d", &n,&k);
	data = (int*)malloc(sizeof(int) * n);
	count = n;
	for (i = 0; i < n; i++)
	{
		data[i] = i + 1;
	}
	index = 0;
	printf("<");
	while (count)
	{
		//count�� �ݺ����� ����Ǹ鼭 1�� �����Ѵ�.
		//�׷��� count�� ������ ������ �����ϹǷ� �ݺ����� ����Ǹ鼭 ť�� 1�� �پ���� ǥ���Ѵ�.
		index = (index + k - 1) % count;
		printf("%d", data[index]);
		for (i = index; i < count - 1; i++)//count�� 1�� �����ϹǷ� �ݺ����� ����Ǹ鼭 ť�� ũ���� 1�� �پ���.(i<count-1, -1�� ���� ������ ������ ����.)
		{
			data[i] = data[i + 1];//data[i]=data[i+1]�̹Ƿ� i�� ������ index-1���� �����ؾ� �Ѵ�.
		}

		if (count > 1)
			printf(", ");
		count--;
	}
	printf(">");

	free(data);
	return 0;
}