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

3개의 배열을 동적할당한다. 하나는 수열에 관한 배열로 int형 n개의 인덱스를 갖도록
다른 하나는 stack에 관한 배열로 int형 n개의 인덱스를 갖도록
마지막으로 +,-에 관한 배열로 char형 n*2개의 인덱스를 갖도록(+는 n개가 무조건 출력되야하고, -도 n개가 무조건 출력되야되므로)

arr[i]값 이전의 값을 전부다 stack에 집어넣는다. 반복되는 횟수만큼 ch_arr에도 +를 집어넣는다.
stack[top]값이랑 arr[i]값이 서로 다르면 stack의 맨 꼭대기의 있는 값을 반환하는 것이 아니므로 no를 출력하고 프로그램을 종료한다.
하지만 둘이 같으면 stack[top]값을 출력하고 -를 ch_arr에 집어넣는다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,n,k=0;
	int* stack, * arr;
	int top = -1,ch_top=-1;
	char* ch_arr;

	scanf("%d", &n);
	stack = (int*)malloc(sizeof(int) * n);
	arr = (int*)malloc(sizeof(int) * n);
	ch_arr = (char*)malloc(sizeof(char) * (n * 2 + 1));


	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}


	for (i = 0; i < n; i++)
	{
		while (k < arr[i])//i번째 값이 이전 값보다 크면 push를 진행함
		{
			top++;//스택의 인덱스에 해당
			k++;//스택에 들어갈 값에 해당
			ch_top++;
			stack[top] = k;
			ch_arr[ch_top] = '+';
		}
		if (stack[top] != arr[i])//만약 i번째 값이 이전 값보다 작으면 위 반복문을 실행하지 않는데, top번째 값이랑 다르면 스택에 맨 위에 값이 아니라는 것이다.
		{
			printf("NO\n");
			return 0;
		}
		else 
		{
			ch_top++;
			ch_arr[ch_top] = '-';
			stack[top] = 0;//초기화
			top--;//가리키는 인덱스를 하나 감소시킨다.
		}
	}
	for (i = 0; i <= ch_top; i++)//+,-를 차례대로 출력한다.
	{
		printf("%c\n", ch_arr[i]);
	}

}