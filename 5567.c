/*
ģ���� �ʴ��ϴµ� ���ΰ��� a�� ģ����� a�� ģ�� b������ ������ �� �ִ�.
������ ���� 500����,����ũ�� ���̴� 10000���ϴ�.


list�� ù��° �Է¹迭�� k���ϰ� �ι�° �Է¹迭�� o��� �Ѵ�.
�迭�� ������ ���� �����ϰ�
�� �� 1�� ģ���� ģ���� ���� �迭���ٰ� �����Ѵ�.

�Է�
1.������ ����
2.����Ʈ�� ����

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
	int list, friend_member;
	int* fri;//friend��� ������ int���̸� int�� �޸�ũ�Ⱑ 500�� �ִ� �迭�� ������ش�.
	int* fri_of_friend;
	int friend_num = 0;
	int k = 0;

	scanf_s("%d %d", &friend_member, &list);//list�� ���̸� �����Ѵ�.
	human.a= (int*)malloc(sizeof(int) * friend_member);
	human.b= (int*)malloc(sizeof(int) * friend_member);
	fri = (int*)malloc(sizeof(int) * friend_member);
	fri_of_friend = (int*)malloc(sizeof(int) * friend_member);
	//���ΰ��� ���ڸ� �����Ѵ�.
	for (int i = 0; i < list; i++)
	{

		scanf_s("%d %d", &human.a[i], &human.b[i]);
		if ((human.a[i] != human.b[i]) && (human.a[i] <= friend_member && human.b[i] <= friend_member))
		//human.a��human.b�� ���� ���� �ʰ� �� ���� ���� ������ �ִ� ũ�� �����϶�
		{
			if (human.a[i] == 1 || human.b[i] == 1)
				//human.a�� human.b�� ���ΰ��̶�� human.b �� human.a�� ���ΰ��� ģ�����ȴ�.
			{
				if (human.a[i] == 1)
				{
					fri[human.b[i]] = human.b[i];
					//human.b�� ���� ���ڸ� ���� friend�迭�� ���� human.b�� �����Ѵ�.
				}
				else
					//human.b�� ���ΰ��϶� human.a�� ���ΰ��� ģ�����ȴ�.
				{
					fri[human.a[i]] = human.a[i];
				}
			}
		}
	}
	for (int i = 0; i < friend_member; i++)
	//������ ����ŭ �ݺ��Ѵ�.
	{
		while (k < list)
		//ģ���� ģ���� ã������ �ݺ����̴�.
		{
			if (fri[human.a[k]] == human.a[k] || fri[human.b[k]] == human.b[k])
				//human.a[i]==4 ��� fri�� 4��° ��ҿ� 4�� ������ ���ΰ��� ģ����� ���̴�.
			{
				if (fri[human.a[k]] == human.a[k] && fri[human.b[k]] == human.b[k])
				//fri�� �� ��ҿ� �Ѵ� ���� ������ ���ΰ��� ģ����� ���̱⿡
				//k�� 1�� ���� �ݺ����� ó������ �����Ѵ�.
				{
					k++;
					continue;
				}
				else if (fri[human.a[k]] == human.a[k])
				{
					fri_of_friend[human.b[k]] = human.b[k];
					//ģ���� ģ���� fri�迭�� �����Ѵ�.
				}
				else if(fri[human.b[k]]==human.b[k])
				{
					fri_of_friend[human.a[k]] = human.a[k];
				}
			}
			k++;
		}
		if (fri[i] != NULL || fri_of_friend[i]!=NULL)
		{
			friend_num++;
		}
	}
	free(fri);
	printf("%d", friend_num);
	return 0;
}