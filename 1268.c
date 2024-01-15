/*
���� �� �л� �� 1�г���� 5�г���� �ٸ� �п�� ���� ���� �� Ƚ���� ���� ���� �ְ�
�ӽù����̵ȴ�. �̶� �ӽù����� �� �� �ִ� �ְ� �������̸� ���� ���� ��ȣ�� �л��� �ӽù����� �ȴ�.
(2���� �迭���� ���� ������ ������ 5�̴�.)
Ǯ��:�ϴ� malloc�Լ��� �л����� �ø���. �� �л� �迭�� ���̴� 5�̴�.
���� �� ���� ���ϸ� ���� ���ڰ� �ִ� �ֵ��� count�� 1������Ų��.
count�� ���� ū �ָ� ���, ������ ��ȣ�� ���� �ָ� ���.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) a>b?a:b

typedef struct
{
	int stu[5];
	int count;
}STU;

void student_count(STU*,int);

int main(void)
{
	STU *student;
	int n,i,k;
	int max_ = 0;

	scanf_s("%d", &n);
	student = (STU*)malloc(sizeof(int) * n);//student�� STU�ڷ����� ���� ����ü �����̱⿡ STU*�� ����Ѵ�.

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
	printf("%d", max_+1);
	
	return 0;
}

void student_count(STU* student,int n)//1�� �л����� 1�г���� 5�г��� ���� ���� �ְ� �ִ��� �˻��ϰ� �״��� 2�� �̷������� �ö󰣴�.
{
	int i,k,index=0;
	while (index<n)
	{
		for (i = 0; i < 5; i++)//1�г���� 5�г����
		{
			for (k = 0; k < n; k++)//1������ n������ index���� �˻��Ͽ� ���� ������ index count�� 1�߰��Ѵ�.
			{
				if(k!=index)//k==index�϶��� ������ count�� 1�߰��ǹǷ�
					student[index].count += student[k].stu[i] == student[index].stu[i] ? 1 : 0;
			}
		}
		index++;
	}
}