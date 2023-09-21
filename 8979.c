//입력의 첫줄 => 국가의 수 , 등수를 알고픈 국가
//입력 => 국가를 나타내는 정수값 , 금메달 ,은메달 ,동메달

#include <stdio.h>

int main(void)
{
	int country_num, country_rank;
	int country_m[500][3];
	int ranking = 1;
	int member;
	
	scanf_s("%d %d", &country_num, &country_rank);
	for (int i = 0; i < country_num; i++)
	{
		scanf_s("%d", &member);
		//member의 입력값은 1부터 시작하므로 배열의 0번째 요소부터 시작이 아닌 1부터 시작한다.
		scanf_s("%d %d %d", &country_m[member][0], &country_m[member][1], &country_m[member][2]);
		
	}
	for (int k = 1; k <=country_num; k++)
	//첫번째 나라부터 끝 나라까지 rank번째 나라와 비교하며.
	//k번째 나라보다 순위가 낮으면 ranking에다 1을 더하여 순위를 뒤로 미룬다.
	{
		if (country_m[k][0] > country_m[country_rank][0])
			//k번째 나라의 금메달이 더 많으면 rank나라의 순위는 뒤로 밀려난다.
		{
			ranking++;
		}
		else if (country_m[k][0] < country_m[country_rank][0])
			//rank가 금메달이 더 많을때
		{
			continue;
		}
		else if ((country_m[k][0] == country_m[country_rank][0]) && (country_m[k][1] > country_m[country_rank][1]))
			//k번째 나라의 은메달이 더 많으면 rank나라의 순위는 뒤로 밀려난다.
		{
			ranking++;
		}
		else if (country_m[k][1] < country_m[country_rank][1])
			//rank가 은메달이 더 많을때
		{
			continue;
		}
		else if ((country_m[k][1] == country_m[country_rank][1]) && (country_m[k][2] > country_m[country_rank][2]))
			//k번째 나라의 동메달이 더 많으면 rank나라의 순위는 뒤로 밀려난다.
		{
			ranking++;
		}
	}
	printf("%d", ranking);
	return 0;
}