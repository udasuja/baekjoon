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
		//count가 반복문이 진행되면서 1씩 감소한다.
		//그러한 count로 나머지 연산을 진행하므로 반복문이 진행되면서 큐가 1씩 줄어듦을 표현한다.
		index = (index + k - 1) % count;
		printf("%d", data[index]);
		for (i = index; i < count - 1; i++)//count가 1씩 감소하므로 반복문이 진행되면서 큐의 크가가 1씩 줄어든다.(i<count-1, -1를 붙인 이유는 다음과 같다.)
		{
			data[i] = data[i + 1];//data[i]=data[i+1]이므로 i는 마지막 index-1까지 저장해야 한다.
		}

		if (count > 1)
			printf(", ");
		count--;
	}
	printf(">");

	free(data);
	return 0;
}