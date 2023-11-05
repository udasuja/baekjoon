/*
입력된 메시지는 각 문자가 세 번째 등장할 때 한 번 더 문자가 삽입된다
예를 들면 요원이 "HELLOTHEREWELLBEFINE" 라는 메시지를 보내고 싶어 했다면 
"HELLOTHEREEWELLLBEFINEE" 는 정확한 변형이다.
한 번 더 삽입된 문자는 즉 4번째 대문자는 소문자로 표현된다.
(3의 배수 번 나온 문자는 없다.)  
HELLOTHEREEWELLLBEFINEE는
HELLOTHEREeWELLlBEFINEe가 된다.

어떤 문자가 3번의 배수만큼 나온지를 확인하고 그런 문자가 있으면 fake출력
*/
#include <stdio.h>

int main(void)
{
	int textcase;
	int str = 0, c, fourth = 0;
	scanf_s("%d", &textcase);
	c = getchar();
	//c변수는 textcase에서 저장되지 않는 \n입력을 없애기 위해서이다.
	while (textcase)
	{
		int charater[27] = { 0 };
		int fal = 0, tru=0,count = 0;
		do
		{
			int number;
			str = getchar();
			number = (int)(str - 'A');

			if (number >= 0)
			{
				charater[number] += 1;
				//알파벳에 해당하는 요소에 1를 추가하여 어떤 알파벳이 입력되었는지 알 수 있다.
			}
			if (count)
			{
				if (str == fourth)
				{
					tru=1;
					count = 0;
					charater[number] = 0;
				}
				else
				{
					fal = 1;
				}
			}
			if (charater[number] / 3 == 1)
			{
				count = 1;
				fourth = str;
			}
		} while (str != '\n');//입력이 \n(엔터)이라면 반복을 종료한다.
		if (fal == 0&&tru==1)
		{
			printf("OK\n");
		}
		else if (fal == 1)
		{
			printf("FAKE\n");
		}
		textcase--;
	}

	return 0;
}