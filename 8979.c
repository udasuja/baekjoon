//�Է��� ù�� => ������ �� , ����� �˰��� ����
//�Է� => ������ ��Ÿ���� ������ , �ݸ޴� ,���޴� ,���޴�

#include <stdio.h>

int main(void)
{
	int country_num, country_rank;
	int country_m[500][3];
	int ranking = 1;
	int member;
	
	scanf_s("%d %d", &country_num, &country_rank);
	for (int i = 0; i < country_num; i++)
	{
		scanf_s("%d", &member);
		//member�� �Է°��� 1���� �����ϹǷ� �迭�� 0��° ��Һ��� ������ �ƴ� 1���� �����Ѵ�.
		scanf_s("%d %d %d", &country_m[member][0], &country_m[member][1], &country_m[member][2]);
		
	}
	for (int k = 1; k <=country_num; k++)
	//ù��° ������� �� ������� rank��° ����� ���ϸ�.
	//k��° ���󺸴� ������ ������ ranking���� 1�� ���Ͽ� ������ �ڷ� �̷��.
	{
		if (country_m[k][0] > country_m[country_rank][0])
			//k��° ������ �ݸ޴��� �� ������ rank������ ������ �ڷ� �з�����.
		{
			ranking++;
		}
		else if (country_m[k][0] < country_m[country_rank][0])
			//rank�� �ݸ޴��� �� ������
		{
			continue;
		}
		else if ((country_m[k][0] == country_m[country_rank][0]) && (country_m[k][1] > country_m[country_rank][1]))
			//k��° ������ ���޴��� �� ������ rank������ ������ �ڷ� �з�����.
		{
			ranking++;
		}
		else if (country_m[k][1] < country_m[country_rank][1])
			//rank�� ���޴��� �� ������
		{
			continue;
		}
		else if ((country_m[k][1] == country_m[country_rank][1]) && (country_m[k][2] > country_m[country_rank][2]))
			//k��° ������ ���޴��� �� ������ rank������ ������ �ڷ� �з�����.
		{
			ranking++;
		}
	}
	printf("%d", ranking);
	return 0;
}