/*
I	V	X	L	C	D	M
1	5	10	50	100	500	1000
V, L, D�� �� ���� ����� �� �ְ� I, X, C, M�� '����'�ؼ� �� �������� ����� �� �ִ�.
���� ���ڰ� ū ������ ���ʿ� ���� ���� ������ ����. 
IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900 �� ��Ÿ����. �̵� ������ �� ������ ����� �� �ִ�.

�Է�:�θ� ���ڷ� �̷���� �� ���� �Է¹޾� �� ���� ���� ���� �ƶ��� ���ڿ� �θ� ���ڷ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	���ʺ��� ū ���� �ش��ϴ� ���ڸ� ���ʴ�� �Է��Ѵ�.
���:�׿� �ش��ϴ� �ƶ��� ���ڿ� �θ� ���ڸ� ����Ѵ�.

switch���� �̿��Ͽ� i v x l c d m�� ���� case�� �̵��ϰ� i x c �� �̵��� �� �� �ڿ� ���� v x ,l c, d m�� �ٴ����� Ȯ���Ѵ�.
�׸��� �θ� ���ڸ� ����Ͽ� �հ踦 ����Ѵ�.
�ƶ��� ���� ����� �� ���ڸ� �θ� ���ڷ� ����Ѵ�.
*/

#include <stdio.h>
void Roma_number(char*, int*);
void Arabia_number(int);

int main(void)
{
	int sum = 0;
	char string[50];
	int i;

	for (i = 0; i < 2; i++)
	//�θ� ���ڸ� �ƶ��� ���ڷ� ��ȯ
	{
		scanf_s("%s", string,sizeof(string));
		Roma_number(string, &sum);
		//string�� �ּҰ��� ��ȯ�ϸ� string�� ����� ���ڿ��� �ƴ� string�� ����Ű�� ������
		//�츮�� ����Ű�� ���� �Ͱ��� ���̰� �ִ�.
		//�׷��� string�� �ּҰ��� ��ȯ���� ������ string�� ����� ���ڿ�(���ڿ��� ����� ���� �� ���ڿ��� �ּҰ��� �����Ѵ�.)
		//�� ���ڿ��� �ּҰ��� �Ű������� ����Ǿ� �Ű������� �� ���ڿ��� ����ų ���̴�.
	}
	printf("%d\n", sum);
	//�ƶ��� ���ڸ� �θ� ���ڷ� ��ȯ
	Arabia_number(sum);
	return 0;
}

void Roma_number(char arr[], int* sum)
{
	int j;
	for (j = 0; arr[j] != 0; j++)//j��° ��Ұ� �� ������ ������ �ݺ��Ѵ�.
	{
		switch (arr[j])
		{
		case 'I':
			if (arr[j + 1] == 'V')
			{
				*sum += 4;
				j++;
				break;
			}
			else if (arr[j + 1] == 'X')
			{

				*sum += 9;
				j++;
				break;
			}
			else
			{
				*sum += 1;
				break;
			}

		case 'V':
			*sum += 5;
			break;
		case 'X':
			if (arr[j + 1] == 'L')
			{
				*sum += 40;
				j++;
				break;
			}
			else if (arr[j + 1] == 'C')
			{
				*sum += 90;
				j++;
				break;
			}
			else
			{
				*sum += 10;
				break;
			}
		case 'L':
			*sum += 50;
			break;
		case 'C':
			if (arr[j + 1] == 'D')
			{
				*sum += 400;
				j++;
				break;
			}
			else if (arr[j + 1] == 'M')
			{
				*sum += 900;
				j++;
				break;
			}
			else
			{
				*sum += 100;
				break;
			}
		case 'D':
			*sum += 500;
			break;
		case 'M':
			*sum += 1000;
			break;
		}
	}
}

void Arabia_number(int num)
{
	int i=4, k = 1000;
	
	while (i--)
	{
		int num2 = num / k,s;

		switch (i)
		{
		case 3:
			if (num2 == 0)
			{
				break;
			}
			else if (num2 <= 4)
			{
				for (s = num2; s; s--)
				{
					printf("M");
				}
			}
			break;
		case 2:
			if (num2 == 0)
			{
				break;
			}
			else if (num2 <= 4)
			{
				int co = 0;
				num2 == 4 ? printf("CD") : co++;
				for (s = num2; co&&s; s--)
				{
					printf("C");
				}
			}
			else if (num2 <= 9)
			{
				int co = 0;
				num2 == 9 ? printf("CM") : (num2 == 5 ? printf("D") : co++);
				for (s = num2-5; co&&s; s--)
				{
					s == num2-5 ? printf("D") : printf("C");
				}
			}
			break;
		case 1:
			if (num2 == 0)
			{
				break;
			}
			else if (num2 <= 4)
			{
				int co = 0;
				num2 == 4 ? printf("XL") : co++;
				for (s = num2; co && s; s--)
				{
					printf("X");
				}
			}
			else if (num2 <= 9)
			{
				int co = 0;
				num2 == 9 ? printf("XC") : (num2==5?printf("L"):co++);
				for (s = num2-5; co && s; s--)
				{
					s == num2-5 ? printf("L") : printf("X");
				}
			}
			break;
		case 0:
			if (num2 == 0)
			{
				break;
			}
			else if (num2 <= 4)
			{
				int co = 0;
				num2 == 4 ? printf("IV") : co++;
				for (s = num2; co && s; s--)
				{
					printf("I");
				}
			}
			else if (num2 <= 9)
			{
				int co = 0;
				num2 == 9 ? printf("IX") : (num2 == 5 ? printf("V") : co++);
				for (s = num2-5; co && s; s--)
				{
					s == num2-5 ? printf("V") : printf("I");
				}
			}
			break;
		}

		num %= k;
		k /= 10;
	}
}