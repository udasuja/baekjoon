/*
배열의 크기는 600000로 한다.
top은 strlen(문자열)-1의 값으로 초기화한다. (top=strlen(문자열)-1)

L-> top값을 1만큼 줄임 (0이면 감소시키지 않음->top-= top==0?0:1;)
D-> top값을 1만큼 증가(strlen(문자열)-1이면 증가시키지 않음)
B-> top에 해당하는 인덱스를 제거한다. top오른쪽에 있는 모든 문자열을 왼쪽으로 1칸 이동
P $-> top를 1증가시키고 그 자리에 $라는 문자를 집어넣는다. 만약 그 top자리에 문자가 이미있으면 모든 문자를 오른쪽으로 1칸 이동후 집어넣는다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 600001

int main(void)
{
	char arr[SIZE];
	int top,n;
	scanf("%s", arr);
	top = strlen(arr);

	scanf("%d", &n);
	getchar();
	while (n--)
	{
		char ch,c;
		scanf("%c", &ch);
		getchar();//L,D,B를 입력했을때 입력버퍼에 남는 \n를 없애고 P를 입력했을때의 스페이스 문자를 없앤다.
		switch (ch)
		{
		case 'L':
			top -= top == 0 ? 0 : 1;//top이 0이면 top에 0를 뺀다. 0이 아니면 1를 뺀다.
			break;
		case 'D':
			top += top == strlen(arr)? 0 : 1;//top이 strlen(arr)이면 최대값이기에 1를 더하지 않는다.
			break;
		case 'B':
			if (arr[top] == '\0')//top+1에 널문자가 있으면 top에는 어떠한 문자가 마지막을 장식한다는 것이다.
			{
				arr[top-1] = arr[top];//널문자를 top에 넣고
				top--;
			}
			else//널문자가 없다는 것은 오른쪽에 있는 문자를 왼쪽으로 1칸 이동시킨다.
			{
				int ind_r = top+1;
				int ind_l = top;
				while (arr[ind_r] != '\0')
				{
					arr[ind_l] = arr[ind_r];//왼쪽으로 1칸씩 이동시킨다.
					ind_l++;
					ind_r++;
				}
				arr[ind_l] = arr[ind_r];//널문자까지 왼쪽으로 이동시킨다.
				//top--;//삭제된 문자보다 왼쪽으로 1칸 이동시킴
				
			}
			break;
		case 'P':
			scanf("%c", &c);
			getchar();
			if (top < strlen(arr))//top오른쪽에 문자가 있는 경우
			{
				int ind_r = strlen(arr)+1;
				int ind_l = strlen(arr);
				while (top <= ind_l)
				{
					arr[ind_r] = arr[ind_l];
					ind_r--;
					ind_l--;
				}
				arr[top] = c;
			}
			else//top이 널문자를 가리키는 경우
			{
				arr[top + 1] = arr[top];
				arr[top] = c;
				top++;//문자가 맨 뒤에 들어왔으므로 top를 1증가해야됨
			}
			break;
		}
	}
	printf("%s", arr);
}

