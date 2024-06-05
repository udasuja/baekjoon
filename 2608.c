/*
�θ� ���ڸ� �ƶ��Ʒ� �ٲٴ� ����� ���ʺ��� �˻��Ͽ� ���� ���ڿ� �ش��ϴ� ���ڰ� �����ʺ��� �� ũ�� �ٷ� �հ踦 ��������
�װ��� �ƴ϶�� �������� �� ũ�ٴ� ���ε�(��:iv,cd) �װ��� ������-������ ���� �� ���ָ� �ȴ�.
�ƶ��� ���ڸ� �θ��� �ٲٴ� ����� õ�� �ڸ����� �˻��Ͽ� �� �ڸ� ���� �ش��ϴ� ���ڸ�ŭ �ݺ��ϸ� �ȴ�.
 IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900�� ���� ����Ѵ�.
*/
#include <stdio.h>

int Check_char(char*);
void Roma_number(int);
int main(void)
{
	char arr[2][50];
	int i;
	int sum = 0;

	for (i = 0; i < 2; i++)
	{
		int j;
		fgets(arr[i], sizeof(arr[i]), stdin);
		
		for (j = 0; arr[i][j] != '\n'; j++)
		{
			if (j == 0)
			//���ڿ��� ù��° ���ڴ� �׳� �հ迡 �����ش�.
			{
				sum+=Check_char(&arr[i][j]);
			}
			else
			{
				if (Check_char(&arr[i][j - 1]) >= Check_char(&arr[i][j]))
				//���� ���ڰ� �� ū ��� Ȥ�� ���� ���ڰ� �Էµ� ���
				{
					sum += Check_char(&arr[i][j]);
				}
				else
				//������ ������ ���� �� ū ��� IV����
				{
					sum -= Check_char(&arr[i][j - 1]);
					sum += Check_char(&arr[i][j]) - Check_char(&arr[i][j - 1]);
				}
			}
		}
	}
	printf("%d\n", sum);
	Roma_number(sum);
	return 0;
}

int Check_char(char* arr)
{
	switch (*arr)
	{
	case 'M':
		return 1000;
	case 'D':
		return 500;
	case 'C':
		return 100;
	case 'L':
		return 50;
	case 'X':
		return 10;
	case 'V':
		return 5;
	case 'I':
		return 1;
	default://�ƹ��͵� �ش����� ����
		return 0;
	}
}

void Roma_number(int sum)
//�ƶ��� ���ڸ� �θ� ���ڷ� �ٲٴ� �Լ��� ����
{
	int i = 1000;
	while (i)
	{
		int share = sum / i;//�ڸ���
		if (i == 1000 && share > 0)
		//if������ i�� �ش��ϴ� sum�� �ڸ����� ã�´�.
		{
			while (share--)//�ڸ����� �ش��ϴ� ��ŭ �ݺ��Ѵ�.
			{
				printf("M");
			}
		}
		else if (i == 100)
		{
			switch (share)
			{
			case 9:
				printf("CM");
				break;
			case 8:case 7:case 6:case 5:
				printf("D");//500�� �ش��ϴ� ���ڴ� 1���� ���
				while (share - 5)
				{
					printf("C");//share-5����ŭ C����Ѵ�.
					share--;
				}
				break;
			case 4:
				printf("CD");
				break;
			case 3:case 2:case 1:
				while (share--)
				{
					printf("C");
				}
				break;
			}
		}
		else if (i == 10)
		{
			switch (share)
			{
			case 9:
				printf("XC");
				break;
			case 8:case 7:case 6:case 5:
				printf("L");
				while (share - 5)
				{
					printf("X");
					share--;
				}
				break;
			case 4:
				printf("XL");
				break;
			case 3:case 2:case 1:
				while (share--)
				{
					printf("X");
				}
				break;
			}
		}
		else if (i == 1)
		{
			switch (share)
			{
			case 9:
				printf("IX");
				break;
			case 8:case 7:case 6:case 5:
				printf("V");
				while (share - 5)
				{
					printf("I");
					share--;
				}
				break;
			case 4:
				printf("IV");
				break;
			case 3:case 2:case 1:
				while (share--)
				{
					printf("I");
				}
				break;
			}
		}
		sum %= i;
		i /= 10;
	}
}