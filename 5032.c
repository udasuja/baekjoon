/*
�Է�: ���� �� ,�߰��� �� ���� ��, �� ���� �ʿ��� ���� ����
���: ���� �� �ִ� ź���� ����
�׸��� �ٲ�԰� ���� ���� �ٵ� �װ� ������ �� �� ������ �ٲ�Դ´�.
*/
#include <stdio.h>

void Bottle(int, int, int);

int main(void)
{
	unsigned int b_num1, b_num2, b_num3;


	scanf_s("%d %d %d", &b_num1, &b_num2, &b_num3);
	Bottle(b_num1, b_num2, b_num3);
}

void Bottle(int b_num1, int b_num2, int b_num3)
{
	int drink, new_b = 0, empty_bottle;


	new_b = (b_num1 + b_num2) / b_num3;
	//���� ���� �� �ִ� �������� ��
	drink = new_b;
	//���� �������� ��
	empty_bottle = ((b_num1 + b_num2) % b_num3) + new_b;
	//�� �ٲٰ� ���� ���� �������ٰ� �� ���� ���Ѵ�.
	while(empty_bottle >= b_num3)
	{
//���� ���� ���� �ٲ� �� �ִ� ��� ���ų� ������ �� �ٲ� �� �ִ�.
		new_b = empty_bottle / b_num3;
		//�� �� ������ �������� �ٲ�԰�
		drink += new_b;
		//�� ����ŭ �Ծ��⿡ drink�� new_b�� ���Ѵ�.
		empty_bottle = empty_bottle % b_num3 + new_b;
		//�԰� ���� �� ���� ��� �������� �ľ�
	} 
	printf("%d", drink);
}