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
	int c,lastnumber=-1;
	scanf_s("%d", &textcase);
	c = getchar();
	//scanf�� �̿��Ͽ� �Է��� ���� �������� '\n'�� �Է¹��ۿ� �������� �ٵ� �װ��� ���ִ� ���� 
	while (textcase)
	{
		int charater[26] = { 0 };
		int fal = 0,str=0,compare=0;
		while (str!='\n')
		{
			int number;
			str = getchar();
			number = (int)(str - 'A');
			if (compare == str && charater[lastnumber] == -1)
			//N-1��°�� ���ڰ� 3�� �Է��� �޾��� �� N��° ���ڰ� �� ���ڶ� ������
			{
				compare = 0;
				//���� ������ �ʱ�ȭ�Ѵ�.
			}
			else if (charater[lastnumber] == -1)
			//N-1��°�� ���ڰ� 3�� �Է��� �޾Ҵµ� N��° ���ڰ� �� ���ڶ� �ٸ���
			{
				fal = 1;
				//fal�� 1�̸� �� �޽����� �����̶�� ���̴�.
			}
			if (number >= 0)
			//�Է¹��� ���ڰ� �빮���϶� �ι��ڶ�� number�� ������ �� ���̴�.(�ƽ�Ű�ڵ� ���� �ι��ڰ� �� ������)
			{
				charater[number] += 1;
				//�� ���ĺ��� ������ 1�����Ѵ�.
			}
			if (charater[number] == 3)
			//���� ���ڰ� 3��������
			{
				compare = str;
				lastnumber = (int)(compare - 'A');
				charater[number] = -1;
				//���� ���� ���ڰ� �̹��� ���� ���ڿ� ������ �� ���ڰ� ����Ƚ���� 0�̵� ���̴�.
				//charater[number]+=1;�� ���ؼ� 
			}
		}
		if (fal == 1)
		{
			printf("FAKE\n");
		}
		else
		{
			printf("OK\n");
		}
		textcase--;
	}

	return 0;
}