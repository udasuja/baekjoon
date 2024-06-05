/*
첫째줄에 5개의 수를 입력하고 출력으로는 입력된 수 중 3개 이상으로 나누어 떨어지는 가장 작은 수
brute force algorithm이므로 그냥 무식한 방식으로 문제를 해결하겠다.
풀이:5개의 수 중 중간값을 찾고 그 중간 값부터 1씩 증가시켜 3개 이상으로 나누어 떨어지는 가장 작은 수를 구한다.
*/

#include <stdio.h>
#define MAX(a,b) a>b?a:b

int middle_number(int arr[]);

int main(void)
{
	int arr[5],i;
	int middle;

	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	middle = middle_number(arr);
	while (1)
	{
		int count = 0;
		for (i = 0; i < 5; i++)
		{
			if (middle % arr[i] == 0)
				count++;
		}
		if (count > 2)
			break;
		else
			middle++;
	}
	printf("%d", middle);
	return 0;
}

int middle_number(int arr[])
{
	int replica[5]={arr[0],arr[1],arr[2],arr[3],arr[4]};//arr배열을 복사한 배열
	int k,j,max_index=0,max;

	for (k = 0; k < 3; k++)//중간값을 찾는 것이기에 3번 반복하여 5개중 가장 큰 수와 2번째로 큰 수를 제거하며 3번째로 큰 수를 찾는다.
	{
		for (j = 0; j < 5; j++)
		{
			max = MAX(replica[j], replica[max_index]);
			if (max == replica[j])
				max_index = j;
		}
		//위 반복문으로 구한 최대값이 있는 요소에 접근하여 그 요소에 있는 수를 0으로 만든다.
		if(k<2)
			replica[max_index] = 0;
	}
	return replica[max_index];
	
}