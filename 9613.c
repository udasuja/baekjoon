/*
최대공약수(gcd)의 합
첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있다. 
각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 
다음에는 n개의 수가 주어진다


오름차순 정렬 후 각 요소들을 쌍으로 만든뒤 gcd를 구하고 그 값의 합을 구한다. -> 정렬은 굳이 필요없으므로 제외되었다.
유클리드 호제법 적용하여 푼다.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int* arr;
	int cnum;
}test_case;

//int compare(const void* a, const void* b);
int gcd(int ,int );


int main(void)
{
	int k;

	scanf_s("%d", &k);

	while (k--)
	{
		test_case t;
		int i,j;
		long long sum = 0;

		scanf_s("%d", &t.cnum);
		t.arr = (int*)malloc(sizeof(int) * t.cnum);
		for(i=0;i<t.cnum;i++)
			scanf_s("%d", &t.arr[i]);
//		qsort(t.arr, t.cnum, sizeof(int), compare);
		for (i = 0; i < t.cnum - 1; i++)//마지막 요소 바로 이전까지 반복
			for (j = i; j < t.cnum - 1; j++)
				sum += gcd(t.arr[i], t.arr[j + 1]);
			

		printf("%ld\n", sum);
		free(t.arr);
	}
}

int gcd(int oper,int re)
{
	if (oper % re == 0)
		return re;
	return gcd(re,oper%re);
}

/*
int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	else if (*(int*)a > *(int*)b)
		return 1;
	else
		return 0;
}
*/