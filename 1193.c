/*
 * 무한히 큰 배열에 다음과 같이 분수들이 적혀있다.
 *
 * 1/1	1/2	1/3	1/4	1/5	…
 * 2/1	2/2	2/3	2/4	…	…
 * 3/1	3/2	3/3	…	…	…
 * 4/1	4/2	…	…	…	…
 * 5/1	…	…	…	…	…
 * …	…	…	…	…	…
 * 이와 같이 나열된 분수들을 1/1 → 1/2 → 2/1 → 3/1 → 2/2 → 1/3->1/4->2/3->3/2… 과 같은 
 * 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, 6번, 7번, 8번, 9번, … 분수라고 하자.
 * (if you draw graph then you can find relation)
 * X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.
 *
 * 입력
 * 첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다.
 *
 * 출력
 * 첫째 줄에 분수를 출력한다.
 *
 * algorithm:
 * 1.분자가 1이면 분모를 1더한다.
 * 1-1.그다음 분자를 1씩 더하면서 분모를 1감소시킨다.
 * 2.분모가 1이되면 분자를 1더한다.
 * 2-1.그다음 분자를 1씩 감소하면서 분모를 1증가시킨다.
 * 과정 1.이 될 때까지 반복한다.
 */
#include <stdio.h>

int main(void)
{
	int n;
	int denom=1,mole=1;//각각 분모와 분자를 뜻함
	int re_2=0;//re_2가 1이면 과정2가 행해지는 것을 뜻함
	int re_3=1;//re_3가 1이면 과정 3이 행해지는 것을 뜻함
	scanf("%d",&n);
		
	while((n--)>1)
	{
		if(mole==1&&re_3==1)//분자가 1인 경우 과정 1진행,과정 2-1가 되는 경우를 생각하여 re_3==1일때도 진행
		{
			denom+=1;
			re_3=0;
			re_2=1;
		}
		else if(denom==1&&re_2==1)//과정 2진행이 과정은 1-1인 경우와 2가 동시에 작동될때 벌어짐
		{
			mole+=1;
			re_2=0;
			re_3=1;
		
		}
		else if(re_2==1)//과정 1-1진행
		{	
			mole+=1;
			denom-=1;
		}
		else if(re_3==1)//과정 2-1진행
		{
			mole-=1;
			denom+=1;
		}
	

	}
	printf("%d/%d",mole,denom);
	return 0;
}
			

