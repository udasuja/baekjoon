/*
입력: 빈병의 수 ,발견한 빈 병의 수, 새 병에 필요한 빈병의 개수
출력: 먹을 수 있는 탄산의 개수
그리고 바꿔먹고 빈병이 남을 텐데 그걸 가지고 또 새 병으로 바꿔먹는다.
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
	//새로 먹을 수 있는 음류수의 양
	drink = new_b;
	//먹은 음류수의 양
	empty_bottle = ((b_num1 + b_num2) % b_num3) + new_b;
	//빈병 바꾸고 남은 빈병의 개수에다가 새 병을 더한다.
	while(empty_bottle >= b_num3)
	{
//남은 빈병의 양이 바꿀 수 있는 양과 같거나 많으면 또 바꿀 수 있다.
		new_b = empty_bottle / b_num3;
		//또 빈 병으로 음류수를 바꿔먹고
		drink += new_b;
		//새 병만큼 먹었기에 drink에 new_b를 더한다.
		empty_bottle = empty_bottle % b_num3 + new_b;
		//먹고 남은 빈 병이 어느 정도인지 파악
	} 
	printf("%d", drink);
}