#include <stdio.h>

int main(void)
{
	int day, math_page, language_page, math_sol, language_sol;
	int i;
	scanf_s("%d %d %d %d %d", &day, &math_page, &language_page, &math_sol, &language_sol);
	for (i = 0; math_page != 0 || language_page != 0;)
	{
		math_page -= math_sol;
		language_page -= language_sol;
		i++;
		//for���� ��ȣ ���� �ƴ� �ۿ� �ִ� ������ ���а� ���� ������ Ǯ��
		//�Ϸ簡 �����ٴ� ��(=�������� 1ȸ �� Ǯ���ٴ� ��)�� ���������� �����ֱ� ���ؼ���.
		if (math_page <= 0 && language_page <= 0)
		//�� �� 0�����̸� �� �̻� Ǯ �������� ���ٴ� ���̱⿡ �ݺ��� �����Ѵ�.
		{
			break;
		}
	}
	printf("%d", day - i);
}