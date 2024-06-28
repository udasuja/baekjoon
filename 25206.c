/*
 * 전공평점을 계산해주는 프로그램을 작성해보자.
 *
 * 전공평점은 전공과목별 (학점 × 과목평점)의 합을 학점의 총합으로 나눈 값이다.
 *
 * 인하대학교 컴퓨터공학과의 등급에 따른 과목평점은 다음 표와 같다.
 *
 * A+	4.5
 * A0	4.0
 * B+	3.5
 * B0	3.0
 * C+	2.5
 * C0	2.0
 * D+	1.5
 * D0	1.0
 * F	0.0
 * P/F 과목의 경우 등급이 P또는 F로 표시되는데, 등급이 P인 과목은 계산에서 제외해야 한다.
 *
 * 과연 치훈이는 무사히 졸업할 수 있을까?
 *
 * 입력:
 * 20줄에 걸쳐 치훈이가 수강한 전공과목의 과목명, 학점, 등급이 공백으로 구분되어 주어진다.
 *
 * 출력:
 * 치훈이의 전공평점을 출력한다.
 * 정답과의 절대오차 또는 상대오차가 (10^{-4}) 이하이면 정답으로 인정한다.
 *
 * algorithm:
 * 공백을 기준으로 처음 문자열과 두번째 문자열은 무시하고 switch문을 이용하고 등급에 따른 점수를 더한다.
 *
 */

#include <stdio.h>

int main(void)
{
	char c,rank[3];
	int line=20;
	double grade,sum=0,sum_gra=0;
	while(line--)
	{
		while((c=getchar())!=' ');
		scanf("%lf",&grade);
		c=getchar();
		scanf("%s",rank);
		c=getchar();//scanf로 인한 공백문자 제거
		switch(rank[0])
		{
			case 'A':
				sum+=(rank[1]=='+')?4.5*grade:4.0*grade;
				break;
			case 'B':
				sum+=(rank[1]=='+')?3.5*grade:3.0*grade;
				break;
			case 'C':
				sum+=(rank[1]=='+')?2.5*grade:2.0*grade;
				break;
			case 'D':
				sum+=(rank[1]=='+')?1.5*grade:1.0*grade;
				break;
		}
		if (rank[0] != 'P')
			sum_gra += grade;
	}
	printf("%.6lf\n",sum/sum_gra);
}
	
