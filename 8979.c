#include <stdio.h>

int main(void)
{
	int gold_arr[100] = { 0 }, selver_arr[100] = { 0 }, copper_arr[100] = { 0 };
	int country_num, rank,country_member;
	int country[1000][3];
	int g_last = 0, s_last=0, c_last=0;
	int g_sum = 0, s_sum = 0, c_sum = 0;

	scanf_s("%d %d", &country_num, &rank);
	for (int i = 0;i < country_num; i++)
	{
		int gold, selver, copper;
		scanf_s("%d", &country_member);
		scanf_s("%d %d %d", &country[country_member][0], &country[country_member][1], &country[country_member][2]);
		gold = country[country_member][0];
		selver = country[country_member][1];
		copper = country[country_member][2];
		
		if (country[country_member][0] > 0)
		{
			gold_arr[gold] += 1;
			g_last = g_last < gold ? gold + 1 : g_last;
			g_sum++;//rank의 금메달이 0일때를 대비하여
		}
		//gold값이 0이하 일때 밑의 조건문들을 실행
		else if (country[country_member][1] > 0)
		{
			selver_arr[selver] += 1;
			s_last = s_last < selver ? selver + 1 : s_last;
			s_sum++;//rank의 은메달이 0일때를 대비
		}
		//gold=<0 그리고 selver<=0일때 실행
		else if (country[country_member][2] > 0)
		{
			copper_arr[copper] += 1;
			c_last = c_last < copper ? copper + 1 : c_last;
			c_sum++;//rank의 동메달이 0일때를 대비
		}
	}

	if (country[rank][0] > 0)
	{
		int r_gold = country[rank][0]+1;
		int gold=1;
		while (r_gold < g_last)
		{
			gold += gold_arr[r_gold];

		}
		printf("%d", gold);
	}
	else if (country[rank][1] > 0)
	{
		int r_selver = country[rank][1] + 1;
		int selver= 1;
		while (r_selver < s_last)
		{
			selver += selver_arr[r_selver];

		}
		printf("%d", g_sum+selver);
	}
	else
	{
		int r_copper = country[rank][2] + 1;
		int copper = 1;
		if (country[rank][2] == 0)
		{
			printf("%d", g_sum + s_sum + c_sum);
		}
		else
		{
			
			while (r_copper < c_last)
			{
				copper += copper_arr[r_copper];

			}
			printf("%d", g_sum + s_sum+copper);
		}
	}
}