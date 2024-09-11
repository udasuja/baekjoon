/*
예를 살펴보며 문제에 대해 설명하겠다.

입력:
8 -> n값
4
3
6
8
7
5
2
1

먼저 1부터 4까지의 값을 스택에 넣는다.-> +가 4번 나옴
그 다음 4가 수열에 첫번째 자리에 있으므로 스택에서 4를 pop했다.-> -가 1번 나옴
3이 수열에 두번째 자리에 있으므로 스택에서 3를 pop했다. -> -가 1번 나옴
6이 수열에 세번째 자리에 있으므로 스택은 5와 6을 push했다. 그리고 6를 pop했다. -> +가 2번 나오고 -가 1번 나옴
8이 수열에 네번째 자리에 있으므로 스택은 7과 8을 push했다. 그리고 8를 pop했다. -> +가 2번 나오고 -가 1번 나옴
7이 수열에 다섯번째 자리에 있으므로 스택은 7를 pop했다. -> -가 1번 나옴


*/




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,n,no=1;
	int* arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);

	}
	
	for (i = 0;i < n; i++)
	{
		if (i == 0 || arr[i] > arr[i + 1])//현재 값이 이후 값보다 작으면 push실행
		{
			int k;
			k = i == 0 ? arr[i] : arr[i] - arr[i+1];
			while (k--)
			{
				printf("%d", k);
				printf("+\n");
			}
		}
		if(arr[i]+1==arr[i+1])//현재 값이 이후 값보다 1만큼 크면 pop실행
		{
			printf("-\n");
		}
	}
}