/*
Ai의 오른쪽에 있는 수들 중
Ai보다 큰 수들 중
가장 왼쪽에 있는 수

풀이
Ai오른쪽에 있는 모든 수들 중 가장 먼저 만나는 Ai보다 큰 수를 출력한다.
없으면 -1를 출력한다.
하지만 이렇게 하면 시간 초과

또 다른 풀이
배열을 세 개 만든다. 
한 개는 원래의 배열이고 이 배열의 이름을 c라 하자,
다른 개는 정렬할 배열이고, 
마지막 한 개는 정렬할 배열의 인덱스가 저장된다.
정렬할 배열을 A라 하겠다. 그리고 인덱스 배열을 B라 하겠다.
A배열을 정렬함과 동시에 B배열도 정렬하는데
A배열 내의 a[8]=9이고, a[1]=11일때 이 둘의 위치를 바꾼다면
a[1]=9,a[8]=11가 될 것이다. 이때 배열 B에서의 b[1]=1, b[8]=8은
b[1]=8, b[8]=1가 된다. 
즉 b[1]=8은 a배열의 인덱스 1이 가리키는 값이
a배열의 인덱스 8로 갔다는 의미가 된다.
b[8]=1은 a배열의 인덱스 8이 가리키는 값이
a배열의 인덱스 1로 갔다는 의미가 된다.

이런 식으로 두 배열의 정렬을 마치고
a배열은 이제는 안쓸 것이므로 여기에 출력값을 저장하겠다.
b배열을 참고하여 
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000

int sequ[SIZE];



int main(void)
{
	int n;
	int i;

	scanf_s("%d", &n);
	for (i = 0;i < n;i++)
	{
		scanf_s("%d", &sequ[i]);
	}

	for (i = 0;i < n;i++)
	{
		
		int k,right=0;
		int com = sequ[i];

		for (k = i+1;k < n;k++)
		{
			if (com < sequ[k])
			{
				right = sequ[k];
				break;
			}
		}
		if (right != 0)
			printf("%d ", right);
		else
			printf("-1 ");
		
		
	}
}