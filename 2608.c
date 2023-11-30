/*
I	V	X	L	C	D	M
1	5	10	50	100	500	1000
V, L, D는 한 번만 사용할 수 있고 I, X, C, M은 '연속'해서 세 번까지만 사용할 수 있다.
=>연속 세 번은 이전 것과 현재 것을 비교하여 변수에 숫자를 세는데 그 숫자가 3이상이면 프로그램을 종료한다.
만약 이전 것과 현재 것을 비교하여 다른 문자가 나오면 변수를 0으로 초기화 한다.
작은 숫자가 큰 숫자의 왼쪽에 오는 경우는 다음과 같다. 
IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900 을 나타낸다. 이들 각각은 한 번씩만 사용할 수 있다.

입력:로마 숫자로 이루어진 두 수를 입력받아 그 둘을 더한 값을 아라비아 숫자와 로마 숫자로 출력하는 프로그램을 작성하시오.
	왼쪽부터 큰 수에 해당하는 문자를 차례대로 입력한다.
출력:그에 해당하는 아라비아 숫자와 로마 숫자를 출력한다.

switch문을 이용하여 i v x l c d m에 따른 case로 이동하고 i x c 로 이동할 때 그 뒤에 각각 v x ,l c, d m이 붙는지를 확인한다.
그리고 로마 숫자를 계산하여 합계를 계산한다.
아라비아 숫자 출력후 그 숫자를 로마 숫자로 출력한다.
*/

#include <stdio.h>
int add(char*, int*, int*);
void Arabia_number(int);

int main(void)
{
	int i, c;
	int sum = 0;
	char arr[50];
	int check[3] = { 0 };//첫 번째 요소부터 각각 V,L,D를 의미한다.


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
						//전 것과 비교했을때 three가 2이상이면 3번 이상 나왔다는 것이다.
						//그때 전 것과 또 같은 것이 나왔다는 것이니깐 4번은 나왔다는 것이된다.
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