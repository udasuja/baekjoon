/*
10대 컴퓨터가 순서대로 데이터를 처리할때 마지막 데이터가 처리되는 컴퓨터의 번호는?
ex)5대 컴퓨터 10개의 데이터=>1번com-1번data,2번com-2번data,3번com-3번data,4번com-4번data,5번com-5번data,1번com-6번data ... 5번com-10번data
입력: 반복횟수
	 데이터의 개수 a,b이때 a는 밑이고 b는 계승이다.

풀이:
	
	
	a를 1부터 b까지 제곱하면서 a의 1의 자리수와 제곱한 수의 1의 자리 숫자가 같아지면 그 횟수를 저장하고 그 횟수와 b를 나누고 나머지를 구한다.
	그리고 나머지만큼 a를 제곱하면서 a의 1의 자리수를 구한다.
*/
#include <stdio.h>

int main(void)
{
	int t, a, b, num1, i;
	scanf_s("%d", &t);
	while (t--)
	{
		int count = 1;
		scanf_s("%d %d", &a, &b);
		num1 = a;
		for (i = 0; i < b; i++)
		{
			num1 = num1 * a;
			if (a >= 10)
			{
				count++;
				num1 = (num1 % 100) % 10;
				if (num1 == a % 10)
					break;
			}
			else if (a < 10)
			{
				count++;
				num1 = num1 % 10;
				if (num1 == a)
					break;
			}
		}
		b -= count;
		while (b-->0)
		{
			num1 = num1 * a;
			if (a >= 10)
				num1 = (num1 % 100) % 10;
			else if (a < 10)
				num1 = num1 % 10;
		}
		printf("%d\n", num1 %10 );
	}
}