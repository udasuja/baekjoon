/*
전쟁은 여러 번의 전투로 이루어진다. 각 전투에서 살아있는 병사중 제일 약한 병사가 죽는다. 
만약 제일 약한 병사가 여러 명이고, 제일 약한 병사가 모두 같은 편에 있다면, 그 중에 한 명이 임의로 선택되어 죽는다. 
하지만, 제일 약한 병사가 여러 명이고, 양 편에 모두 있다면, "세비"의 제일 약한 병사 중 한 명이 임의로 선택되어 죽는다.
전쟁은 한 명의 병사를 제외하고 모두 죽었을 때 끝난다. 전쟁의 승자를 출력하는 프로그램을 작성하시오.

입력:
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 100보다 작거나 같다. 

"각 테스트 케이스"는 다음과 같이 이루어져 있다.
=>
첫째 줄에 N(세준의 병사)과 M(세비의 병사)이 들어오고, 
둘째 줄에는 세준이의 병사들의 힘이 들어오고, 
셋째 줄에는 세비의 병사들의 힘이 들어온다. 
힘은 정수이고, 이 값이 클수록 강하고, 작을수록 약하다.

출력:
각 테스트 케이스에 대해서 한 줄에 하나씩 차례대로 승자를 출력한다. 
세준이가 이기면 S를 세비가 이기면 B를 둘다 아닐 경우에는 C를 출력한다.

풀이:
세준의 병사의 힘을 저장한다.
세비의 병사의 힘을 저장한다.
각각의 병사 중 가장 작은 힘을 갖은 병사 한 명을 뽑고 그 둘을 비교하여 가장 작은 힘을 갖은 병사를 죽인다.
같으면 세비의 병사를 죽인다.
둘 중의 병사가 1만 남을 때까지 반복한다.

구현:
구조체
{
	병사의 힘(char형 배열)
}

int main
{
	세준의 병사, 세빈의 병사
	세준의 병사와 세빈의 병사들의 각각의 힘을 입력받는다.
	각각의 병사들을 퀵 정렬을 통해 정렬한다.
	0번째 요소부터 비교하여 숫자가 작은 애를 죽이고
	살아남은 0번째 요소와 죽은 후 다음 숫자를 지닌 애와 비교하여 죽을지 살지를 결정한다.
	마지막 요소의 다다를 때까지 반복한다.
}
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 < num2)
	{
		return -1;
	}
	else if (num1 > num2)
	{
		return 1;
	}
	else
		return 0;
}

void war(int*, int*,int ,int);

int main(void)
{
	//int* bin, * jun;
	int t,i;

	scanf_s("%d", &t);

	for(i=0;i<t;i++)		
	{
		int bin_num, jun_num,n;
		scanf_s("%d %d", &jun_num,&bin_num);
		int *bin = (int*)malloc(sizeof(int) * bin_num);
		int *jun = (int*)malloc(sizeof(int) * jun_num);
		for (n = 0; n < jun_num; n++)
		{
			scanf_s("%d", &jun[n]);
		}
		for (n = 0; n < bin_num; n++)
		{
			scanf_s("%d", &bin[n]);
		}
		if (!bin_num)
		{
			printf("S\n");
			i++;
			continue;
		}
		else if (!jun_num)
		{
			printf("B\n");
			i++;
			continue;
		}
		qsort(jun, sizeof(jun) / sizeof(int), sizeof(int), compare);
		qsort(bin, sizeof(bin) / sizeof(int), sizeof(int), compare);
		war(jun, bin,jun_num,bin_num);
	}

}

void war(int* jun, int* bin,int jun_num,int bin_num)
{
	int b, j;
	for (b = j = 0; b < bin_num && j < jun_num;)
	{
		if (jun[j] > bin[b])
		{
			b++;
		}
		else if (jun[j] < bin[b])//세준의 팀원이 약하면 세준의 팀원이 죽는다.
		{
			j++;
		}
		else//서로 같으면 세비의 팀원이 죽는다.
		{
			b++;
		}
	}
	if ((jun_num - j) > (bin_num - b))//살아남은 병사가 세준이 더 많은 경우
	{
		printf("S\n");
	}
	else if ((jun_num - j) < (bin_num - b))//살아남은 병사가 세비가 더 많은 경우
	{
		printf("B\n");
	}
}