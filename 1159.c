/*
선수의 수는 최대 150명이고 선수 한 명당 이름은 최대 30자이다. 
선수의 이름 첫 글자만 저장하도록 한다.
*/

#include <stdio.h>

int main(void)
{
	char name[30], first_name[150];
	char albat[26]={0};
	int non_player=0;
	int number;


	scanf_s("%d", &number);

	/*
	for문으로 name의 최대길이는 30자이고 각 선수의 첫글자는
	입력된 순서대로 first_name에 저장된다.
	*/
	for (int i = 0; i < number; i++)
	{
		scanf_s("%s", name,sizeof(name));
		first_name[i] = name[0];
	}

	/*
	첫 번째 선수의 첫글자를 가지고 마지막 선수의 첫글자까지
	모든 선수들을 비교하며 첫 번째 선수와 같은 첫 글자를 갖고 있다면
	그 번호의 선수의 이름을 null로 바꿔주고 카운트를 세준다.
	그리고 선수 이름 대신 null이 나오면 다음 선수로 넘어간다.
	*/
	//a의 아스키코드 값은 97이다.(10진수 기준)
	for (int i = 0; i < number; i++)
	{
		for (int k = i+1; k < number; k++)
		{
			if (first_name[i] != NULL)
			//first_name의 i번째 요소가 NULL인 것은 제외
			//이 조건이 없으면 NULL인것도 알파벳을 세기 때문이다.
			{
				if (first_name[k] == NULL)
				{
					continue;
				}
				else if (first_name[i] == first_name[k])
				//first_name의 i번째 요소와 k번째 요소가 같으면 실행
				{
					albat[(int)first_name[i] - 97] += 1;
					first_name[k] = NULL;
				}
				
			}
			else
			{
				break;
				//반복문 탈출
			}
		}
	}
	/*
	초반 albat의 모든 원소는 0이다. 즉 a를 first_name으로 갖는 사람이
	6명이라고 한다면 비교하는 자신은 포함하지 않고 셈을 세기 때문에
	5명이라고 나온다.
	즉 albat의 원소 중 4 이상을 만족하는 원소가 선발된다.
	*/
	for (int i = 0; i < 26; i++)
	//a~z를 97를 뺀 아스키코드로 표현하면 0~25가된다.
	//이때 non_player값이 25가 된다면 z가 될 때까지 선발 선수가 없다는 것이다.
	{
		albat[i] >= 4 ?printf("%c",i+97) : non_player++;
		non_player == 26 ? printf("PREDAJA") : 0 ;//non값이 26가 되면(i값보다 1크다 즉 i가 25면 non은 26이된다.) 문자열 출력
	}
	return 0;
}