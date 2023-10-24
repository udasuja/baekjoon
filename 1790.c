/*
10에서 20까지 10,11,12,13,14---19라 했을때 일의 자리에 있는 숫자의 개수는 10개
10의 자리에 있는 숫자의 개수는 10개로 총 20개의 숫자가 나온다.
즉 나온 숫자의 개수(=10) * 자리수
100에서 110까지는 100,101,102,103----109로 총 3*10로 30개의 숫자가 나온다.
*/
#include <stdio.h>

int main(void)
{
	int n, s,k=1;//k는 a에 10을 곱한 횟수가 된다.
	int i = 1,a=1,number=0;
	scanf_s("%d %d", &n, &s);
	while (i <= n)
	{
		int quotient = i / a, remain = i % a;
		if (quotient == 10)//몫이 10이 되면 자리수가 1개 증가했다는 것이기에
		//a에 10을 곱해준다.
		{
			a *= 10;
			k++;
		}
		if (number + k >= s)
		//number=숫자의 번호를 의미 즉 1,2,3,4,라 했을때 3일때의 number는 3이된다.
		{
			for (int j = 1; j <= k; j++)
			{
				
				if (j == k)
				//j==k이면은 i숫자의 맨끝자리의 수를 출력하라는 의미이기에 나머지 출력
				{
					return printf("%d", remain);
				}
				else if (number + j == s)
				{
					return printf("%d", quotient);
				}
				remain = i % a;
				a /= 10;
				quotient = remain / a;
			}
		}
		else
		//위 조건이 아니면 그 숫자내에서는 없는 것이기에 자리수만큼 증가
		{
			number += k;

		}
		i++;
	}
	printf("%d", -1);
	return 0;
}