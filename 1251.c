/*
 * ��¥ �ϳ� �ϳ� �����ؾ��Ѵ�.
 * �׷��ϱ� ù���ں��� ���� �ι�° ���� �� ���ڿ���
 * ù���� ���� ����°�� ���� �� ���ڿ��� �� �̷������� �ϳ��ϳ� ��� ����� ���� ���ؾ��Ѵ�.
 */
#include <stdio.h>
#include <string.h>

void reverse(char* arr)
{
	int len = strlen(arr);
	int i;
	for (i = 0; i < len / 2; i++)//���� ������ ���� �ݺ��� len/2���� ���������� �ݺ��ϹǷ� len�� Ȧ���� ���� ��� �ε��� ������ �����ϰ�
								 //¦���϶��� abcd b���� �����Ѵ�.
	{
		char temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}

int main(void)
{
	char arr[51], min_arr[] = { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" };//�ڵ带 �����ϸ鼭 �ּ� ������ ã�ƾ� �ϹǷ� �ִ� �������� �ʱ�ȭ�Ѵ�.
	int i, len, k;
	scanf("%s", arr);
	len = strlen(arr);
	for (i = 1; i < len - 1; i++)//ù��° �ε������� ���� ���������� 2��° ���� �ε������� �ݺ��Ѵ�.
	{
		for (k = i + 1; k < len; k++)//i��° �ε������� ���� ���������� 1��° ���� �ε������� �ݺ��Ѵ�.
		{
			char first[51], second[51], third[51];
			char new_word[51];
			strncpy(first, arr, i);//first�� arr�� ���ڿ��� i�� �����Ѵ�.
			first[i] = '\0';
			strncpy(second, arr + i, k - i);//i��°���� �����Ͽ� k-i���� �����Ѵ�.
			//�׷��⿡ arr+i�� �Ͽ� ���� �ּҰ��� i��° index�� �Ѵ�.
			second[k - i] = '\0';
			strncpy(third, arr + k, len - k);//�̰͵� k��°���� ������ �����ϱ�����
			//arr+k�� ���� �ּҰ����� �Ͽ� len-k�� �����Ѵ�.
			third[len - k] = '\0';
			reverse(first);
			reverse(second);
			reverse(third);
			strcpy(new_word, first);//new_word��� �迭�� first���� third���� ���ʴ�� ����ִ´�. ó������ first�� �����Ѵ�.
			strcat(new_word, second);//first���� reverse�� second�� ����
			strcat(new_word, third);//first�� �ٿ��� second�ڿ� third�� ����
			if (strcmp(new_word, min_arr) < 0)//new_word�� min_arr�� ���� �ٸ���. �޶����� ���ڸ� ���Ͽ� new_word�� ���ڰ� ������
											  //������ ��ȯ�ϹǷ� min_arr�� new_word�� ���´�.
				strcpy(min_arr, new_word);

		}
	}
	printf("%s", min_arr);
}
