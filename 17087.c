/*
나의 위치, 친구의 위치를 하나의 배열에 넣고 오름차순 정렬한다.
n=1...일 때 n번째 값과 n+1값의 차이를 구하고
n번째 차이와 n+1번째 차이 쌍들의 gcd중 가장 큰 값을 구한다.

1.입력 배열들을 오름차순 정렬하고(나의 위치+친구의 위치=1+n만큼의 크기를 갖는다.)
2.가장 가까운 원소들끼리 뺀 값을 배열에 저장한다. 이때 뺀 값을 저장하는 배열의 크기는 입력 배열의 크기보다 1작다
3.모든 뺀 값에 통용되는 최대공약수를 찾으면 된다. 즉 모든 뺀 값의 공통된 약수이면서 최대값을 찾으면 된다.
*/


#include <stdio.h>
#include <stdlib.h>
#define MIN(A,B) (A<B?A:B)

int compare(void const* a, void const* b);
int gcd(int, int);

int main(void)
{
	int n;
	int* seq;
	int i,k;
	int co ;

	scanf_s("%d", &n);
	seq = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i < n+1; i++)
		scanf_s("%d", &seq[i]);
	
	qsort(seq, n + 1, sizeof(int), compare);//1

//2,3
	co = seq[1]-seq[0];
	for(k=1;k<n;k++)
	{
		co = gcd(co,seq[k+1]-seq[k]);
	}
	free(seq);
	printf("%d\n", co);
	return 0;
}

//stack overflow를 방지하기 위해 재귀함수 대신 반복문으로 gcd를 구함
int gcd(int oper, int re)
{
	while (re)//나머지가 0이면 반복종료
	{
		int temp = oper % re;
		oper = re;
		re = temp;
	}
	return oper;

}

int compare(void const* a, void const* b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	else if (*(int*)a > *(int*)b)
		return 1;
	else
		return 0;
}