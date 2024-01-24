/*
� ���� 2������ �Է����� �� 8������ ����ϴ� ���α׷�
���� ���:100�� ������ �����ʺ��� 2^0*0+2^1*0+2^2*1�� ���� 100�� 10������ ǥ������ ���� ���̰�
���Ĺ��� %o�� �� ���� 8������ ����� �� �ִ�.
2������ ǥ���� ���� �����ʺ��� 3���ھ� ���� ���� ó�� ������ش�.=>�׸��� �� ������ �������� ������� ����Ѵ�. 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void binary_octal(char* arr);

int main(void)
{
	char arr[1000001];
	
	scanf_s("%s", arr, sizeof(arr));
	binary_octal(arr);

	return 0;
}
void binary_octal(char* arr)
{
	int i;
	double j = 0;
	int sum = 0;
	int len = strlen(arr);
	for (i = len - 1; i >= len - 3 && i >= 0; i--)
	{
		int num = arr[i] - '0';
		sum += (int)(pow(2, j) * num);
		arr[i] = '\0';
		j++;
	}
	if (i < 0)
	{
		printf("%d", sum);
		return;
	}
	else
		binary_octal(arr);
	printf("%d", sum);
	return;
}