/*
������ ���� �ִ� 150���̰� ���� �� ��� �̸��� �ִ� 30���̴�. 
������ �̸� ù ���ڸ� �����ϵ��� �Ѵ�.
*/

#include <stdio.h>

int main(void)
{
	char name[30], first_name[150];
	char albat[26]={0};
	int non_player=0;
	int number;


	scanf_s("%d", &number);

	/*
	for������ name�� �ִ���̴� 30���̰� �� ������ ù���ڴ�
	�Էµ� ������� first_name�� ����ȴ�.
	*/
	for (int i = 0; i < number; i++)
	{
		scanf_s("%s", name,sizeof(name));
		first_name[i] = name[0];
	}

	/*
	ù ��° ������ ù���ڸ� ������ ������ ������ ù���ڱ���
	��� �������� ���ϸ� ù ��° ������ ���� ù ���ڸ� ���� �ִٸ�
	�� ��ȣ�� ������ �̸��� null�� �ٲ��ְ� ī��Ʈ�� ���ش�.
	�׸��� ���� �̸� ��� null�� ������ ���� ������ �Ѿ��.
	*/
	//a�� �ƽ�Ű�ڵ� ���� 97�̴�.(10���� ����)
	for (int i = 0; i < number; i++)
	{
		for (int k = i+1; k < number; k++)
		{
			if (first_name[i] != NULL)
			//first_name�� i��° ��Ұ� NULL�� ���� ����
			//�� ������ ������ NULL�ΰ͵� ���ĺ��� ���� �����̴�.
			{
				if (first_name[k] == NULL)
				{
					continue;
				}
				else if (first_name[i] == first_name[k])
				//first_name�� i��° ��ҿ� k��° ��Ұ� ������ ����
				{
					albat[(int)first_name[i] - 97] += 1;
					first_name[k] = NULL;
				}
				
			}
			else
			{
				break;
				//�ݺ��� Ż��
			}
		}
	}
	/*
	�ʹ� albat�� ��� ���Ҵ� 0�̴�. �� a�� first_name���� ���� �����
	6���̶�� �Ѵٸ� ���ϴ� �ڽ��� �������� �ʰ� ���� ���� ������
	5���̶�� ���´�.
	�� albat�� ���� �� 4 �̻��� �����ϴ� ���Ұ� ���ߵȴ�.
	*/
	for (int i = 0; i < 26; i++)
	//a~z�� 97�� �� �ƽ�Ű�ڵ�� ǥ���ϸ� 0~25���ȴ�.
	//�̶� non_player���� 25�� �ȴٸ� z�� �� ������ ���� ������ ���ٴ� ���̴�.
	{
		albat[i] >= 4 ?printf("%c",i+97) : non_player++;
		non_player == 26 ? printf("PREDAJA") : 0 ;//non���� 26�� �Ǹ�(i������ 1ũ�� �� i�� 25�� non�� 26�̵ȴ�.) ���ڿ� ���
	}
	return 0;
}