/*
에라토스테네스의 체로 n범위 이내의 소수를 판별한다. 
소수는 -1로 아직 검사하지 않는 수는 0으로 
소수 이외의 수는 1이상으로 둔다.
소수를 판별한 후 2부터 시작하여 n과 뺀 뒤 
뺀 값이 소수면 출력 값을 1증가시킨다. 
이런 식으로 출력값을 찾을 수 있다.
*/

#include <stdio.h>
#include <stdlib.h>
#define PRI -1


int main(void)
{
	int t;

	scanf_s("%d", &t);

	while (t--)
	{
		int i,n;
		int *arr;
		int sum = 0;

		scanf_s("%d", &n);

		arr = (int*)calloc(n+1, sizeof(int));
		//소수 판별
		for (i = 2; i < n + 1; i++)
		{
			int k;
			int j=1;

			if (arr[i] == 0)
			{
				arr[i] = PRI;
			}

			for (k = i * (1 + j); arr[i]==PRI && k < n + 1; k =i*(1+ j))
			{
				arr[k] += 1;
				j++;
			}
		}

		//골드바흐 파티션
		for (i = 2; i < n + 1; i++)
		{
			if (arr[i] == PRI)
			{
				int diff = n - i;
				sum+=arr[diff] = arr[diff] == PRI ? 1 : 0;
				
			}
		}
		printf("%d\n", sum);
		free(arr);
	}
}