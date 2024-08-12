/*
 * n을 입력했을 때 2^n X 2^n 행렬이 구성이 된다.(이때 행렬의 번호는 0부터 시작한다.)
 * 그리고 이 행렬을 2^(n-1) X 2^(n-1)행렬로 4등분한다.
 * 좌상단부터 우상단, 좌하단, 우하단으로 이어진다.
 *
 * 풀이는 2^n X 2^n행렬을 4등분한뒤 좌상단의 행렬에 접근한다.
 * 2 X 2행렬 단위로 맨 좌측 상단부터 우측방향으로 이동하면서 방문한다.
 * 그러다가 (r,c)에 도달하면 종료한다.
 *
 * algorithm:
 * 2^(n-1)계산
 * c가 2^(n-1)보다 작으면 (r,c)가 4등분 기준 좌측에 있는 것이다.
 * 	r이 2^(n-1)보다 작으면 아무런 연산도 안할 것이다.
 * 	r이 2^(n-1)보다 크면 좌하단에 있는 것이므로 ->2^(n-1)*2*2^(n-1)을 sum에 더한다.
 * 		이때는 r을 2^(n-1)만큼 뺀다.(계산의 편의성을 위해)
 * c가 2^(n-1)보다 크면 (r,c)가 4등분 기준 우측에 있는 것이다.
 * 	r이 2^(n-1)보다 작으면 우상단에 있는 것이므로->2^(n-1)*2^(n-1)을 sum에 더한다.
 * 		이때는 c을 2^(n-1)만큼 뺀다.(계산의 편의성을 위해)
 * 	r이 2^(n-1)보다 크면 우하단에 있는 것이므로 -> 2^(n-1)*3*2^(n-1)을 sum에 더한다.
 * 		이때는 c을 2^(n-1)만큼 뺀다.(계산의 편의성을 위해)
 * 		이때는 r을 2^(n-1)만큼 뺀다.(계산의 편의성을 위해)
 *
 * r과 c는 0부터 시작하여 2^(n-1)까지의 값을 갖게된다.
 * r을 2로 나눴을 때 나머지가 1이 나오면 sum에 2^(n-1)*(r-1)을 곱하고 2를 더한다.
 * r을 2로 나눴을 때 나머지가 0이 나오면 sum에 2^(n-1)*r을 더한다.
 * num=0
 * for(i=0;i<c;i++)
 * 	if(num==0)
 * 		sum+=1
 * 		num=1
 * 	else
 * 		sum+=3
 * 		num=0
 *
 *
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, r, c;
	int sum = 0, row, col, square, num = 0, i;
	scanf("%d %d %d", &n, &r, &c);
	square = (int)pow(2.0, (double)(n - 1));//2^(n-1)계산

	if(c<square)
	{
		if(r>square)
		{
			sum+=square*square*2;
			r-=square;
		}
	}
	else
	{
		if(r<square)
		{
			sum+=square*square;
			c-=square;
		}
		else
		{
			sum+=square*square*3;
			r-=square;
			c-=square;
		}
	}
	if(r%2==0)
	{
		sum+=square*r;
	}
	else
	{
		sum+=square*(r-1);
		sum+=2;
	}

	for (i = 0;i < c;i++)
	{
		if (num == 0)
		{
			sum += 1;
			num = 1;
		}
		else
		{
			sum += 3;
			num = 0;
		}
	}
	printf("%d", sum);

}

