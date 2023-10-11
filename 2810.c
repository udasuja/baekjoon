/*
입력:좌석의 수
	 좌석의 종류(S는 일반좌석을 의미 L은 커플 석을 의미)
출력:컵홀더를 쓸 수 있는 사람의 수
ex)SLLS라면 컵홀더는 *S*LL*S*가된다. 이때 *은 컵홀더를 의미한다.
LL은 한 개의 S라고 생각한다.
*/

void Number_of_cupholder(int*, int*,int);

#include <stdio.h>

int main(void)
{
	int n,people=0,seat=0;
	

	scanf_s("%d", &n);
	//좌석의 수
	Number_of_cupholder(&people, &seat,n);
	//people와 seat의 주소값을 반환해 holder의 개수와 인원을 인계받는다.
	seat > people ? printf("%d", people) : printf("%d", seat);
	//holder의 개수가 사람 수보다 많으면 사람 수 만큼 출력하고
	//적으면 즉 사람 수가 더 많으면 시트 수(=holder의 개수) 만큼만 출력한다.
	return 0;
}

void Number_of_cupholder(int* people, int* seat,int n)
{
	int s = 0;
	char kind_of_seat;
	for (int i = 0; i < n; i++)
	{
		scanf_s(" %c", &kind_of_seat);
		//( %c) %c앞에 한 칸뛴 이유는 입력버퍼를 초기화 하기 위해서다.
		if (kind_of_seat == 'S' || kind_of_seat == 's')
		{
			(*people)++;//사람의 수를 의미한다.
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
	(* seat) -= s;//seat라는 변수는 의자에 달려있는 컴홀더의 개수를 의미한다.
}