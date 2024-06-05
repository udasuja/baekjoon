/*
X가 있을때 상하좌우를 확인후 .이나 공백이 4칸이하 3칸이상 있으면 바다라고 출력한다.
12행,12열로 이뤄진 행렬을 만든 뒤 행은 1행부터 열은 1열부터 문자을 입력받기 시작한다.
그리고 입력받지 못한 공간은 0으로 만들고 상하좌우 \n나 .이나 0이 있으면 카운터를 센후 그 값이
4칸이하 3칸이상이면 바다로 출력한다.
*/



#include <stdio.h>


int arr[12][12] = { 0 };
char fifth_year[10][10];
void input(int, int);
void sea(int ,int);
void fifth_print(int,int);

typedef struct
{
	int first;
	int last;
}MATRIX;

int main(void)
{
	int input_row, input_col;
	int c;
	scanf_s("%d %d", &input_row, &input_col);
	c = getchar();//scanf는 입력을 받을려면 \n를 사용해야하는데
	//이 \n는 계속 입력버퍼에 남아있게 된다. 그것을 지워주는 문장이다.

	input(input_row, input_col);//바다와 육지를 입력받는다.
	sea(input_row, input_col);//가라앉는 바다를 찾는다.
	fifth_print(input_row, input_col);
	
}

void input(int input_row, int input_col)
//행의 개수와 열의 개수를 입력받는다.
{
	int c;
	for (int i = 1; i <= input_row; i++)
	//행의 개수만큼 반복
	{
		for (int j = 1; j <= input_col; j++)
		//열의 개수만큼 반복
		{
			char str=0;
			str = getchar();
			//str의 문자를 저장하고 그 문자가 엔터라면 반복을 종료
			if (str == '\n')
			{
				break;
			}
			else
			{
				//엔터가 아니라면 i행 j열에 문자 저장한다.
				arr[i][j] = str;
			}
		}
		c = getchar();//마지막에 입력된 \n를 없애기위한 문장이다.

	}
}

void sea(int input_row, int input_col)
//50년뒤에 가라앉을 땅과 아닌 땅을 구분하는 함수이다.
{
	for (int i = 1; i <= input_row; i++)
	{
		for (int j = 1; j <= input_col; j++)
		{
			if (arr[i][j] == 'X')
			//i행 j열에 저장된 문자가 X라일때 실행
			{
				int sea_count = 0;
				int count = -1;
				while (count < 2)
				//상하좌우 . \n 0중 하나이면 둘러싸고 있는 바다의 개수를 1증가 시킨다.
				//(.은 바다라고 문제에 나왔고 0과 \n는 빈공간(=바다)을 의미한다.)
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
				if (sea_count >= 3 )
				//3면이상이 바다면 그 섬은 잠긴다.
				{

					fifth_year[i][j] = '.';
					continue;
				}
			}
			//if문이 실행되지 않으면 continue도 실행되지 않을 것이기에 밑의 코드가 실행된다.
			//즉 arr의 i행 j열이 fifth_year의 i행 j열에 저장된다.
			fifth_year[i][j] = arr[i][j];
		}
	}
}

void fifth_print(int input_row, int input_col)
{
	MATRIX col,row;

	col.first = row.first = 99;
	col.last = row.last = -99;

	for (int i = 1; i <= input_row; i++)
	{
		for (int j = 1; j <= input_col; j++)
		{
			if (fifth_year[i][j] == 'X')
			//fifth_year이라는 배열의 i행 j열의 문자가 X라일때
			//시작 행과 끝행,시작 열과 끝열을 i와 j에 각각 비교하여 시작행,끝행,시작열,끝열을 각각 저장한다.
			{
				col.first = col.first > j ? j : col.first;
				col.last = col.last < j ? j : col.last;
				row.first = row.first > i ? i : row.first;
				row.last = row.last < i ? i : row.last;
			}
		}
	}

	for (int r = row.first; r <= row.last; r++)
	{
		for (int c = col.first; c <= col.last; c++)
		{
			printf("%c", fifth_year[r][c]);
		}
		printf("\n");
	}
}