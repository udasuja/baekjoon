/*
 * 지민이는 길이가 64cm인 막대를 가지고 있다. 
 * 어느 날, 그는 길이가 Xcm인 막대가 가지고 싶어졌다. 
 * 지민이는 원래 가지고 있던 막대를 더 작은 막대로 자른다음에, 
 * 풀로 붙여서 길이가 Xcm인 막대를 만들려고 한다.
 *
 * 막대를 자르는 가장 쉬운 방법은 절반으로 자르는 것이다. 
 * 지민이는 아래와 같은 과정을 거쳐서 막대를 자르려고 한다.
 *
 * 1.지민이가 가지고 있는 막대의 길이를 모두 더한다. 
 * 	처음에는 64cm 막대 하나만 가지고 있다. 
 * 	이때, 합이 X보다 크다면, 아래와 같은 과정을 반복한다.
 * 1-1.가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다.
 * 1-2.만약, 위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이의 합이 X보다 크거나 같다면, 
 * 	위에서 자른 막대의 절반 중 하나를 버린다.
 * 2.이제, 남아있는 모든 막대를 풀로 붙여서 Xcm를 만든다.
 *
 * X가 주어졌을 때, 위의 과정을 거친다면, 
 * 몇 개의 막대를 풀로 붙여서 Xcm를 만들 수 있는지 구하는 프로그램을 작성하시오. 
 *
 * 입력
 * 첫째 줄에 X가 주어진다. X는 64보다 작거나 같은 자연수이다.
 *
 * 출력
 * 문제의 과정을 거친다면, 몇 개의 막대를 풀로 붙여서 Xcm를 만들 수 있는지 출력한다.
 *
 * 즉 문제는 64를 반 쪼개고 하나는 남기고 하나는 또 반 짜른다.그리고 그 반을 32에 더해 x가 나올때 까지 이를 반복
 *
 * 예제 입력 
 * 23
 * 예제 출력  
 * 4
 *
 * 어차피 2^6=64이고 2로 나누어 2^n중 n<=6인 막대의 길이의 합을 조합하여 x를 만든다.
 * 이때 겹치는 막대의 길이는 없다.
 *
 * 현재 이 코드의 입력이 23에 대한 출력이다.
 *23
 23 32
 23 8
 7 1
 2
 */
//n>>k를 이용하여 n을 2로 k번 나눈다.
#include <stdio.h>

int main(void)
{
	int x,n=64;
	int i;
	int sh,re;
	int sum=0;
	scanf("%d",&x);
	
	for(i=1;x!=0;i++)
	{
		re=x%n;
		if(re==0)//x를 n으로 나눴을 때 딱 떨어지면 그 막대로 x를 커버 가능하다.
		{
			sum+=1;
			break;
		}
		else if(re<x)//x%n이 x보다 작으면 n이 x보다 작다는 것이다.
		{
			sum+=1;//그럼 그 길이의 막대가 결과에  포함된다는 것이다.

		}
		x=re;
		n=n>>i;
		printf("%d %d\n",x,n);

	}
	printf("%d",sum);

}
