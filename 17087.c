/*
나의 위치, 친구의 위치를 하나의 배열에 넣고 오름차순 정렬한다.
n=1...일 때 n번째 값과 n+1값의 차이를 구하고
n번째 차이와 n+1번째 차이 쌍들의 gcd중 가장 큰 값을 구한다.

1.입력 배열들을 오름차순 정렬하고(나의 위치+친구의 위치=1+n만큼의 크기를 갖는다.)
2.가장 가까운 원소들끼리 뺀 값을 배열에 저장한다. 이때 뺀 값을 저장하는 배열의 크기는 입력 배열의 크기보다 1작다
3.그 뺀 값이 저장된 배열을 오름차순 정렬한다.
4.뺀 값이 가장 작은 값을 기준으로 뺀 값의 모든 gcd를 구하고 가장 작은 값을 구한다.

4.의 근거는 다음과 같다.
만약 입력의 배열이 1 3 7 11일때 가장 가까운 원소들의 차는 다음과 같다.
3-1=2
7-3=4
11-7=4
나의 위치가 3일 때
만약 가장 작은 값이 아닌 임의의 값을 기준으로 하면 즉 4를 기준으로 하면
3-4=-1이므로 절대 1위치에 갈 수 없다 그렇기에 가장 작은 값을 기준으로 한다.
그리고 gcd를 구하는 이유는 A_n과 A_n+1의 차이가 5일 때 d=2로는 갈 수 없다.
그렇기에 차이 5와 차이 2의 최대공약수를 구하는 것이다.

즉 차이의 값 중 가장 작은 값을 기준으로 모든 차이의 값의 gcd를 구하는 값 중 가장 작은 값을 구하면 답을 구할 수 있다.


*/


#include <stdio.h>
#include <stdlib.h>
#define MIN(A,B) (A<B?A:B)

int compare(void const* a, void const* b);
int gcd(int, int);

int main(void)
{
	int n;
	int* seq,*dis;
	int i,k;
	int co ;

	scanf_s("%d", &n);
	seq = (int*)malloc(sizeof(int) * (n + 1));
	dis = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i < n+1; i++)
		scanf_s("%d", &seq[i]);
	
	qsort(seq, n + 1, sizeof(int), compare);//1
	
	for (k=0; k<n; k++)//2
		dis[k] = seq[k+1] - seq[k];
	
	qsort(dis, n, sizeof(int), compare);//3


//4
	co = dis[0];
	for(k=1;k<n;k++)
	{
		co = MIN(co, gcd(dis[0], dis[k]));
	}
	printf("%d\n", co);
	return 0;
}

int gcd(int oper, int re)
{
	if (oper % re == 0)
		return re;
	return gcd(re, oper % re);
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