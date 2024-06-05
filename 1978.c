/*
어떤 자연수 n의 제곱근 이하의 수로 n이 한 번이라도 나누어 떨어지면 합성수이고 아니면 소수다. 
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int num1, num2,i,sum=0;
	scanf_s("%d", &num1);

	for (i = 0; i < num1; i++)
	{
		int k;
		scanf_s("%d", &num2);
		for (k = 2; k < sqrt(num2); k++)//2부터 num2의 제곱근 바로 전의 자연수까지 비교한다.
			//이때 범위 내의 자연수 중에 나누어 떨어지는 것이 하나라도 있으면 반복을 졸료한다.
			//나누어 떨어지는 것이 한 개도 없으면 k는 sqrt보다 큰 자연수 중에 가장 작은 자연수가 되면서 반복이 종료될 것이고
			//num2의 제곱근이 자연수가 아니라면 num2의 제곱근으로 num2을 나누어도 나누어 떨어지지 않을 것이므로 sum에 1을 추가한다.
			//자연수라면 어떤 수의 제곱이 num2가 되므로 당연이 그때의 어떤 수가 num2의 약수이므로 num2는 합성수이다.
		{
			if (num2 % k == 0)
				break;
		}
		if (k > sqrt(num2))
		{
			sum += sqrt(num2) - (int)sqrt(num2) > 0 ? 1 : 0;
		}
	}
	printf("%d", sum);
	return 0;
}