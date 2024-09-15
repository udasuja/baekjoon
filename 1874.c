/*
예를 살펴보며 문제에 대해 설명하겠다.

입력:
8 -> n값
4
3
6
8
7
5
2
1

먼저 1부터 4까지의 값을 스택에 넣는다.-> +가 4번 나옴
그 다음 4가 수열에 첫번째 자리에 있으므로 스택에서 4를 pop했다.-> -가 1번 나옴
3이 수열에 두번째 자리에 있으므로 스택에서 3를 pop했다. -> -가 1번 나옴
6이 수열에 세번째 자리에 있으므로 스택은 5와 6을 push했다. 그리고 6를 pop했다. -> +가 2번 나오고 -가 1번 나옴
8이 수열에 네번째 자리에 있으므로 스택은 7과 8을 push했다. 그리고 8를 pop했다. -> +가 2번 나오고 -가 1번 나옴
7이 수열에 다섯번째 자리에 있으므로 스택은 7를 pop했다. -> -가 1번 나옴

linked list를 구현하여 +혹은 -를 element에 집어넣는다.
이때 arr[i]의 값에 대한 stack배열 인덱스 한 칸 앞의 값이 1이면 NO를 출력하고 프로그램을 종료한다.

배열을 2개 구현한다. 그리고 linked list를 구현한다.
하나는 arr로 다른 하나는 스택으로 구현한다.
스택에는 k값을 차례대로 집어넣는다.
그리고 top를 이용하여 스택에 얼마나 들어왔는지 저장한다.
push를 통해 k값과 top값을 증가시키고 스택에 넣고 linked list에는 +를 집어넣는다.
그리고 pop를 통해 top값을 감소시키고 스택에서 값을 제거시킨다. 만약 pop하는 값이 top인덱스에 있는 값이 아니면 NO를 출력하고 종료한다.
push pop 반복문을 끝내면 linked list에 저장된 +를 출력한다. 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	char c;
	struct node* link;
}node;

int main(void)
{
	int i,n,k=0;
	int* stack, * arr;
	int top = -1;
	node* first=NULL;

	scanf("%d", &n);
	stack = (int*)malloc(sizeof(int) * n);
	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}


	for (i = 0; i < n; i++)
	{
		while (k < arr[i])//i번째 값이 이전 값보다 크면 push를 진행함
		{
			node* new_node = (node*)malloc(sizeof(node));
			top++;//스택의 인덱스에 해당
			k++;//스택에 들어갈 값에 해당
			stack[top] = k;
			new_node->c = '+';
			new_node->link = first;//first가 가리키는 것을 new_node가 가리키고
			first = new_node;//first는 동적할당된 새로운 node를 가리킨다.
	//		printf("k: %d, top: %d, stack[top]: %d ", k, top, stack[top]);
		}
	//	printf("\n");
		if (stack[top] != arr[i])//만약 i번째 값이 이전 값보다 작으면 위 반복문을 실행하지 않는데, top번째 값이랑 다르면 스택에 맨 위에 값이 아니라는 것이다.
		{
			printf("NO\n");
			return 0;
		}
		else 
		{
			node* new_node = (node*)malloc(sizeof(node));
			new_node->c = '-';
			new_node->link = first;
			first = new_node;
			stack[top] = 0;//초기화
			top--;//가리키는 인덱스를 하나 감소시킨다.
		}
	}
	reflexive(first);

}