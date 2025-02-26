#include <stdio.h>

#define SIZE 1000000

int stack[SIZE];
int top = -2;

void output(int* arr, int size);

int main(void)
{
	int arr[SIZE];
	int i, n;

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	output(arr, n - 1);
}

void output(int* arr, int size)
{
	//degenerate case
	if (size == -1)
		return;
	int result;


	while (stack[top] <= arr[size] && --top > -1)
		;
	if (top == -1)
		result = -1;
	else
		result = stack[top];


	stack[++top] = arr[size];
	output(arr, size - 1);
	printf("%d ", result);
	return;
}