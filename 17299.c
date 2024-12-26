/*
Ai가 수열 A에서 등장한 횟수를 F(Ai)라고 했을 때
Ai의 오등큰수는 오른쪽에 있으면서
수열 A에서 등장한 횟수가 F(Ai)보다 큰 수 중에서
가장 왼쪽에 있는 수를 의미한다. 
그러한 수가 없는 경우에 오등큰수는 -1이다.

그럼 17298처럼 문제를 풀되
stack에 들어가고 그 stack의 top과 비교하는 수는 현재의 원소값에 대한 배열이 아닌
F(Ai)에 대한 배열의 원소와 비교하면 된다.

입력 배열의 원소값과 top이 가리키는 stack의 원소값을 count배열의 index로 하여 그 원소의 F(Ai)값에 접근한다. 그리고 둘을 비교한다.

*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000

int stack[SIZE];
int sequ[SIZE];
int top = -1;

int empty(int top)
{
	return top == -1;
}

int main(void)
{
	int n, i;
	int* count = (int*)calloc(SIZE,sizeof(int));	//모든 원소를 0으로 초기화
	int s_ind;	//stack에는 현재의 원소 값이 저장되야한다. 

	scanf_s("%d", &n);
	for (i = 0;i < n;i++)
	{
		int ind;
		scanf_s("%d", &sequ[i]);
		ind = sequ[i];
		count[ind]++;	//입력값의 횟수를 센다.
	}

	for (i = n - 1;i >= 0;i--)
	{
		int ind=sequ[i];	//i번째 입력값을 ind에 넣어 count의 index로 활용한다.
		int result;

		while (!empty(top))
		{
			if (count[s_ind] > count[ind])	//오등큰수를 발견하는 조건
				break;
			top--;	//pop연산
			s_ind = stack[top];	
		}

		if (empty(top))
//stack이 텅 비었다는 것은 현재 원소의 횟수가 모든 stack내에 저장된 원소의 횟수보다 크다는 것이다.
		{
			result = -1;	
		}
		else
		{
			result = stack[top];	//오등큰수 (stack의 top은 조건에 맞는 입력 배열의 원소를 가리키므로)
		}

		stack[++top] = sequ[i];
		sequ[i] = result;	//어차피 sequ[i]는 stack에 넣어졌으로 sequ는 결과값을 저장하는 배열로 쓴다.
		s_ind = stack[top];	//stack의 top이 가리키는 원소에 대한 count값을 얻기 위해 stack의 top이 가리키는 원소를 index로 함
	}
	for (i = 0;i < n;i++)
	{
		printf("%d ", sequ[i]);
	}

	free(count);
	return 0;
}