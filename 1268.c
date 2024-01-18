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
#define MAX(a,b) a>b?a:b

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
	int i, k, index = 0;
	while (index < n)
	{
		int compare[1000] = { 0 };//���� ���� �� �л��� �ߺ��Ǿ� ������ �ʴ´�.
		int start = 0;
		for (i = 0; i < 5; i++)//1�г���� 5�г����
		{
			for (k = start; k < n; k++)//1������ n������ index���� �˻��Ͽ� ���� ������ index count�� 1�߰��Ѵ�.
			{
				if (k != index && student[k].stu[i] == student[index].stu[i] && compare[k] != 1)
					//k==index�϶��� ������ count�� 1�߰��ǹǷ� k!=index�� ����
					//student[k].stu[i] == student[index].stu[i]=>index��° �л��� k��° �л��� i�г��� �� �������̰�
					//compare�迭�� k��° ��Ұ� 1�� �ƴϸ� ���ǹ� ����
				{
					student[index].count += 1;
					compare[k] = 1;

				}
			}
		}
		index++;
	}
}