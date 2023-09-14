#include <stdio.h>

int main(void)
{
	int arr[5][16];//5X16인 행렬 5행 16열
	//문제에서는 한 줄당 15문자만 입력 가능하지만 \n문자를 고려해서 열은 16개이다. 
	int lastcolumn=0;
	int del[5] ;
	for (int i = 0; i < 5; i++)
	{
		int n = 0;
		arr[i][n] = getchar();
		for (n = 1;n < 16 && arr[i][n-1] != '\012'; n++)
//n번째 열이 15이하이고 마지막으로 입력한 문자가 \n문자가 아닐때 코드실행
		{
			arr[i][n] = getchar();
			if (lastcolumn <= n)
			{
				lastcolumn = n;//입력한 행렬중 가장큰 열을 저장한다.
			}
		}
	}
	for (int n = 0; n < 16 && lastcolumn>n ; n++)
//n이 14이하이고 가로로 가장 긴 행에 입력된 열보다 작은 열일때만 실행
	{
		for (int i = 0; i < 5; i++)
		{
			while (arr[i][n] == '\12' || i == del[i])
//i,n번째 요소가 \n이던지 i번째 행이 삭제된 행이라면 밑을 실행
			{
				del[i] = i;
				//arr의 i번째 행을 del의 i번째 요소에 저장하여
				//arr의 i번째 행을 출력 행에서 제외한다.
				i++;
			}
			if (i <= 4)
//위 반복문에서 i++후 i값이 4보다 클 수도 있기에 i값이 4보다 크면 출력을 하지 않는다.
			{
				printf("%c", arr[i][n]);
			}

		}
	}
	return 0;
}