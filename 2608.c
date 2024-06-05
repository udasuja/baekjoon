/*
로마 숫자를 아라비아로 바꾸는 방법은 왼쪽부터 검사하여 왼쪽 문자에 해당하는 숫자가 오른쪽보다 더 크면 바로 합계를 해주지만
그것이 아니라면 오른쪽이 더 크다는 것인데(예:iv,cd) 그것은 오른쪽-왼쪽의 값을 더 해주면 된다.
아라비아 숫자를 로마로 바꾸는 방법은 천의 자리부터 검사하여 그 자리 값에 해당하는 숫자만큼 반복하면 된다.
 IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900는 따로 계산한다.
*/
#include <stdio.h>

int Check_char(char*);
void Roma_number(int);
int main(void)
{
	char arr[2][50];
	int i;
	int sum = 0;

	for (i = 0; i < 2; i++)
	{
		int j;
		fgets(arr[i], sizeof(arr[i]), stdin);
		
		for (j = 0; arr[i][j] != '\n'; j++)
		{
			if (j == 0)
			//문자열의 첫번째 문자는 그냥 합계에 더해준다.
			{
				sum+=Check_char(&arr[i][j]);
			}
			else
			{
				if (Check_char(&arr[i][j - 1]) >= Check_char(&arr[i][j]))
				//왼쪽 문자가 더 큰 경우 혹은 같은 문자가 입력된 경우
				{
					sum += Check_char(&arr[i][j]);
				}
				else
				//오른쪽 문자의 값이 더 큰 경우 IV같이
				{
					sum -= Check_char(&arr[i][j - 1]);
					sum += Check_char(&arr[i][j]) - Check_char(&arr[i][j - 1]);
				}
			}
		}
	}
	printf("%d\n", sum);
	Roma_number(sum);
	return 0;
}

int Check_char(char* arr)
{
	switch (*arr)
	{
	case 'M':
		return 1000;
	case 'D':
		return 500;
	case 'C':
		return 100;
	case 'L':
		return 50;
	case 'X':
		return 10;
	case 'V':
		return 5;
	case 'I':
		return 1;
	default://아무것도 해당하지 않음
		return 0;
	}
}

void Roma_number(int sum)
//아라비아 숫자를 로마 숫자로 바꾸는 함수는 성공
{
	int i = 1000;
	while (i)
	{
		int share = sum / i;//자리수
		if (i == 1000 && share > 0)
		//if문으로 i에 해당하는 sum의 자리수를 찾는다.
		{
			while (share--)//자리수에 해당하는 만큼 반복한다.
			{
				printf("M");
			}
		}
		else if (i == 100)
		{
			switch (share)
			{
			case 9:
				printf("CM");
				break;
			case 8:case 7:case 6:case 5:
				printf("D");//500에 해당하는 문자는 1번만 출력
				while (share - 5)
				{
					printf("C");//share-5번만큼 C출력한다.
					share--;
				}
				break;
			case 4:
				printf("CD");
				break;
			case 3:case 2:case 1:
				while (share--)
				{
					printf("C");
				}
				break;
			}
		}
		else if (i == 10)
		{
			switch (share)
			{
			case 9:
				printf("XC");
				break;
			case 8:case 7:case 6:case 5:
				printf("L");
				while (share - 5)
				{
					printf("X");
					share--;
				}
				break;
			case 4:
				printf("XL");
				break;
			case 3:case 2:case 1:
				while (share--)
				{
					printf("X");
				}
				break;
			}
		}
		else if (i == 1)
		{
			switch (share)
			{
			case 9:
				printf("IX");
				break;
			case 8:case 7:case 6:case 5:
				printf("V");
				while (share - 5)
				{
					printf("I");
					share--;
				}
				break;
			case 4:
				printf("IV");
				break;
			case 3:case 2:case 1:
				while (share--)
				{
					printf("I");
				}
				break;
			}
		}
		sum %= i;
		i /= 10;
	}
}