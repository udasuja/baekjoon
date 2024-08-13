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
 *위 코드를 (r,c)에 도달할 때까지 반복한다.
 *
 *
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, r, c;
	int sum = 0,square, i;
	scanf("%d %d %d", &n, &r, &c);
	for(i=1;i<=n;i++)
	{
		square = (int)pow(2.0, (double)(n - i));//2^(n-i)계산하고 이 값이 1이 되때까지 반복한다.

		if(c<square)
		{
			if(r>=square)//r은 0부터 시작하므로 r이 square보다 크거나 같을때 좌하단에 걸린다.
			{
				sum+=square*square*2;
				r-=square;
			}
		}
		else//c는 0부터 시작하므로 c가 square보다 크거나 같을때 우상단,우하단에 걸린다.
		{
			if(r<square)
			{
				sum+=square*square;
				c-=square;
			}
			else//r이 0부터 시작하므로 r이 square보다 크거나 같을때 우하단에 걸린다.
			{
				sum+=square*square*3;
				r-=square;
				c-=square;
			}
		}
	}
	printf("%d", sum);

}

