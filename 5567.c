/*
ù ��° �ݺ������� ���ΰ��� ģ���� Ư���迭���ٰ� �����Ѵ�.
�������� Ư���迭�� ���ΰ��� ģ���� ���� ��ҹ�ȣ���ٰ� ���ΰ��� ģ���� ���� �����Ѵ�.
ex)1 4��� �ϸ� 4�� ���ΰ��� ģ���̱⿡ fri[4]==4�� �ȴ�.
�ι�° �ݺ������� ģ���� ����ִ� ���� ������ friend_num�� 1�� �����ش�.(=���ΰ� ��ȥ���� �ϰ��� ������ �ǹ�)
*/

#include <stdio.h>
#include <stdlib.h>

struct human
{
	int* a;
	int* b;
}human;

int main(void)
{
	int friend_member, list;
	int* friend_of_protagonist;
	int friend_num = 0;

	scanf_s("%d %d", &friend_member, &list);
	human.a = (int*)malloc(sizeof(int) * list);//int�� �ڷ����� ������ ���ִ� �޸� ũ�Ⱑ 4����Ʈ * friend_member�� �迭
	human.b = (int*)malloc(sizeof(int) * list);
	friend_of_protagonist = (int*)malloc(sizeof(int) * (friend_member+1));
	
	for (int i = 0; i < list; i++)
	{
		int a,b;
		scanf_s("%d %d", &human.a[i], &human.b[i]);
		a = human.a[i];//a���� i��° ���� ����a�� ����
		b = human.b[i];//b���� i��° ���� ����b�� ����

		if (a < b)
		{
			if (a == 1)
			{
				if (b != 1 && friend_of_protagonist[b] != b)
					//a�� 1�̰� b�� 1�� �ƴϸ� �迭�� b��ҿ� b�� ���� ����ִ´�.
					//�׸��� �迭�� b��ҿ� b���� ���� ��쿡 �����Ѵ�.
					//������ b��� ���� �̹� �ϰ����� ������ �Ǿ��ֱ⿡ �����Ѵ�.
				{
					friend_of_protagonist[b] = b;
					friend_num++;
				}
			}
		}
	}
	//�� �ݺ������� ���ΰ��� ģ���� �� �迭���ٰ� ����־���.
	//�׸��� ���ΰ��� ģ���� �ϰ����� �����Ͽ���.
	//���� �ݺ����� ���ΰ��� ģ���� ģ���� ���ϴ� �ݺ����̴�.
	for (int i = 0; i < list; i++)
	{
		int a = human.a[i], b = human.b[i];
		if (friend_of_protagonist[a] > 0 || friend_of_protagonist[b] > 0)
		//�迭�� ����� �ִٸ� i��° �࿡ ���ΰ��� ģ���� �ִٴ� ���̴�.
		{
			if (friend_of_protagonist[a] == a && friend_of_protagonist[b] == b)
			//�Ѵ� ���� ���´ٸ� �ߺ��Ǿ� ģ���� ���� ���ϴ� ���̱⿡ �� ���� �����Ѵ�.
			{
				continue;
			}
			else if(a!=1&&b!=1)
			//a���� b����� 1�� �ƴѰ��
			//else��� ���� �ϳ��� i��° ���� 2���� �� �� �ϳ��� ���� ���� ���´ٴ� ���̱⿡
			//�ϰ��� ���� 1�� �߰��Ѵ�.
			{
				friend_num++;
			}
		}

	}
	free(human.a);
	free(human.b);
	free(friend_of_protagonist);
	printf("%d", friend_num);
	return 0;
}