/*
입력: 당선인의 수,투표용지의 수,학생의 번호

출력: 당선인의 번호

조건:
학생들이 추천을 시작하기 전에 모든 사진틀은 비어있다.
어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다.
비어있는 사진틀이 없는 경우에는 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제하고,
그 자리에 새롭게 추천받은 학생의 사진을 게시한다. 
이때, 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는
그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제한다.
현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
사진틀에 게시된 사진이 삭제되는 경우에는 해당 학생이 추천받은 횟수는 0으로 바뀐다.

사진틀에 즉석으로 넣고
출력할때는 오름차순으로 출력해야 되는 것 같다.
*/
#include <stdio.h>

typedef struct
{
	int vote;//투표수를 저장한다.
	int number;//투표순서를 저장한다.
	int people;//학생의 번호를 저장한다.
}STUDENT;

int main(void)
{
	int n, total;
	STUDENT st[20] = { 0 };

	//처음 입력값은 st배열에 저장하고 투표수와 투표순서 또한 저장한다.
	//배열의 마지막 요소의 번호는 n-1이 되고 n-1이 될 때까지 입력한 학생의 투표수와 순서를 저장한다.(0부터 n-1까지 차례대로)
	//만약 n-1까지 다 차면 입력받은 후보와 투표수가 일치하는 것들 중 투표순서가 가장 빠른 것의 자리를 대체한다.


	scanf_s("%d %d", &n, &total);

	for (int i = 0; i < total; i++)
	{
		int student,k;
		scanf_s("%d", &student);

		if (st[n-1].people==0)
		//st라는 배열의 n-1까지 후보가 가득 차지 않을 경우
		{
			int zero;
			for (k = 0; k < n; k++)
			{
				if (st[k].people == student)
				//st배열에 student라는 번호를 갖은 학생이 존재할 경우
				{
					st[k].vote++;
					st[k].number = i;
					break;
				}
				else if (st[k].people == 0)
				//st배열에 people 값이 0인 것이 나오면
				{
					zero = k;
					break;
				}
			}
			if (st[k].people!=student)
			//st[k]가 student라면 st배열에 student가 존재하다는 것이고
			//그것이 아니라면 st배열에는 student라는 학생의 번호가 없다는 것이다.
			{
				st[zero].people = student;
				st[zero].vote++;
				st[zero].number = i;
			}			
		}
		else
		//가득 찬 경우
		{
		//입력받은 학생의 번호가 st배열에 존재하는지 아닌지부터 살펴본다.
			for (k = 0; k < n; k++)
			{
				if (st[k].people == student)
				//위 조건이 존재하는 경우 k는 n보다 작은 값을 갖는다.
				{
					st[k].vote++;
					st[k].number = i;
					break;
				}
			}
			if (k == n)
			//st배열에 student라는 학생의 번호가 없는 경우
			//없으면 새로 입력받은 것이기에 득표수는 1일 것이다.
			{
				int old=i;//이 변수는 득표수가 1이고 투표번호가 가장 빠른 애를 지우기위해 사용된다.
				for (k = 0; k < n; k++)
				{
					if ((st[k].vote==1) && (old > st[k].number))
					//st배열에 k번째 요소의 학생의 득표수가 1이고 투표순서가 old보다 낮으면
					//그것이 가장 오래된 것이기에 old에 그것을 저장한다.
					{

						
						old = k;//투표받은지 가장 오래된 학생을 저장한다. 
					}
				}
				printf("%d;", k);
				st[old].people = student;
				st[old].number = i;
				printf("%d;%d;",old, st[old].people);
			}
		}
	}
	printf("%d %d %d", st[0].number, st[1].number, st[2].number);
	return 0;
}