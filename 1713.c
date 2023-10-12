/*
입력:당선인의 수,추천횟수, 학생의 번호
출력:당선인

득표수가 많은 순서대로 출력하고 만약 같은 경우라면
늦게 표를 받은 순서대로 출력한다.
그리고 콘솔 창에서의 출력은 오름차순으로 출력한다.

비어있는 사진틀이 없을 때에는 표를 가장 적게 받은 애를 지운고
그 자리에 대체한다. 만약 같은 표를 2명이 받았다면 오래된 애를 지운다.


*/
#include <stdio.h>

int main(void)
{
	int n,picture[20][2] = {0};//사진틀의 개수 20개이하
	//picture라는 배열의 0번째 열에는 당선자를 1번째 열에는 득표수를 나타낸다.
	int student;//추천횟수
	int student_num[100]={0};//학생의 번호
	//2차원 배열로 0번째 열에는 투표를 받은 횟수를 나타내고

	scanf_s("%d %d", &n, &student);
	for (int i = 0; i < student; i++)
	//어느 학생이 얼마나 투표받고 어느 순서를 갖는지를 알기 위한 반복문
	{
		int num;

		scanf_s("%d", &num);
		student_num[num]++;//num이라는 번호를 가진 학생의 투표수를 1추가한다.

		for (int k = 0; k < n; k++)
		{
			if (picture[k][1] < student_num[num])
			//picture당선자의 순서를 나타내는 배열의 k번째 요소의 값보다 num배열의 num번째 요소의 값이 더 클때
			{
				for (int x = n - 1; x > k; x--)

				//마지막 요소를 제거하고 순서를 뒤로 밀기위해 x의 값은 마지막요소보다 1만큼 앞선다.
				//k번째에 num번째 요소의 값을 넣기위해 k보다 클때만 반복하도록 하였다.
				{
					picture[x][1] = picture[x - 1][1];
					//x번째 요소의 값은 그보다 1칸 앞선 요소의 값으로 대체한다.
					picture[x][0] = picture[x - 1][0];
				}
				picture[k][0] = num;//k의 값은 num이라는 학생의 번호가된다.
				picture[k][1] = student_num[num];
			}
			else if (picture[k][1] == student_num[num])
			//k번째 요소값과 num번째 요소값이 서로 같다면
			{
				//k번째 요소는 원래부터 있던 것이고 num요소는 새로 올라온 것이기에
				//k번째 요소를 num요소가 대체한다.
				picture[k][0] = num;
			}
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d", picture[i][0]);
	}

	return 0;
}