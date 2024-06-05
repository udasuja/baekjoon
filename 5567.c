/*
첫 번째 반복문에는 주인공의 친구를 특정배열에다가 저장한다.
저장방법은 특정배열에 주인공의 친구와 같은 요소번호에다가 주인공의 친구의 값을 저장한다.
ex)1 4라고 하면 4는 주인공의 친구이기에 fri[4]==4가 된다.
두번째 반복문에는 친구가 들어있는 행이 있으면 friend_num에 1을 더해준다.(=주인공 결혼식의 하객의 개수를 의미)
*/

#include <stdio.h>
#include <stdlib.h>

struct human
{
	int* a;
	int* b;
}human;

int main(void)
{
	int friend_member, list;
	int* friend_of_protagonist;
	int friend_num = 0;

	scanf_s("%d %d", &friend_member, &list);
	human.a = (int*)malloc(sizeof(int) * list);//int형 자료형을 저장할 수있는 메모리 크기가 4바이트 * friend_member인 배열
	human.b = (int*)malloc(sizeof(int) * list);
	friend_of_protagonist = (int*)malloc(sizeof(int) * (friend_member+1));
	
	for (int i = 0; i < list; i++)
	{
		int a,b;
		scanf_s("%d %d", &human.a[i], &human.b[i]);
		a = human.a[i];//a열의 i번째 값을 변수a에 저장
		b = human.b[i];//b열의 i번째 값을 변수b에 저장

		if (a < b)
		{
			if (a == 1)
			{
				if (b != 1 && friend_of_protagonist[b] != b)
					//a가 1이고 b가 1이 아니면 배열의 b요소에 b의 값을 집어넣는다.
					//그리고 배열에 b요소에 b값이 없는 경우에 실행한다.
					//있으면 b라는 값은 이미 하객수에 포함이 되어있기에 제외한다.
				{
					friend_of_protagonist[b] = b;
					friend_num++;
				}
			}
		}
	}
	//위 반복문으로 주인공의 친구를 다 배열에다가 집어넣었다.
	//그리고 주인공의 친구를 하객수에 포함하였다.
	//밑의 반복문은 주인공의 친구의 친구를 구하는 반복문이다.
	for (int i = 0; i < list; i++)
	{
		int a = human.a[i], b = human.b[i];
		if (friend_of_protagonist[a] > 0 || friend_of_protagonist[b] > 0)
		//배열에 양수가 있다면 i번째 행에 주인공의 친구가 있다는 뜻이다.
		{
			if (friend_of_protagonist[a] == a && friend_of_protagonist[b] == b)
			//둘다 값을 갖는다면 중복되어 친구의 수를 더하는 것이기에 이 행은 제외한다.
			{
				continue;
			}
			else if(a!=1&&b!=1)
			//a값과 b값모두 1이 아닌경우
			//else라는 것은 하나만 i번째 행의 2개의 열 중 하나의 열만 값을 갖는다는 것이기에
			//하객의 수에 1을 추가한다.
			{
				friend_num++;
			}
		}

	}
	free(human.a);
	free(human.b);
	free(friend_of_protagonist);
	printf("%d", friend_num);
	return 0;
}