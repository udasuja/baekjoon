/*
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만, 
{1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.
수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.
커졌다가 중간을 기준으로 작아져야된다.
수열에서 수의 개수가 짝수면 n/2와 (n/2)+1중에서 n/2가 더 커야된다.
홀수면 n+1/2을 기준으로 오른쪽으로 갈 수록 한 칸 왼쪽보다 더 작아야된다.
입력:첫째줄=>수열의 크기
	 둘째줄=> 수열

수열을 왼쪽부터 오른쪽으로 순서대로 검사했을 때 가장 큰 수를 찾고 그 수 값이 같고 다른 위치에 있으면 그 위치를 저장한다.
그 큰 수를 기준으로 왼쪽 오른쪽으로 각각 n-1번보다 작은수를 찾고 못찾겠으면 길이를 세는 것을 그만둔다.
그리고 길이 중 가장 큰 값이 출력된다.
이때 수열의 규칙성도 부합해야된다. ("12월 06일"에는 이 규칙성을 부합하지 못하였다.)
*/

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a>b)?a:b)


int main(void)
{
	int n, i = 0, max_num = 0, max1 = 0, max2 = 0;
	int* arr;

	scanf_s("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	while (i < n)
	{
		scanf_s("%d", &arr[i++]);
		max1 = max(arr[i - 1], max1);
	}

	while (i--)
	{
		int lengh = 1;
		if (max1 == arr[i])
		{
			int left = i - 1, right = i + 1;
			int l_check = i, r_check = i;
			int end[2] = { 0 };
			while (1)
			{
				if ((left>=0)&&(arr[left] < arr[l_check]))
				{
					l_check = left;
					lengh++;
				}
				else if (left < 0)
				{
					end[0]++;
				}
				if ((right < n) && (arr[right] < arr[r_check]))
				{
					r_check = right;
					lengh++;
				}
				else if (right > n)
				{
					end[1]++;
				}
				if (end[0] && end[1])
					break;
				right++;
				left--;
			}
		}
		max2 = max(lengh, max2);
	}
	printf("%d", max2);
	free(arr);
	return 0;
}