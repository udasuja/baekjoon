/*
� ���� 2������ �Է����� �� 8������ ����ϴ� ���α׷�
���� ���:100�� ������ �����ʺ��� 2^0*0+2^1*0+2^2*1�� ���� 100�� 10������ ǥ������ ���� ���̰�
���Ĺ��� %o�� �� ���� 8������ ����� �� �ִ�.
2������ ǥ���� ���� �����ʺ��� 3���ھ� ���� ���� ó�� ������ְ� �� ���� �ϵ��ڵ� ������� ����Ѵ�.=>�׸��� �� ������ �������� ������� ����Ѵ�. 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>


void binary_octal(char* arr,int len);

int main(void)
{
	char arr[1000001];
	int len;
	scanf_s("%s", arr, sizeof(arr));
	len = strlen(arr);
	binary_octal(arr,len);

	return 0;
}
void binary_octal(char* arr,int len)
{
	int i,j=2;
	char arr_c[4]={'0','0','0'};
	//11001100���� ���� �Է��� ��11/001/100���� �ɰ� �� �ִ�. �̶� 11�� ����� �� arr_c[0]�� ���� 0�̶�� ������ ����Ǿ��ٸ�
	//�ƴϸ� ������ ������ ����Ǿ��ٸ� atoi�Լ�(���ڿ�=>����)�� ����� ���� ����. �׷��⿡ 2��° ��ұ��� '0'���� �ʱ�ȭ ���ش�.
	if (len <= 0)
	{
		return;
	}
	else
	{
		for (i = len-1; i >= 0 && j >=0; i--,j--)//arr_c�Լ��� �ڿ������� ���ڸ� ä��� 0��° ��� ����(���� ���:-1��°)�� ������ �� ������ ��
		{
			arr_c[j] = arr[i];
		}
		binary_octal(arr, len - 3);//���������̱⿡ ����Լ��� ����Ͽ���.
		switch (atoi(arr_c))
		{
		case 0:
			printf("0");
			break;
		case 1://001�� ���⿡�� �ɸ���.
			printf("1");
			break;
		case 10://010�� ���⿡�� �ɸ���.
			printf("2");
			break;
		case 11:
			printf("3");
			break;
		case 100:
			printf("4");
			break;
		case 101:
			printf("5");
			break;
		case 110:
			printf("6");
			break;
		case 111:
			printf("7");
		}
	}
	return;
}