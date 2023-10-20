/*
입력: a
이 a가 10보다 크면 1의 자리에서 반올림 하고 그리고 a가 100보다 크면 10의 자리에서 반올림한 후
a가 1000보다 크면 100의 자리에서 반올림 이것을 반복한다.
*/

#include <stdio.h>

int main(void)
{
	int s_arr[8], i = 0;
	char s;
	while (1)
	{
		s = getchar();//숫자를 문자형태로 입력받는다. 
		if (s == '\n')//만약 엔터키를 입력하면 반복문을 끝낸다.
		{
			break;
		}
		s_arr[i++] = s;
		//i값이 문자열의 길이를 알려준다.
		//ex)345\n고 입력하면 i는 3이라는 값을 갖게된다.
	}
	//밑에는 반올림 및 반내림 알고리즘
	for (int k = i; k > 2; k--)
	{
		if ((int)s_arr[k] >= 5)
		{
			s_arr[k - 1] = (int)s_arr[k - 1] + 1;
		}
		if ((int)s_arr[k - 1] >= 10)
		{
			s_arr[k - 2] = (int)s_arr[k - 2] + 1;
			s_arr[k - 1] = (int)s_arr[k - 1] - 10;
		}
	}

	if (i == 1)
	{
		s_arr[0] <= '4' ? printf("%d", 0) : printf("%d", 10);
	}
	else
	{


		if (s_arr[1] <= '4')
		{
			printf("%d", (int)s_arr[0]);
			while (--i)
			{
				printf("%d", 0);
			}
		}
		else
		{
			if (s_arr[0] == '9')
			{
				printf("%d", 1);
				while (i--)
				{
					printf("%d", 0);
				}

			}
			else
			{
				printf("%d", (int)((int)s_arr[0] + 1));
				while (--i)
				{
					printf("%d", 0);
				}
			}
		}
	}
	return 0;
}