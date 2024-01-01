/*
연산수를 줄일려면 3으로 최대한 나누는 것이 중요하다.
1을 빼서 3의 약수를 만들 수 있을 때에는 1을 빼고 
2를 빼야지만 3의 약수가 되는 경우는 2로 나누거나 1을 빼서 2의 약수로 만들어서 나눈다.
즉 순서는 3의 약수인가?
아니면 1을 빼서 3의 약수가 되는가?
아니면 1을 빼서 2의 약수가 되는가?순이다.
*/

#include <stdio.h>


void cycle(int,int*);

int main(void)
{
	while (1)
	{
		int n, sum = 0;
		scanf_s("%d", &n);
		cycle(n, &sum);
		printf("%d", sum);
	}
	return 0;
}

void cycle(int n, int* sum)
{
	if (n == 1)
		return ;

	if (n % 3 == 0)
	{
		*sum+=1;
		cycle(n / 3, sum);//이 함수에서 sum이라는 매개변수는 sum이라는 인자의 주소값을 저장하고 있기에
		//재귀함수 형태를 나타내기 위해 호출할 때는 인자로는 &sum이 아닌 sum을 쓰는 것이 맞다. 
	}
	else if ((n - 1) % 3 == 0)
	{
		*sum+=1;
		cycle((n-1), sum);
	}
	else if (n % 2 == 0)
	{
		*sum+=1;
		cycle(n / 2, sum);
	}
	else if ((n - 1) % 2 == 0)
	{
		*sum+=1;
		cycle(n - 1, sum);
	}
}