/*
X�� ������ �����¿츦 Ȯ���� .�̳� ������ 4ĭ���� 3ĭ�̻� ������ �ٴٶ�� ����Ѵ�.
12��,12���� �̷��� ����� ���� �� ���� 1����� ���� 1������ ������ �Է¹ޱ� �����Ѵ�.
�׸��� �Է¹��� ���� ������ 0���� ����� �����¿� \n�� .�̳� 0�� ������ ī���͸� ���� �� ����
4ĭ���� 3ĭ�̻��̸� �ٴٷ� ����Ѵ�.
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
	c = getchar();//scanf�� �Է��� �������� \n�� ����ؾ��ϴµ�
	//�� \n�� ��� �Է¹��ۿ� �����ְ� �ȴ�. �װ��� �����ִ� �����̴�.

	input(input_row, input_col);//�ٴٿ� ������ �Է¹޴´�.
	sea(input_row, input_col);//����ɴ� �ٴٸ� ã�´�.
	fifth_print(input_row, input_col);
	
}

void input(int input_row, int input_col)
//���� ������ ���� ������ �Է¹޴´�.
{
	int c;
	for (int i = 1; i <= input_row; i++)
	//���� ������ŭ �ݺ�
	{
		for (int j = 1; j <= input_col; j++)
		//���� ������ŭ �ݺ�
		{
			char str=0;
			str = getchar();
			//str�� ���ڸ� �����ϰ� �� ���ڰ� ���Ͷ�� �ݺ��� ����
			if (str == '\n')
			{
				break;
			}
			else
			{
				//���Ͱ� �ƴ϶�� i�� j���� ���� �����Ѵ�.
				arr[i][j] = str;
			}
		}
		c = getchar();//�������� �Էµ� \n�� ���ֱ����� �����̴�.

	}
}

void sea(int input_row, int input_col)
//50��ڿ� ������� ���� �ƴ� ���� �����ϴ� �Լ��̴�.
{
	for (int i = 1; i <= input_row; i++)
	{
		for (int j = 1; j <= input_col; j++)
		{
			if (arr[i][j] == 'X')
			//i�� j���� ����� ���ڰ� X���϶� ����
			{
				int sea_count = 0;
				int count = -1;
				while (count < 2)
				//�����¿� . \n 0�� �ϳ��̸� �ѷ��ΰ� �ִ� �ٴ��� ������ 1���� ��Ų��.
				//(.�� �ٴٶ�� ������ ���԰� 0�� \n�� �����(=�ٴ�)�� �ǹ��Ѵ�.)
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
				//3���̻��� �ٴٸ� �� ���� ����.
				{

					fifth_year[i][j] = '.';
					continue;
				}
			}
			//if���� ������� ������ continue�� ������� ���� ���̱⿡ ���� �ڵ尡 ����ȴ�.
			//�� arr�� i�� j���� fifth_year�� i�� j���� ����ȴ�.
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
			//fifth_year�̶�� �迭�� i�� j���� ���ڰ� X���϶�
			//���� ��� ����,���� ���� ������ i�� j�� ���� ���Ͽ� ������,����,���ۿ�,������ ���� �����Ѵ�.
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