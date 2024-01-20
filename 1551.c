/*
크기가 N인 수열 A가 주어졌을 때, 세준이는 인접한 두 원소의 차이를 이용해서 크기가 N-1인 수열 B를 만들 수 있다.
예를 들어, A = {5, 6, 3, 9, -1} 이었을 때, B = {6-5, 3-6, 9-3, -1-9} = {1, -3, 6, -10}이 된다. 즉, B[i] = A[i+1]-A[i]가 된다.
이 짓을 k번 했을 때의 수열 B를 출력하시오
입력: A수열의 길이, k번 반복
	  A수열(이때 수열의 숫자는 ,(쉼표)로 구분된다.)=>현 코드에서는 조건을 구분하지 못했다.

풀이:
문자열을 입력받고 ,를 기준으로 문자열을 쪼개고 그 숫자만 남은 문자열은 atoi()함수로 정수형태로 바꾼다.
atoi("100")이면 정수100이 반환된다.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(int* arr,int,int);

int main(void)
{
	int n,num_r;
	int* arr;
	int i,j=0;
	int last_comma=0;//마지막으로 나온 쉼표의 위치를 저장함
	char arr_str[2020];//20개의 숫자가 모두 100일때 ,랑 널문자 포함해서 최대 2020개의 char메모리가 있어야됨


	scanf_s("%d %d", &n, &num_r);
	arr = (int*)malloc(sizeof(int) * n);
	scanf_s("%s", arr_str,sizeof(arr_str));
	
	for (i = 0; arr_str[i] != '\0'; i++)//널문자가 나오기 전까지 반복한다.
	{
		char num_str[5];//-100이라는 문자까지 커버치기 위해서는 저장 가능한 문자의 개수는 5개가 되야된다.(널문자 포함)
		if (arr_str[i] == ',')//i번째 문자가 ,일때 last_comma번부터 i-1번까지의 정수형문자를 num_str에 저장한다.
		{
			int k;
			for (k = 0; last_comma < i; k++,last_comma++)
			{
				num_str[k] = arr_str[last_comma];
			}
			num_str[k] = '\0';//문자열이 되기위해 맨오른쪽에 널문자를 삽입하였다.
			last_comma++;//,다음에 존재하는 숫자의 맨 왼쪽의 숫자를 가리킨다.
			arr[j++] = atoi(num_str);
		}
		else if (arr_str[i + 1] == '\0')//다음문자가 널문자라면
		{
			int k = 0;
			while (last_comma < i + 1)
			{
				num_str[k++] = arr_str[last_comma++];
			}
			num_str[k] = '\0';
			arr[j] = atoi(num_str);
		}
	}
	func(arr,n,num_r);
	free(arr);
	return 0;
}

void func(int* arr,int n,int num_r)
{
	int i = 0;
	if (num_r == 0)
	{
		printf("%d", arr[i++]);
		while (i < n)
		{
			printf(",%d", arr[i++]);
		}
		return;
	}

	while (i < n-1)//배열은 0부터 시작하므로 n개의 정수를 사용하고 싶으면 n-1까지 반복되야된다.
	{
		arr[i] = arr[i + 1] - arr[i];
		i++;
	}
	arr[i] = 0;//반복문이 끝나면 i는 n-1이 될 것이고 그 요소의 값을 0으로 만든다.(수열 B는 수열 A보다 길이가 1만큼 짧으므로)
	func(arr, n - 1, num_r - 1);//num_r이 0이 될 때 수열 B를 만들며 반복한다.
}