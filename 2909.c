/*
입력: 사탕의 가격, 지폐의 0의 개수
출력: 내야하는 가격

ex)지폐의 액면가가 100원이면 사탕의 가격이 149면 반내림해서 100원 결제
150원이면 반올림해서 200원 결제
즉 가격%0의 개수를 한다음 나머지 값의 앞글자가 4이하이면 반내림
5이상이면 반올림을 한다.
*/
#include <stdio.h>

int main(void)
{
	int  bill;
	unsigned long int price_candy,money=1,price1;

	scanf_s("%ld %d", &price_candy, &bill);
	for (int i = 0; i < bill; i++)
	//지불 가능한 지폐의 액면가를 구한다.
	//bill은 지폐의 0의 개수이기에 반복문을 통해 지폐의 액면가를 구한다. 
	{
		money *= 10;
	}
	price1 = price_candy % money;
	if ((money / 10) * 5 <= price1&&price1)
	//money에 10을 몫의 나누기를 한후 5를 더한것이 나머지보다 작거나 같고
	//나머지 값이 0이 아니면 실행
	//이래야지 money가 1원 일때 반올림을 하지 않고 정상적으로 처리된다.
	//ex)액면가 10원 사탕 가격 159원 price1의 값은 9가 된다.
	//money/10*5의 값은 5가 되고 5보다 크므로 반올림을 하게된다.
	//즉 좌변보다 우변이 더 크면 예시와 같으므로 반올림을 하게된다.
	{
		price_candy -= (price_candy % money);
		//나머지만큼 빼고
		price_candy += money;
		//money만큼 더하면 반올림이 된다.
	}
	else
	{
		price_candy -= (price_candy%money);
		//price_candy에다가 나머지만큼 빼면 반내림하는 것이된다.
	}
	printf("%d", price_candy);
	return 0;
}