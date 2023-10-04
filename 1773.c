/*
첫 입력: 학생의 수, 폭죽쇼가 끝나는 시간(초 단위)

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int student, sec;
	int time = 0;
	int* student_t;

	
	scanf_s("%d %d", &student, &sec);
	student_t = (int*)malloc(sizeof(int) * sec);
	for (int i = 0; i < student; i++)
	//학생 수만큼 반복한다.
	{
		int a;
		scanf_s("%d", &a);//어떤 학생의 폭주 주기를 입력받는다.
		for (int k = 1,j=a; j <= sec;)//k를 먼저1더하고 a와 곱한다.
		{
			if (student_t[j] != j)
			{
				student_t[j] = j;
				//배열에 저장하고
				time++;
			}
			j = a * ++k;
		}
	}

	printf("%d", time);
	return 0;
}