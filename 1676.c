/*문제
 * N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.
 *
 * 입력
 * 첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)
 *
 * 출력
 * 첫째 줄에 구한 0의 개수를 출력한다.
 *
 * 예제 입력 1 
 * 10
 * 예제 출력 1 
 * 2
 * 예제 입력 2 
 * 3
 * 예제 출력 2 
 * 0
 *
 * algorithm:
 * n!을 구하는 함수를 구현
 * 	int fac(int n)
 * 		if(n==1)
 * 			return 1;
 * 		return n*fac(n-1);
 * 0의 개수를 구하는 함수
 * 	 n!을 s라는 변수에 저장한다.
 *	 s을 10으로 나누고 나머지가 0이면
 *	 s을 10으로 나눈 몫을 s에 저장한다.
 * 	 이 과정을 나머지가 0이 아닐 때까지 반복한다.
 *
 */
#include <stdio.h>

unsigned long long factorial(int n)
{
	if(n==1)
		return 1;
	return n*factorial(n-1);
}
int number_zero(unsigned long long fac)
{
	int num=0;
	while(fac%10==0)
	{
		fac=fac/10;
		num++;
		
	}
	return num;
}



int main(void)
{
	int n;
	int num=0;
	unsigned long long fac;
	scanf("%d",&n);
	fac=factorial(n);
	num=number_zero(fac);
	printf("%d\n",num);
	return 0;
}
