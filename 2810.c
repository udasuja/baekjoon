/*
�Է�:�¼��� ��
	 �¼��� ����(S�� �Ϲ��¼��� �ǹ� L�� Ŀ�� ���� �ǹ�)
���:��Ȧ���� �� �� �ִ� ����� ��
ex)SLLS��� ��Ȧ���� *S*LL*S*���ȴ�. �̶� *�� ��Ȧ���� �ǹ��Ѵ�.
LL�� �� ���� S��� �����Ѵ�.
*/

void Number_of_cupholder(int*, int*,int);

#include <stdio.h>

int main(void)
{
	int n,people=0,seat=0;
	

	scanf_s("%d", &n);
	//�¼��� ��
	Number_of_cupholder(&people, &seat,n);
	//people�� seat�� �ּҰ��� ��ȯ�� holder�� ������ �ο��� �ΰ�޴´�.
	seat > people ? printf("%d", people) : printf("%d", seat);
	//holder�� ������ ��� ������ ������ ��� �� ��ŭ ����ϰ�
	//������ �� ��� ���� �� ������ ��Ʈ ��(=holder�� ����) ��ŭ�� ����Ѵ�.
	return 0;
}

void Number_of_cupholder(int* people, int* seat,int n)
{
	int s = 0;
	char kind_of_seat;
	for (int i = 0; i < n; i++)
	{
		scanf_s(" %c", &kind_of_seat);
		//( %c) %c�տ� �� ĭ�� ������ �Է¹��۸� �ʱ�ȭ �ϱ� ���ؼ���.
		if (kind_of_seat == 'S' || kind_of_seat == 's')
		{
			(*people)++;//����� ���� �ǹ��Ѵ�.
			s++;
			(* seat) += 2;
		}
		if (kind_of_seat == 'L' || kind_of_seat == 'l')
		{
			i++;
			scanf_s(" %c", &kind_of_seat);
			if (kind_of_seat == 'L' || kind_of_seat == 'l')
			{
				(*people) += 2;
				s++;
				(* seat) += 2;
			}
			else
			{
				i -= 2;
			}
		}
	}
	
	s = (s == 0) ? s : --s;
	(* seat) -= s;//seat��� ������ ���ڿ� �޷��ִ� ��Ȧ���� ������ �ǹ��Ѵ�.
}