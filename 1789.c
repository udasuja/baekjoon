/*문제
 * 서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?
 *
 * 입력
 * 첫째 줄에 자연수 S(1 ≤ S ≤ 4,294,967,295)가 주어진다.
 *
 * 출력
 * 첫째 줄에 자연수 N의 최댓값을 출력한다.
 *
 * 예제 입력
 * 200
 * 예제 출력 
 * 19
 * 
 * 1부터 시작하여 등차수열의 합을 구한뒤 그 k개의 등차수열의 합이 s와 같거나 크면 k-1이 그 답이된다. 
 */

#include <stdio.h>
#define AP(n) (((n+1)%2==0)?((n+1)/2)*n:(n+1)*(n/2))

long long binary_search(long long n, long long s)
{
	n = n / 2;
	if (AP(n) < s)
		return n;
	return binary_search(n, s);//위 반복문이 만족되어 n이 return 되면 
							   //그 n에 대한 n*2를 매개변수로 갖는 binary_search함수의 return값 또한 n이라 한다.
							   //즉 재귀함수를 끊어낸 n이 모든 binary_search의 return 값이 된다.
}

int main(void)
{
	/*
	자료형을 unsigned long이 아닌 long long으로 한 이유는
	unsinged long의 최대 범위는 4,294,967,295가 되는데 
	만약 s가 4,294,967,295라면 for반복문은 AP의 값이 4,294,967,295이상 일때 중단하게된다.
	하지만 범위가 unsigned long이라면 4,294,967,295이상의 값을 갖지 못하고 
	이상한 값으로 작아져서 무한루프를 돌기에 자료형을 long long으로 한 것이다.
	*/
	long long n;
	long long s;
	scanf("%lld",&s);
	n=binary_search(s,s);
	for(;AP(n)<=s;n++);
	printf("%lld",n-1);
	return 0;
}

