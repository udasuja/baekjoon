/*
같은 반 학생 중 1학년부터 5학년까지 다른 학우와 같은 반이 된 횟수가 가장 많은 애가
임시반장이된다. 이때 임시반장이 될 수 있는 애가 여러명이면 가장 작은 번호의 학생이 임시반장이 된다.
(2차원 배열에서 열의 개수는 무조건 5이다.)
풀이:일단 malloc함수로 학생수를 늘린다. 그 학생 배열의 길이는 5이다.
열을 한 개씩 비교하며 같은 숫자가 있는 애들의 count를 1증가시킨다.
count가 가장 큰 애를 출력, 같으면 번호가 작은 애를 출력.


*/
#include <stdio.h>
//구조체 변수와 student_count함수의 compare에 malloc함수를 사용했더니 메모리 부족 현상이 나왔다.
#define MAX(a,b) a>b?a:b

typedef struct
{
	int stu[5];
	int count;
}STU;

void student_count(STU*, int);

int main(void)
{
	STU student[1000];
	int n, i, k;
	int max_ = 0;

	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < 5; k++)
		{
			student[i].count = 0;//i번째 학생의 count값을 0으로 초기화한다.
			scanf_s("%d", &student[i].stu[k]);
		}
	}
	student_count(student, n);
	for (i = 0; i < n; i++)
	{
		max_ = student[i].count > student[max_].count ? i : max_;
	}
	printf("%d", max_ + 1);

	return 0;
}

void student_count(STU* student, int n)//1번 학생부터 1학년부터 5학년중 같은 반인 애가 있는지 검사하고 그다음 2번 이런식으로 올라간다.
{
	int i, k, index = 0;
	while (index < n)
	{
		int compare[1000] = { 0 };//같은 반이 된 학생을 중복되어 셈하지 않는다.
		int start = 0;
		for (i = 0; i < 5; i++)//1학년부터 5학년까지
		{
			for (k = start; k < n; k++)//1번부터 n번까지 index번과 검사하여 서로 같으면 index count에 1추가한다.
			{
				if (k != index && student[k].stu[i] == student[index].stu[i] && compare[k] != 1)
					//k==index일때는 무조건 count가 1추가되므로 k!=index일 때와
					//student[k].stu[i] == student[index].stu[i]=>index번째 학생과 k번째 학생이 i학년일 때 같은반이고
					//compare배열의 k번째 요소가 1이 아니면 조건문 실행
				{
					student[index].count += 1;
					compare[k] = 1;

				}
			}
		}
		index++;
	}
}