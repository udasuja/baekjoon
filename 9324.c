/*
�Էµ� �޽����� �� ���ڰ� �� ��° ������ �� �� �� �� ���ڰ� ���Եȴ�
���� ��� ����� "HELLOTHEREWELLBEFINE" ��� �޽����� ������ �;� �ߴٸ� 
"HELLOTHEREEWELLLBEFINEE" �� ��Ȯ�� �����̴�.
�� �� �� ���Ե� ���ڴ� �� 4��° �빮�ڴ� �ҹ��ڷ� ǥ���ȴ�.
(3�� ��� �� ���� ���ڴ� ����.)  
HELLOTHEREEWELLLBEFINEE��
HELLOTHEREeWELLlBEFINEe�� �ȴ�.

� ���ڰ� 3���� �����ŭ �������� Ȯ���ϰ� �׷� ���ڰ� ������ fake���
*/
#include <stdio.h>

int main(void)
{
	int textcase;
	int str = 0, c, fourth = 0;
	scanf_s("%d", &textcase);
	c = getchar();
	//c������ textcase���� ������� �ʴ� \n�Է��� ���ֱ� ���ؼ��̴�.
	while (textcase)
	{
		int charater[27] = { 0 };
		int fal = 0, tru=0,count = 0;
		do
		{
			int number;
			str = getchar();
			number = (int)(str - 'A');

			if (number >= 0)
			{
				charater[number] += 1;
				//���ĺ��� �ش��ϴ� ��ҿ� 1�� �߰��Ͽ� � ���ĺ��� �ԷµǾ����� �� �� �ִ�.
			}
			if (count)
			{
				if (str == fourth)
				{
					tru=1;
					count = 0;
					charater[number] = 0;
				}
				else
				{
					fal = 1;
				}
			}
			if (charater[number] / 3 == 1)
			{
				count = 1;
				fourth = str;
			}
		} while (str != '\n');//�Է��� \n(����)�̶�� �ݺ��� �����Ѵ�.
		if (fal == 0&&tru==1)
		{
			printf("OK\n");
		}
		else if (fal == 1)
		{
			printf("FAKE\n");
		}
		textcase--;
	}

	return 0;
}