/*
�л����� ��ȣ�� �̴µ� �� ��ȣ�� �� ĭ ������ ������ ���� ��ȣ�̴�.
ù��° �л��� ������ 0�� �̰� �� �� �ι�° �л��� 0,1�߿� �̴´�.
1�� ������ ù��° �л��� �������� ��ĭ �տ��� ���� ����.
0�̸� �� �ڿ� ���� ����.
*/

#include <stdio.h>


int main(void)
{
	int num;
	int i = 1,j,go;
	int line[101] = { 0 };

	scanf_s("%d", &num);
	while (num--)
	{
		int jump_num;

		scanf_s("%d", &jump_num);
		if (jump_num == 0)
		{
			for (j = 0; line[j] != 0; j++);
			line[j] = i;
		}
		else
		{
			for (j = 0; line[j] != 0; j++);
			j -= 1;
			//�̶� �� j��° ��Ұ� �Ǹ����� ��Ұ� �ǰ�
			//�� ��Ҹ� jump_num��ŭ �ڷ� �а�
			//�߰��� �� ������ student(i��)�� �ִ´�.
			for (go = jump_num; go; go--,j--)
			{
				line[j+1] = line[j];
			}
			j += 1;
			line[j] = i;
		}

		i++;
	}
	for (j = 0; line[j] != 0; j++)
	{
		printf("%d ", line[j]);
	}
	return 0;
}
