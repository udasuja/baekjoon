/*
10�� ��ǻ�Ͱ� ������� �����͸� ó���Ҷ� ������ �����Ͱ� ó���Ǵ� ��ǻ���� ��ȣ��?
ex)5�� ��ǻ�� 10���� ������=>1��com-1��data,2��com-2��data,3��com-3��data,4��com-4��data,5��com-5��data,1��com-6��data ... 5��com-10��data
�Է�: �ݺ�Ƚ��
	 �������� ���� a,b�̶� a�� ���̰� b�� ����̴�.

Ǯ��:
	
	
	a�� 1���� b���� �����ϸ鼭 a�� 1�� �ڸ����� ������ ���� 1�� �ڸ� ���ڰ� �������� �� Ƚ���� �����ϰ� �� Ƚ���� b�� ������ �������� ���Ѵ�.
	�׸��� ��������ŭ a�� �����ϸ鼭 a�� 1�� �ڸ����� ���Ѵ�.
*/
#include <stdio.h>

int main(void)
{
	int t, a, b, num1, i;
	scanf_s("%d", &t);
	while (t--)
	{
		int count = 1;
		scanf_s("%d %d", &a, &b);
		num1 = a;
		for (i = 0; i < b; i++)
		{
			num1 = num1 * a;
			if (a >= 10)
			{
				count++;
				num1 = (num1 % 100) % 10;
				if (num1 == a % 10)
					break;
			}
			else if (a < 10)
			{
				count++;
				num1 = num1 % 10;
				if (num1 == a)
					break;
			}
		}
		b -= count;
		while (b-->0)
		{
			num1 = num1 * a;
			if (a >= 10)
				num1 = (num1 % 100) % 10;
			else if (a < 10)
				num1 = num1 % 10;
		}
		printf("%d\n", num1 %10 );
	}
}