/*
ù �Է�: �л��� ��, ���׼ ������ �ð�(�� ����)

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int student, sec;
	int time = 0;
	long int* student_t;

	
	scanf_s("%d %d", &student, &sec);
	student_t = (long int*)malloc(sizeof(long int) * sec);
	for (int i = 0; i < student; i++)
	//�л� ����ŭ �ݺ��Ѵ�.
	{
		int a;
		scanf_s("%d", &a);//� �л��� ���� �ֱ⸦ �Է¹޴´�.
		for (long int k = 1,j=a; j <= sec;)//k�� ����1���ϰ� a�� ���Ѵ�.
		{
			if (student_t[j] != j)
			{
				student_t[j] = j;
				//�迭�� �����ϰ�
				time++;
			}
			j = a * ++k;
		}
	}
	free(student_t);
	printf("%d", time);
	return 0;
}