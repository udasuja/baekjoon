/*
�Է�: a
�� a�� 10���� ũ�� 1�� �ڸ����� �ݿø� �ϰ� �׸��� a�� 100���� ũ�� 10�� �ڸ����� �ݿø��� ��
a�� 1000���� ũ�� 100�� �ڸ����� �ݿø� �̰��� �ݺ��Ѵ�.
*/

#include <stdio.h>

int main(void)
{
	int s_arr[8], i = 0;
	char s;
	while (1)
	{
		s = getchar();//���ڸ� �������·� �Է¹޴´�. 
		if (s == '\n')//���� ����Ű�� �Է��ϸ� �ݺ����� ������.
		{
			break;
		}
		s_arr[i++] = s;
		//i���� ���ڿ��� ���̸� �˷��ش�.
		//ex)345\n�� �Է��ϸ� i�� 3�̶�� ���� ���Եȴ�.
	}
	//�ؿ��� �ݿø� �� �ݳ��� �˰���
	for (int k = i; k > 2; k--)
	{
		if ((int)s_arr[k] >= 5)
		{
			s_arr[k - 1] = (int)s_arr[k - 1] + 1;
		}
		if ((int)s_arr[k - 1] >= 10)
		{
			s_arr[k - 2] = (int)s_arr[k - 2] + 1;
			s_arr[k - 1] = (int)s_arr[k - 1] - 10;
		}
	}

	if (i == 1)
	{
		s_arr[0] <= '4' ? printf("%d", 0) : printf("%d", 10);
	}
	else
	{


		if (s_arr[1] <= '4')
		{
			printf("%d", (int)s_arr[0]);
			while (--i)
			{
				printf("%d", 0);
			}
		}
		else
		{
			if (s_arr[0] == '9')
			{
				printf("%d", 1);
				while (i--)
				{
					printf("%d", 0);
				}

			}
			else
			{
				printf("%d", (int)((int)s_arr[0] + 1));
				while (--i)
				{
					printf("%d", 0);
				}
			}
		}
	}
	return 0;
}