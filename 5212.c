/*
X�� ������ �����¿츦 Ȯ���� .�̳� ������ 4ĭ���� 3ĭ�̻� ������ �ٴٶ�� ����Ѵ�.
12��,12���� �̷��� ����� ���� �� ���� 1����� ���� 1������ ������ �Է¹ޱ� �����Ѵ�.
�׸��� �Է¹��� ���� ������ 0���� ����� �����¿� \n�� .�̳� 0�� ������ ī���͸� ���� �� ����
4ĭ���� 3ĭ�̻��̸� �ٴٷ� ����Ѵ�.
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

	input(input_row, input_col);//�ٴٿ� ������ �Է¹޴´�.
	sea(input_row, input_col);//����ɴ� �ٴٸ� ã�´�.
}

void input(int input_row, int input_col)
//11 07�� 1��° ���� ������� ������ �߻��Ѵ�.
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
		c = getchar();//�������� �Էµ� \n�� ���ֱ����� �����̴�.

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