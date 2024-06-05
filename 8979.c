//입력의 첫줄 => 국가의 수 , 등수를 알고픈 국가
//입력 => 국가를 나타내는 정수값 , 금메달 ,은메달 ,동메달

#include <stdio.h>
#include <stdlib.h>

struct medal
//포인터 변수로 구성된 구조채
{
	int* gold;
	int* selver;
	int* copper;
}medal;



int main(void)
{
	int country_num, country_rank;
	medal.gold = (int*)malloc(sizeof(int) * 1000);
	//각 구조체를 int형 메모리를 할당한다.(4바이트*country_num 정도의 크기를 갖는 메모리 크기)
	//그것으로 메모리 크기를 할당 받은 구조체 배열을 만든다.
	medal.selver = (int*)malloc(sizeof(int) * 1000);
	medal.copper = (int*)malloc(sizeof(int) * 1000);
	int ranking = 1;
	int member;

	scanf_s("%d %d", &country_num, &country_rank);
	for (int i = 0; i < country_num; i++)
	{
		scanf_s("%d", &member);
		//member의 입력값은 1부터 시작하므로 배열의 0번째 요소부터 시작이 아닌 1부터 시작한다.
		scanf_s("%d %d %d", &medal.gold[member], &medal.selver[member], &medal.copper[member]);

	}
	for (int k = 1; k <= country_num; k++)
		//첫번째 나라부터 끝 나라까지 rank번째 나라와 비교하며.
		//k번째 나라보다 순위가 낮으면 ranking에다 1을 더하여 순위를 뒤로 미룬다.
	{
		if (medal.gold[k] > medal.gold[country_rank])
			//k번째 나라의 금메달이 더 많으면 rank나라의 순위는 뒤로 밀려난다.
		{
			ranking++;
		}
		else if (medal.gold[k] < medal.gold[country_rank])
			//rank가 금메달이 더 많을때
		{
			continue;
		}
		else if ((medal.gold[k] == medal.gold[country_rank]) && (medal.selver[k] > medal.selver[country_rank]))
			//k번째 나라의 은메달이 더 많으면 rank나라의 순위는 뒤로 밀려난다.
		{
			ranking++;
		}
		else if (medal.selver[k] < medal.selver[country_rank])
			//rank가 은메달이 더 많을때
		{
			continue;
		}
		else if ((medal.selver[k] == medal.selver[country_rank]) && (medal.copper[k] > medal.copper[country_rank]))
			//k번째 나라의 동메달이 더 많으면 rank나라의 순위는 뒤로 밀려난다.
		{
			ranking++;
		}
	}
	free(medal.gold);
	free(medal.selver);
	free(medal.copper);
	printf("%d", ranking);
	return 0;
}