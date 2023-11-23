/*
I	V	X	L	C	D	M
1	5	10	50	100	500	1000
V, L, D는 한 번만 사용할 수 있고 I, X, C, M은 '연속'해서 세 번까지만 사용할 수 있다.
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
void Roma_number(char*, int*);
void Arabia_number(int);

int main(void)
{
	int sum = 0;
	char string[50];
	int i;

	for (i = 0; i < 2; i++)
	//로마 숫자를 아라비아 숫자로 변환
	{
		scanf_s("%s", string,sizeof(string));
		Roma_number(string, &sum);
		//string의 주소값을 반환하면 string에 저장된 문자열이 아닌 string을 가리키기 때문에
		//우리가 가리키고 싶은 것과는 차이가 있다.
		//그래서 string의 주소값을 반환하지 않으면 string에 저장된 문자열(문자열이 저장될 때는 그 문자열의 주소값을 저장한다.)
		//그 문자열의 주소값이 매개변수에 저장되어 매개변수는 그 문자열을 가리킬 것이다.
	}
	printf("%d\n", sum);
	//아라비아 숫자를 로마 숫자로 변환
	Arabia_number(sum);
	return 0;
}

void Roma_number(char arr[], int* sum)
{
	int j;
	for (j = 0; arr[j] != 0; j++)//j번째 요소가 널 문자일 때까지 반복한다.
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