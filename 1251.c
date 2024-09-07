/*
 * 진짜 하나 하나 실행해야한다.
 * 그러니깐 첫글자부터 끊고 두번째 끊고 그 문자열과
 * 첫글자 끊고 세번째로 끊고 그 문자열과 비교 이런식으로 하나하나 모든 경우의 수를 비교해야한다.
 */
#include <stdio.h>
#include <string.h>

void reverse(char* arr)
{
	int len = strlen(arr);
	int i;
	for (i = 0; i < len / 2; i++)//문자 스왑을 위한 반복문 len/2보다 작을때까지 반복하므로 len이 홀수일 때는 가운데 인덱스 전까지 실행하고
								 //짝수일때는 abcd b까지 실행한다.
	{
		char temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}

int main(void)
{
	char arr[51], min_arr[] = { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" };//코드를 실행하면서 최소 문장을 찾아야 하므로 최대 문장으로 초기화한다.
	int i, len, k;
	scanf("%s", arr);
	len = strlen(arr);
	for (i = 1; i < len - 1; i++)//첫번째 인덱스부터 끊어 마지막에서 2번째 앞의 인덱스까지 반복한다.
	{
		for (k = i + 1; k < len; k++)//i번째 인덱스부터 끊어 마지막에서 1번째 앞의 인덱스까지 반복한다.
		{
			char first[51], second[51], third[51];
			char new_word[51];
			strncpy(first, arr, i);//first에 arr의 문자열을 i개 복사한다.
			first[i] = '\0';
			strncpy(second, arr + i, k - i);//i번째부터 시작하여 k-i개를 복사한다.
			//그렇기에 arr+i를 하여 시작 주소값을 i번째 index로 한다.
			second[k - i] = '\0';
			strncpy(third, arr + k, len - k);//이것도 k번째부터 끝까지 복사하기위해
			//arr+k를 시작 주소값으로 하여 len-k개 복사한다.
			third[len - k] = '\0';
			reverse(first);
			reverse(second);
			reverse(third);
			strcpy(new_word, first);//new_word라는 배열에 first부터 third까지 차례대로 집어넣는다. 처음에는 first를 복사한다.
			strcat(new_word, second);//first뒷편에 reverse한 second를 붙임
			strcat(new_word, third);//first와 붙여진 second뒤에 third를 붙임
			if (strcmp(new_word, min_arr) < 0)//new_word와 min_arr는 서로 다르다. 달라지는 문자를 비교하여 new_word의 문자가 작으면
											  //음수를 반환하므로 min_arr를 new_word로 덮는다.
				strcpy(min_arr, new_word);

		}
	}
	printf("%s", min_arr);
}
