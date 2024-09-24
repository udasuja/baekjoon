/*
L->커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
D->커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
B->커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 
실제로 커서의 오른쪽에 있던 문자는 그대로임
P $->$라는 문자를 커서 왼쪽에 추가함

예제:
	입력
	abcd
	3
	P x     ->top이 4번째 인덱스를 가리키고 거기에 x를 집어넣는다. 그리고 top값을 1증가시킨다. 
	L		->top은 5번째 인덱스를 가리키다가 3번째 인덱스를 가리킨다.
	P y		->top은 4번째 인덱스를 가리키는데 거기에는 x가 저장되었다.
			  그러므로 x를 오른쪽으로 한 칸 옮기고 빈자리에 y를 저장
	출력
	abcdyx


	입력
	abc
	9
	L->top은 3을 저장했는데 L 때문에 2를 저장
	L->top은 1를 저장
	L->top은 0을 저장
	L->top은 -1를 저장하여 왼쪽 끝에 다달았다는 것을 의미함
	L->여전히 top은 -1이다.
	P x->top은 -1이므로 0번째부터 모든 문자를 오른쪽으로 한 칸 옮긴다.
		 그리고 0번째에 x를 집어넣고 top를 1증가시킨다.
	L ->top은 0이므로 -1로 만든다.
	B ->top이 -1이므로 아무것도 제거되지 않는다.
	P y -> top은 -1이므로 0번째 이후 문자를 오른쪽으로 옮기고, 0번째에 문자를 넣는다.
	출력
	yxabc

	입력
	dmih
	11
	B  ->dmi
	B  ->dm
	P x->dmx
	L  ->top은 m를 가리킴
	B  ->dx
	B  ->x
	B  ->x
	P y->yx
	D   
	D
	P z

	출력
	yxz

top은 배열의 인덱스를 가리키고 왼쪽의 값을 해당 인덱스로 인식하고
오른쪽의 값은 1증가된 인덱스를 인식하도록 한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 600001

int main(void)
{
	int top,n;
	char arr[SIZE];
	scanf("%s", arr);
	top = strlen(arr)-1;//널문자 바로 앞에 있는 index값으로 초기화한다.->가장 오른쪽에 위치하도록 함

	scanf("%d", &n);
	getchar();
	while (n--)
	{
		char comm[5];//L,D,B,P &를 저장하는 배열
		fgets(comm, 5, stdin);
		switch (comm[0])
		{
		case'L':
			top -= top == -1 ? 0 : 1;//top이 -1이라면 왼쪽 끝에 다달았다는 것이다.
			break;
		case'D':
			top += top == strlen(arr)-1 ? 0 : 1;//top이 널문자 바로 앞에 있는 index값이라면 가장 오른쪽에 있는 것이다.
			break;
		case'B':
			if (top != -1)
			{
				int left = top, right = top + 1;
				while (arr[right] != '\0')
				{
					arr[left] = arr[right];//오른쪽에 있는 모든 문자를 다 왼쪽으로 한 칸씩 옮긴다.
					left++;
					right++;
				} 
				arr[left] = arr[right];//널문자도 한 칸 왼쪽으로 이동시킨다.
				top--;//문자를 지웠으므로 커서는 한 칸 왼쪽으로 이동된다.
			}
			break;
		case'P':
		{
			int left = strlen(arr), right = strlen(arr)+1;
			while (left != top)
			{
				arr[right] = arr[left];
				left--;
				right--;
			}
			arr[++top] = comm[2];
		}
		}
	}
	printf("%s", arr);
}