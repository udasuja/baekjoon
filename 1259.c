/*
최대 5개의 문자가 들어갈 수 있는 배열에다가 숫자를 문자열 형태로 입력한다.
그리고 뒤에서부터 차례대로 그 문자를 배열의 맨 앞의 문자와 비교한다.

*/

#include <stdio.h>

int main(void)
{
	int arr[6];
	while (1)
	{
		int i = 0, k = 0, this_is_true = 0;
		do
		{
			arr[i] = getchar();
			i++;
		} while (arr[i - 1] != '\n');
		if (arr[0] == '0')
		{
			break;
		}
		i -= 2;//위 반복문이 종료되면 i-1에 '\n'이 들어갈 것인데
		//그것은 이 문제에서 의미가 없기에 i에 2를 빼준다.
		while (i >= k)//k도 1씩 증가하고 i도 1씩 감소하므로 중간에서 만나면 반복이 종료되야된다.
			//즉 i의 중간값만큼 반복이 진행되면 끝난다.
		{
			if (arr[k] == arr[i])
			{
				this_is_true++;
			}
			k++;
			i--;
		}
		if (this_is_true == k && k != 0)
		{
			printf("yes\n");
		}
		else if (k != 0)
			printf("no\n");
	}

}