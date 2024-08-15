/*
 * r1은 x1과 y1가 중점인 원의 반지름이다.
 * r2는 x2과 y2가 중점인 원의 반지름이다. 
 * 즉 두 원의 둘레가 겹치는 부분의 점이 류재명이 있을 수 있는 위치의 개수다.
 *
 * algorithm:
 * 두 원의 중점이 같고 반지름이 같으면 -1출력
 * 두 원의 중점이 다를때
 * 	중점의 거리를 구한다.
 * 	그 거리가 두 원의 반지름의 합보다 크면
 * 		0출력
 * 	작으면 
 * 		2출력
 * 	같으면 
 * 		1출력한다.
 */
#include <stdio.h>
#include <math.h>

long long distance(int x1,int y1,int x2,int y2)
{
	int x_co,y_co;
	x_co=(x1-x2)*(x1-x2);
	y_co=(y1-y2)*(y1-y2);
	return (x_co+y_co);//편의상 중점간의 거리를 제곱한 것으로 계산한다.
}

int main(void)
{
	int n;
	int x1,y1,r1,x2,y2,r2;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		if((x1==x2)&&(y1==y2)&&(r1==r2))
		{
			if(x1==0)
				printf("1\n");
			else
				printf("-1\n");
		}
		else
		{
			long long dist=distance(x1,y1,x2,y2);
			long long r_sum=(r1+r2)*(r1+r2);
			if(dist>r_sum)
				printf("0\n");
			else if(dist<r_sum)
			{
				if(dist==r1||dist==r2)//두 점 사이의 거리가 반지름과 같으면
						      //두 원의 둘래는 한점에서 만남
					printf("1\n");
				else if(dist>r1&&dist>r2)//두 점 사이의 거리보다 두 원의 반지름이 모두 작으면
					printf("2\n");
				else
					printf("0\n");
			}
			else//거리와 반지름이 같은 경우에도 여러 상황이 존재한다.
			{

				printf("1\n");
			}
		
		}
	}
	return 0;
}
