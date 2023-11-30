/*
I	V	X	L	C	D	M
1	5	10	50	100	500	1000
V, L, D�� �� ���� ����� �� �ְ� I, X, C, M�� '����'�ؼ� �� �������� ����� �� �ִ�.
=>���� �� ���� ���� �Ͱ� ���� ���� ���Ͽ� ������ ���ڸ� ���µ� �� ���ڰ� 3�̻��̸� ���α׷��� �����Ѵ�.
���� ���� �Ͱ� ���� ���� ���Ͽ� �ٸ� ���ڰ� ������ ������ 0���� �ʱ�ȭ �Ѵ�.
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
int add(char*, int*, int*);
void Arabia_number(int);

int main(void)
{
	int i, c;
	int sum = 0;
	char arr[50];
	int check[3] = { 0 };//ù ��° ��Һ��� ���� V,L,D�� �ǹ��Ѵ�.


	for (i = 0; i < 2; i++)
	{
		int three = 0;
		fgets(arr, sizeof(arr), stdin);
		for (c = 0; arr[c] != '\0'; c++)
		{
			if (arr[c] == 'V' || arr[c] == 'L' || arr[c] == 'D')
			{
				arr[c] == 'V' ? check[0]++, add(arr, &sum, &c) : 0;
				arr[c] == 'L' ? check[1]++, add(arr, &sum, &c) : 0;
				arr[c] == 'D' ? check[2]++, add(arr, &sum, &c) : 0;

			}
			else
			{
				add(arr, &sum, &c);
				if (arr[c] == arr[c + 1])
				{
					if (three < 2)
					{
						three++;
					}
					else if (three >= 2)
						//�� �Ͱ� �������� three�� 2�̻��̸� 3�� �̻� ���Դٴ� ���̴�.
						//�׶� �� �Ͱ� �� ���� ���� ���Դٴ� ���̴ϱ� 4���� ���Դٴ� ���̵ȴ�.
					{
						return 0;
					}
				}
				else
				{
					three = 0;
				}
			}
		}
		if (check[0] > 1 || check[1] > 1 || check[2] > 1)
		{
			return 0;
		}
		else
		{
			check[0] = check[1] = check[2] = 0;
		}
	}
	printf("%d\n", sum);
	Arabia_number(sum);
	return 0;
}

int add(char arr[], int* sum, int* c)
{

	int before = *sum;
	switch (arr[*c])
	{
	case 'V':
		*sum += 5;
		break;
	case 'L':
		*sum += 50;
		break;
	case 'D':
		*sum += 500;
		break;
	case 'I':
		if (arr[*c + 1] == 'V')
		{
			*sum += 4;
			*c += 1;
		}
		else
		{
			*sum += arr[*c + 1] == 'X' ? 9 : 1;
			*c += *sum - before == 1 ? 0 : 1;
		}
		break;
	case 'X':
		if (arr[*c + 1] == 'L')
		{
			*sum += 40;
			*c += 1;
		}
		else
		{
			*sum += arr[*c + 1] == 'C' ? 90 : 10;
			*c += *sum - before == 10 ? 0 : 1;
		}
		break;
	case 'C':
		if (arr[*c + 1] == 'D')
		{
			*sum += 400;
			*c += 1;
		}
		else
		{
			*sum += arr[*c + 1] == 'M' ? 900 : 100;
			*c += *sum - before == 100 ? 0 : 1;
		}
		break;
	case 'M':
		*sum += 1000;
		break;
	}
	return 0;
}

void Arabia_number(int num)
{
	int i = 4, k = 1000;

	while (i--)
	{
		int num2 = num / k, s;

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
				for (s = num2; co && s; s--)
				{
					printf("C");
				}
			}
			else if (num2 <= 9)
			{
				int co = 0;
				num2 == 9 ? printf("CM") : (num2 == 5 ? printf("D") : co++);
				for (s = num2 - 5; co && s; s--)
				{
					s == num2 - 5 ? printf("D") : printf("C");
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
				num2 == 9 ? printf("XC") : (num2 == 5 ? printf("L") : co++);
				for (s = num2 - 5; co && s; s--)
				{
					s == num2 - 5 ? printf("L") : printf("X");
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
				for (s = num2 - 5; co && s; s--)
				{
					s == num2 - 5 ? printf("V") : printf("I");
				}
			}
			break;
		}

		num %= k;
		k /= 10;
	}
}