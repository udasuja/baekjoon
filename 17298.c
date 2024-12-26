/*
배열의 마지막 원소부터 for문을 시작하여 현재 stack의 top이 가리키는 값과 비교한다. 
만약 가리키는 값보다 현재의 배열의 원소 값이 더 크면 pop연산을 하고 
작으면 그 값이 현재의 배열의 원소의 오큰수가 된다(이때는 pop연산을 하지 않음). 
만약 stack이 비어있으면 현재의 원소의 오큰수는 -1이 된다. 
(현재의 배열의 원소값보다 작을 때만 pop연산을 함으로 오큰수를 재활용할 수 있다.
즉 3 2 7일 때 2의 오큰수를 구한뒤 pop연산을 안하기 때문에
2의 오큰수도 7이 될 수 있고, 3의 오큰수도 7이 될 수 있다.)
그리고 현재 i에 대한 for문의 마지막 명령은 현재의 배열의 원소값을 push하는 것이다.

*/

#include <stdio.h>
#define SIZE 1000000

int stack[SIZE];//현재 원소의 오른쪽 원소들을 stack에 저장
int sequ[SIZE];
int resu[SIZE];//결과(오큰수) 저장
int top = -1;

int empty(int top)
{
	return top == -1;
}

int main(void)
{
	int n, k;

	scanf_s("%d", &n);
	for (k = 0;k < n;k++)
	{
		scanf_s("%d", &sequ[k]);
	}

	for (k = n - 1;k >= 0;k--)
	{
		while (!empty(top) && stack[top] <= sequ[k])	
		//stack의 top값이 현재 원소보다 작거나 같으면 그 값을 pop한다.
		{
			top--;//pop연산
		}
		if (empty(top))
		{
			resu[k] = -1;	//오큰수가 없는 경우
		}
		else
		{
			resu[k] = stack[top];	//stack의 top이 오큰수인 경우
		}

		stack[++top] = sequ[k];	//현재의 원소값 push
	}
	for (k = 0;k < n;k++)
		printf("%d ", resu[k]);
	return 0;
}