/*
�迭�� ũ��� 600000�� �Ѵ�.
top�� strlen(���ڿ�)-1�� ������ �ʱ�ȭ�Ѵ�. (top=strlen(���ڿ�)-1)

L-> top���� 1��ŭ ���� (0�̸� ���ҽ�Ű�� ����->top-= top==0?0:1;)
D-> top���� 1��ŭ ����(strlen(���ڿ�)-1�̸� ������Ű�� ����)
B-> top�� �ش��ϴ� �ε����� �����Ѵ�. top�����ʿ� �ִ� ��� ���ڿ��� �������� 1ĭ �̵�
P $-> top�� 1������Ű�� �� �ڸ��� $��� ���ڸ� ����ִ´�. ���� �� top�ڸ��� ���ڰ� �̹������� ��� ���ڸ� ���������� 1ĭ �̵��� ����ִ´�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 600001

int main(void)
{
	char arr[SIZE];
	int top,n;
	scanf("%s", arr);
	top = strlen(arr);

	scanf("%d", &n);
	getchar();
	while (n--)
	{
		char ch,c;
		scanf("%c", &ch);
		getchar();//L,D,B�� �Է������� �Է¹��ۿ� ���� \n�� ���ְ� P�� �Է��������� �����̽� ���ڸ� ���ش�.
		switch (ch)
		{
		case 'L':
			top -= top == 0 ? 0 : 1;//top�� 0�̸� top�� 0�� ����. 0�� �ƴϸ� 1�� ����.
			break;
		case 'D':
			top += top == strlen(arr)? 0 : 1;//top�� strlen(arr)�̸� �ִ밪�̱⿡ 1�� ������ �ʴ´�.
			break;
		case 'B':
			if (arr[top] == '\0')//top+1�� �ι��ڰ� ������ top���� ��� ���ڰ� �������� ����Ѵٴ� ���̴�.
			{
				arr[top-1] = arr[top];//�ι��ڸ� top�� �ְ�
				top--;
			}
			else//�ι��ڰ� ���ٴ� ���� �����ʿ� �ִ� ���ڸ� �������� 1ĭ �̵���Ų��.
			{
				int ind_r = top+1;
				int ind_l = top;
				while (arr[ind_r] != '\0')
				{
					arr[ind_l] = arr[ind_r];//�������� 1ĭ�� �̵���Ų��.
					ind_l++;
					ind_r++;
				}
				arr[ind_l] = arr[ind_r];//�ι��ڱ��� �������� �̵���Ų��.
				//top--;//������ ���ں��� �������� 1ĭ �̵���Ŵ
				
			}
			break;
		case 'P':
			scanf("%c", &c);
			getchar();
			if (top < strlen(arr))//top�����ʿ� ���ڰ� �ִ� ���
			{
				int ind_r = strlen(arr)+1;
				int ind_l = strlen(arr);
				while (top <= ind_l)
				{
					arr[ind_r] = arr[ind_l];
					ind_r--;
					ind_l--;
				}
				arr[top] = c;
			}
			else//top�� �ι��ڸ� ����Ű�� ���
			{
				arr[top + 1] = arr[top];
				arr[top] = c;
				top++;//���ڰ� �� �ڿ� �������Ƿ� top�� 1�����ؾߵ�
			}
			break;
		}
	}
	printf("%s", arr);
}

