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
	int c,lastnumber=-1;
	scanf_s("%d", &textcase);
	c = getchar();
	//scanf를 이용하여 입력할 때는 마지막에 '\n'가 입력버퍼에 남아있을 텐데 그것을 없애는 역할 
	while (textcase)
	{
		int charater[26] = { 0 };
		int fal = 0,str=0,compare=0;
		while (str!='\n')
		{
			int number;
			str = getchar();
			number = (int)(str - 'A');
			if (compare == str && charater[lastnumber] == -1)
			//N-1번째의 문자가 3번 입력을 받았을 때 N번째 문자가 그 문자랑 같으면
			{
				compare = 0;
				//비교할 문자을 초기화한다.
			}
			else if (charater[lastnumber] == -1)
			//N-1번째의 문자가 3번 입력을 받았는데 N번째 문자가 그 문자랑 다르면
			{
				fal = 1;
				//fal이 1이면 이 메시지가 거짓이라는 것이다.
			}
			if (number >= 0)
			//입력받은 문자가 대문자일때 널문자라면 number이 음수가 될 것이다.(아스키코드 값이 널문자가 더 작으니)
			{
				charater[number] += 1;
				//그 알파벳이 나오면 1증가한다.
			}
			if (charater[number] == 3)
			//같은 문자가 3번나오면
			{
				compare = str;
				lastnumber = (int)(compare - 'A');
				charater[number] = -1;
				//다음 나올 문자가 이번에 나올 문자와 같으면 그 문자가 나온횟수는 0이될 것이다.
				//charater[number]+=1;에 의해서 
			}
		}
		if (fal == 1)
		{
			printf("FAKE\n");
		}
		else
		{
			printf("OK\n");
		}
		textcase--;
	}

	return 0;
}