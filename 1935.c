/*
post order traversal

재귀함수 형식을 이용한다.
왼쪽 서브트리로 계속 내려가다가 왼쪽 서브트리가 null이면
오픈쪽 서브트리로 내려간다. 오른쪽 서브트리도 null이면 
자기 자신 node를 출력 후 return하여 자신의 부모 node로 복귀한다.

그럼 그 부모 node로 돌아갔을 때 왼쪽 subtree는 출력했지만 오른쪽은 출력하지 않았다면
오른쪽에 접근 후 위 과정을 반복하고
오른쪽 마저 출력을 다 끝냈다면 그러면 자기 자신 node를 출력후
return하여 자신의 부모 node로 돌아간다.


ABC*+DE/-는 binary search tree로는 다음과 같은 구조를 같는다. (A+B*C-D/E)
				 -
			 /		E
		 +		D
	  *		C
	A	B

풀이
값을 저장하는 모든 변수는 double로 설정(문자는 제외)
출력은 %.2lf로 소숫점 둘째 자리까지 출력한다.

큐를 사용하여 문제를 풀겠다.
후위 표기식은 피연산자 큐와 연산자 큐로서 저장한다.
그리고 3번째 줄부터 나오는 피연산자의 값을 배열에 저장
나중에 피연산자 큐에서 피연산자를 pop하여
피연산자를 계산할 때 'A'를 빼 그 피연산자에 대한 원소값에 접근

후위 표기식에 대한 계산을 할 때에는
이전에 시행에서 계산한 피연산자와
현재 피연산자에 대한 원소값를
연산자 큐에서 나온 연산자로 연산한다. 
이때 연산자 문자 +, -, *, /는 각각 -1부터 -4에 대응된다.
*/

#include <stdio.h>
#define SIZE 100

typedef struct
{
	int rear, front;
	char arr[SIZE];
}Arr;

int main(void)
{
	Arr operand, opcode;	
	int n,i,count=0;
	char c;
	double op_arr[26];
	double result;
	int index;

	operand.front = operand.rear = -1;	//큐는 선형큐로 하겠다.
	opcode.front = opcode.rear = -1;

	scanf_s("%d", &n);
	getchar();	//buffer에 남아있는 \n제거

	while ((c = getchar()) != '\n')
	{
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			opcode.arr[++opcode.rear] = c;
		}
		else
		{
			operand.arr[++operand.rear] = c;
		}
		count++;
	}

	for (i = 0;i < n;i++)
	{
		scanf_s("%lf", &op_arr[i]);
	}

	index = operand.arr[++operand.front] - 'A';
	result = op_arr[index];

	for (i = 0;i < count;i++)
	{
		double after;
		if (operand.front <= operand.rear)
		{
			index = operand.arr[++operand.front] - 'A';
			after= op_arr[index];
		}
		switch (opcode.arr[++opcode.front])
		{
		case'+':
			result += after;
			break;
		case'-':
			result -= after;
			break;
		case'*':
			result *= after;
			break;
		case '/':
			result /= after;
			break;
		default:
			break;
		}

		printf("%.2lf\n", result);
	}
	return 0;
}