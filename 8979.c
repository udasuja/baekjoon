//�Է��� ù�� => ������ �� , ����� �˰��� ����
//�Է� => ������ ��Ÿ���� ������ , �ݸ޴� ,���޴� ,���޴�

#include <stdio.h>
#include <stdlib.h>

struct medal
//������ ������ ������ ����ä
{
	int* gold;
	int* selver;
	int* copper;
}medal;



int main(void)
{
	int country_num, country_rank;
	medal.gold = (int*)malloc(sizeof(int) * 1000);
	//�� ����ü�� int�� �޸𸮸� �Ҵ��Ѵ�.(4����Ʈ*country_num ������ ũ�⸦ ���� �޸� ũ��)
	//�װ����� �޸� ũ�⸦ �Ҵ� ���� ����ü �迭�� �����.
	medal.selver = (int*)malloc(sizeof(int) * 1000);
	medal.copper = (int*)malloc(sizeof(int) * 1000);
	int ranking = 1;
	int member;

	scanf_s("%d %d", &country_num, &country_rank);
	for (int i = 0; i < country_num; i++)
	{
		scanf_s("%d", &member);
		//member�� �Է°��� 1���� �����ϹǷ� �迭�� 0��° ��Һ��� ������ �ƴ� 1���� �����Ѵ�.
		scanf_s("%d %d %d", &medal.gold[member], &medal.selver[member], &medal.copper[member]);

	}
	for (int k = 1; k <= country_num; k++)
		//ù��° ������� �� ������� rank��° ����� ���ϸ�.
		//k��° ���󺸴� ������ ������ ranking���� 1�� ���Ͽ� ������ �ڷ� �̷��.
	{
		if (medal.gold[k] > medal.gold[country_rank])
			//k��° ������ �ݸ޴��� �� ������ rank������ ������ �ڷ� �з�����.
		{
			ranking++;
		}
		else if (medal.gold[k] < medal.gold[country_rank])
			//rank�� �ݸ޴��� �� ������
		{
			continue;
		}
		else if ((medal.gold[k] == medal.gold[country_rank]) && (medal.selver[k] > medal.selver[country_rank]))
			//k��° ������ ���޴��� �� ������ rank������ ������ �ڷ� �з�����.
		{
			ranking++;
		}
		else if (medal.selver[k] < medal.selver[country_rank])
			//rank�� ���޴��� �� ������
		{
			continue;
		}
		else if ((medal.selver[k] == medal.selver[country_rank]) && (medal.copper[k] > medal.copper[country_rank]))
			//k��° ������ ���޴��� �� ������ rank������ ������ �ڷ� �з�����.
		{
			ranking++;
		}
	}
	free(medal.gold);
	free(medal.selver);
	free(medal.copper);
	printf("%d", ranking);
	return 0;
}