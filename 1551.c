/*
크기가 N인 수열 A가 주어졌을 때, 세준이는 인접한 두 원소의 차이를 이용해서 크기가 N-1인 수열 B를 만들 수 있다.
예를 들어, A = {5, 6, 3, 9, -1} 이었을 때, B = {6-5, 3-6, 9-3, -1-9} = {1, -3, 6, -10}이 된다. 즉, B[i] = A[i+1]-A[i]가 된다.
이 짓을 k번 했을 때의 수열 B를 출력하시오
입력: A수열의 길이, k번 반복
	  A수열(이때 수열의 숫자는 ,(쉼표)로 구분된다.)

풀이:
scanf로 하나의 숫자를 입력받고 getchar()로 이용하여 ,하나 입력받고 이것을 반복하며 n개의 숫자를 배열에 저장한다.
재귀함수를 이용하여 수열 B를 만들고 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>

void func(int* arr,int,int);

int main(void)
{
	int n,num_r;
	int* arr;
	int i;
	char c;
	scanf_s("%d %d", &n, &num_r);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
		c = getchar();
	}
	func(arr,n,num_r);
	free(arr);
	return 0;
}

void func(int* arr,int n,int num_r)
{
	int i = 0;
	if (num_r == 0)
	{
		printf("%d", arr[i++]);
		while (i < n)
		{
			printf(",%d", arr[i++]);
		}
		return;
	}

	while (i < n-1)//배열은 0부터 시작하므로 n개의 정수를 사용하고 싶으면 n-1까지 반복되야된다.
	{
		arr[i] = arr[i + 1] - arr[i];
		i++;
	}
	arr[i] = 0;//반복문이 끝나면 i는 n-1이 될 것이고 그 요소의 값을 0으로 만든다.(수열 B는 수열 A보다 길이가 1만큼 짧으므로)
	func(arr, n - 1, num_r - 1);//num_r이 0이 될 때 수열 B를 만들며 반복한다.
}