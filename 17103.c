/*
에라토스테네스의 체로 n범위 이내의 소수를 판별한다. 
소수는 1로 아직 검사하지 않는 수는 0으로 
소수 이외의 수는 -1이상으로 둔다.
소수를 판별한 후 2부터 시작하여 n과 뺀 뒤 
뺀 값이 소수면 출력 값을 1증가시킨다. 
이런 식으로 출력값을 찾을 수 있다.


각 textcase의 각각의 n을 입력받고 그 n범위의 소수를 에라토스테네스의 체로 판별하는 것보다
한번에 임의의 범위 내의 소수를 판별하는 것이 훨씬 시간 복잡도 측면에서 이득이다.
*/

#include <stdio.h>
#include <stdlib.h>
#define PRI 1
#define SIZE 1000000

int arr[SIZE+1];

void prime_number(void)
{
	int i;	
	for (i = 2; i <= SIZE; i++)
		arr[i] = 0;	//일단 0으로 초기화
					//이 코드는 필요없긴 하다 arr는 전역변수이므로 어차피 0으로 초기화된다.
					
	//소수 판별
	for (i = 2; i < SIZE + 1; i++)
	{
		int k;
		arr[i] = arr[i] == 0 ? PRI : arr[i];//arr[i]가 소수도, 소수가 아닌 수면(arr[i]==0) PRI로 설정
										//arr[i]!=0이면 밑의 반복문에 의해 -1로 설정된 것이다.
		for (k = i + i; arr[i]==PRI && k < SIZE + 1; k += i)
		{
			arr[k] = -1;	//소수가 아닌 수
		}
	}
	return;
}

int main(void)
{
	int t;
	prime_number();//소수 판별
	scanf_s("%d", &t);
	while (t--)
	{
		int i,n;
		int sum = 0;

		scanf_s("%d", &n);

		//골드바흐 파티션
		for (i = 2; i <= n /2; i++)
		{
			if (arr[i] == PRI&&arr[n-i]==PRI)
			{
				sum+=1;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}