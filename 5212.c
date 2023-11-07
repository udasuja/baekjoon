/*
X가 있을때 상하좌우를 확인후 .이나 공백이 4칸이하 3칸이상 있으면 바다라고 출력한다.
12행,12열로 이뤄진 행렬을 만든 뒤 행은 1행부터 열은 1열부터 문자을 입력받기 시작한다.
그리고 입력받지 못한 공간은 0으로 만들고 상하좌우 \n나 .이나 0이 있으면 카운터를 센후 그 값이
4칸이하 3칸이상이면 바다로 출력한다.
*/



#include <stdio.h>
char arr[12][12] = { 0 };
char fifth_year[10][10];
void input(int, int);
void sea(int ,int);

int main(void)
{
	int input_row, input_col;

	scanf_s("%d %d", &input_row, &input_col);

	input(input_row, input_col);//바다와 육지를 입력받는다.
	sea(input_row, input_col);//가라앉는 바다를 찾는다.
}

void input(int input_row, int input_col)
//11 07날 1번째 열이 사라지는 오류가 발생한다.
{
	int c;
	for (int i = 1; i <= input_row; i++)
	{
		for (int j = 1; j <= input_col; j++)
		{
			char str=0;
			str = getchar();
			if (str == '\n')
			{
				break;
			}
			else
			{
				arr[i][j] = str;
			}
		}
		c = getchar();//마지막에 입력된 \n를 없애기위한 문장이다.

	}
}
void sea(int input_row, int input_col)
{
	for (int i = 1; i <= input_row; i++)
	{
		int count=-1;
		for (int j = 1; j <= input_col; j++)
		{
			if (arr[i][j] == 'X')
			{
				int sea_count = 0;
				while (count < 2)
				{
					if (arr[i][j + count] == '.' || arr[i][j + count] == '\n' || arr[i][j + count] == 0)
					{
						sea_count++;
					}
					if (arr[i + count][j] == '.' || arr[i + count][j] == 0)
					{
						sea_count++;
					}
					count++;
				}
				if (sea_count >= 3 && sea_count <= 4)
				{
					fifth_year[i][j] = '.';
					printf("%c", fifth_year[i][j]);
					continue;
				}
			}
			fifth_year[i][j] = arr[i][j];
			printf("%c", fifth_year[i][j]);
		}
		printf("\n");

	}
}