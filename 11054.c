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

숫자를 입력받고
모든 숫자를 검사한다.
왼쪽이나 오른쪽으로 갈때 기준이 되는 숫자보다 작으며 그 중에서 가장 큰 값을 찾고 큰 값이 두개면 기준이 되는 숫자와 가까운 숫자의 길이를 젠다
그리고 기준이 되는 숫자를 방금 찾은 그 숫자로 대체한다 다시 윗부분을 반복해 왼쪽으로는 
배열 요소가 0이 될때까지 오른쪽으로는 배열 요소가 n-1이 되도록 한다 또는 왼쩍 오른쪽 모두 최소값을 다 찾은 경우에 길이를 제는 것을 종료
틀린이유=> 입력:(7, 1 6 7 2 3 4 5) 답 :4 내 프로그램: 5출력 

*/
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b

int L_check(int, int*,int);//왼쪽만 검사한다.(이때 함수에 arr배열 이름에 해당하는 주소값을 줘서 함수내에서도 arr배열을 이용할 수 있도록 한다.)
int R_check(int, int*,int,int);//오른쪽만 검사한다.

int main(void)
{
	int n, i, max1 = 0, max2 = 0;
	int* arr;

	scanf_s("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		int lengh = 1;
		lengh += L_check(arr[i], arr, i);
		printf("<=left\n");
		lengh += R_check(arr[i], arr, i, n);
		printf("<=right\n");
		
		max2 = max(max2, lengh);
	}
	printf("\n%d", max2);
}

int L_check(int max_l, int* arr,int i)
{
	int k,num=0,element=0,lengh=0;
	int num1 = 0;
	int left = i;
	while (1)
	{
		for (k = left-1; k >= 0; k--)
		{
			num = arr[k] < max_l ? max(arr[k], num) : num;//max_l(기준이 되는 숫자)보다 작으면서 기준이 되는 숫자를 제외하고 가장 큰 수
			element = num == arr[k]&&arr[k] != arr[element] ? k : element;//그리고 max로 계산 했을 때num보다 arr[k]값이 크면 num==arr[k]이 되므로 element에 k를 집어넣는다.
		}
		if ((num1!=0 && left == element)||num==0)
		{
			break;
		}
		else
		{

			printf("%d", num);
			max_l = num;
			left = element;
			num =  0;
			num1 = 1;
			lengh++;
		}
	}
	return lengh;
}
int R_check(int max_r, int* arr, int i,int n)
{
	int k, num = 0, element = 0, lengh = 0;
	int num1 = 0;
	int right = i;
	while (1)
	{
		for (k = right + 1; k<n; k++)
		{
			num = arr[k] < max_r ? max(arr[k], num) : num;//max_r(기준이 되는 숫자)보다 작으면서 기준이 되는 숫자를 제외하고 가장 큰 수
			element = num == arr[k]&& arr[k]!=arr[element] ? k : element;//그리고 max로 계산 했을 때num보다 arr[k]값이 크면 num==arr[k]이 되므로 element에 k를 집어넣는다.
			//arr[k]!=arr[element]는 arr[k]최대값으로 되었을때 전의 최대값은 arr[element]와 같으면 먼저 나온 것을 저장하기 위해서 쓴 코드다.
		}
		if ((num1 != 0 && right == element)||num==0)
		{
			break;
		}
		else
		{	
			printf("%d", num);
			max_r = num;
			right = element;
			num = 0;
			num1 = 1;
			lengh++;
		}
	}
	return lengh;
}