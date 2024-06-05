/*
���� �� �л� �� 1�г���� 5�г���� �ٸ� �п�� ���� ���� �� Ƚ���� ���� ���� �ְ�
�ӽù����̵ȴ�. �̶� �ӽù����� �� �� �ִ� �ְ� �������̸� ���� ���� ��ȣ�� �л��� �ӽù����� �ȴ�.
(2���� �迭���� ���� ������ ������ 5�̴�.)
Ǯ��:�ϴ� malloc�Լ��� �л����� �ø���. �� �л� �迭�� ���̴� 5�̴�.
���� �� ���� ���ϸ� ���� ���ڰ� �ִ� �ֵ��� count�� 1������Ų��.
count�� ���� ū �ָ� ���, ������ ��ȣ�� ���� �ָ� ���.


*/
#include <stdio.h>
//����ü ������ student_count�Լ��� compare�� malloc�Լ��� ����ߴ��� �޸� ���� ������ ���Դ�.

typedef struct
{
	int stu[5];
	int count;
}STU;

void student_count(STU*, int);

int main(void)
{
	STU student[1000];
	int n, i, k;
	int max_ = 0;

	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < 5; k++)
		{
			student[i].count = 0;//i��° �л��� count���� 0���� �ʱ�ȭ�Ѵ�.
			scanf_s("%d", &student[i].stu[k]);
		}
	}
	student_count(student, n);
	for (i = 0; i < n; i++)
	{
		max_ = student[i].count > student[max_].count ? i : max_;
	}
	printf("%d", max_ + 1);

	return 0;
}

void student_count(STU* student, int n)//1�� �л����� 1�г���� 5�г��� ���� ���� �ְ� �ִ��� �˻��ϰ� �״��� 2�� �̷������� �ö󰣴�.
{
	int i, k, j;
	for (i = 0; i < n; i++)//�����
	{
		for (k = 0; k < n; k++)//�Ǵ����
		{
			for (j = 0; j < 5; j++)//�г�
			{
				if (student[i].stu[j] == student[k].stu[j])//����ڿ� �Ǵ������ �� ������ ���� ���� ������ ����
				{
					student[i].count++;
					break;//k��° �л��� j�г⶧ ���� ���̾����Ƿ� �ߺ��Ǿ� �˻簡 ������� �ʵ��� k��° �л����� ��ġ�� ���� ã�� ���� �׸��д�.
				}
			}
		}
	}
}