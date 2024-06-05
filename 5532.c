#include <stdio.h>

int main(void)
{
	int day, math_page, language_page, math_sol, language_sol;
	int i;
	scanf_s("%d %d %d %d %d", &day, &math_page, &language_page, &math_sol, &language_sol);
	for (i = 0; math_page != 0 || language_page != 0;)
	{
		math_page -= math_sol;
		language_page -= language_sol;
		i++;
		//for문의 괄호 안이 아닌 밖에 있는 이유는 수학과 국어 문제를 풀어
		//하루가 지났다는 것(=문제집을 1회 더 풀었다는 것)을 직관적으로 보여주기 위해서다.
		if (math_page <= 0 && language_page <= 0)
		//둘 다 0이하이면 더 이상 풀 페이지가 없다는 것이기에 반복을 종료한다.
		{
			break;
		}
	}
	printf("%d", day - i);
}