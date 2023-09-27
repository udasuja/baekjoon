/*
친구를 초대하는데 주인공과 a가 친구라면 a의 친구 b까지는 데려올 수 있다.
동기의 수는 500이하,리스크의 길이는 10000이하다.


list의 첫번째 입력배열을 k라하고 두번째 입력배열을 o라고 한다.
배열의 순서에 따라 저장하고
그 중 1과 친구인 친구를 따로 배열에다가 저장한다.

입력
1.동기의 숫자
2.리스트의 길이

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
	int list, friend_member;
	int* fri;//friend라는 변수를 int형이며 int형 메모리크기가 500개 있는 배열로 만들어준다.
	int* fri_of_friend;
	int friend_num = 0;
	int k = 0;

	scanf_s("%d %d", &friend_member, &list);//list의 길이를 설정한다.
	human.a= (int*)malloc(sizeof(int) * friend_member);
	human.b= (int*)malloc(sizeof(int) * friend_member);
	fri = (int*)malloc(sizeof(int) * friend_member);
	fri_of_friend = (int*)malloc(sizeof(int) * friend_member);
	//주인공의 숫자를 설정한다.
	for (int i = 0; i < list; i++)
	{

		scanf_s("%d %d", &human.a[i], &human.b[i]);
		if ((human.a[i] != human.b[i]) && (human.a[i] <= friend_member && human.b[i] <= friend_member))
		//human.a랑human.b가 서로 같지 않고 이 둘의 값이 동기의 최대 크기 이하일때
		{
			if (human.a[i] == 1 || human.b[i] == 1)
				//human.a나 human.b가 주인공이라면 human.b 나 human.a는 주인공의 친구가된다.
			{
				if (human.a[i] == 1)
				{
					fri[human.b[i]] = human.b[i];
					//human.b와 같은 인자를 갖는 friend배열의 값에 human.b를 대입한다.
				}
				else
					//human.b가 주인공일때 human.a는 주인공의 친구가된다.
				{
					fri[human.a[i]] = human.a[i];
				}
			}
		}
	}
	for (int i = 0; i < friend_member; i++)
	//동기의 수만큼 반복한다.
	{
		while (k < list)
		//친구의 친구를 찾기위한 반복문이다.
		{
			if (fri[human.a[k]] == human.a[k] || fri[human.b[k]] == human.b[k])
				//human.a[i]==4 라면 fri의 4번째 요소에 4가 있으면 주인공의 친구라는 것이다.
			{
				if (fri[human.a[k]] == human.a[k] && fri[human.b[k]] == human.b[k])
				//fri에 각 요소에 둘다 값이 있으면 주인공의 친구라는 것이기에
				//k에 1를 더해 반복문의 처음부터 시작한다.
				{
					k++;
					continue;
				}
				else if (fri[human.a[k]] == human.a[k])
				{
					fri_of_friend[human.b[k]] = human.b[k];
					//친구의 친구도 fri배열에 저장한다.
				}
				else if(fri[human.b[k]]==human.b[k])
				{
					fri_of_friend[human.a[k]] = human.a[k];
				}
			}
			k++;
		}
		if (fri[i] != NULL || fri_of_friend[i]!=NULL)
		{
			friend_num++;
		}
	}
	free(fri);
	printf("%d", friend_num);
	return 0;
}