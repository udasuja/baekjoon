/*
post order traversal

����Լ� ������ �̿��Ѵ�.
���� ����Ʈ���� ��� �������ٰ� ���� ����Ʈ���� null�̸�
������ ����Ʈ���� ��������. ������ ����Ʈ���� null�̸� 
�ڱ� �ڽ� node�� ��� �� return�Ͽ� �ڽ��� �θ� node�� �����Ѵ�.

�׷� �� �θ� node�� ���ư��� �� ���� subtree�� ��������� �������� ������� �ʾҴٸ�
�����ʿ� ���� �� �� ������ �ݺ��ϰ�
������ ���� ����� �� ���´ٸ� �׷��� �ڱ� �ڽ� node�� �����
return�Ͽ� �ڽ��� �θ� node�� ���ư���.


ABC*+DE/-�� binary search tree�δ� ������ ���� ������ ���´�. (A+B*C-D/E)
				 -
			 /		E
		 +		D
	  *		C
	A	B

Ǯ��
���� �����ϴ� ��� ������ double�� ����(���ڴ� ����)
����� %.2lf�� �Ҽ��� ��° �ڸ����� ����Ѵ�.

ť�� ����Ͽ� ������ Ǯ�ڴ�.
���� ǥ����� �ǿ����� ť�� ������ ť�μ� �����Ѵ�.
�׸��� 3��° �ٺ��� ������ �ǿ������� ���� �迭�� ����
���߿� �ǿ����� ť���� �ǿ����ڸ� pop�Ͽ�
�ǿ����ڸ� ����� �� 'A'�� �� �� �ǿ����ڿ� ���� ���Ұ��� ����

���� ǥ��Ŀ� ���� ����� �� ������
������ ���࿡�� ����� �ǿ����ڿ�
���� �ǿ����ڿ� ���� ���Ұ���
������ ť���� ���� �����ڷ� �����Ѵ�. 
�̶� ������ ���� +, -, *, /�� ���� -1���� -4�� �����ȴ�.
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

	operand.front = operand.rear = -1;	//ť�� ����ť�� �ϰڴ�.
	opcode.front = opcode.rear = -1;

	scanf_s("%d", &n);
	getchar();	//buffer�� �����ִ� \n����

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