/*
입력: 당선인의 수,투표용지의 수,학생의 번호

출력: 당선인의 번호

일단 두가지 배열을 만들고
하나는 받은 투표의 수
하나는 순서를 저장한다.

첫번째 반복문에 투표를 받고 그 순서를 저장한다.
(같은 득표수라면 오래된 애가 지워진다.)
두번째 반복문에는 첫번째 반복문을 토대로 당선인을 뽑는다.
-vote즉 득표수가 0인에가 나오면 continue한다.
-득표수가 0보다 크면 당선인 배열에 0부터 집어넣는다.

세번째 반복문에는 당선인의 배열을 오름차순으로 설정한다.
*/

#include <stdio.h>

int main(void)
{
	int vote[100]={0}, number[100];
	int student_m=0;//학생 번호의 최대값을 구한다.
	int student[20][2]={0};//0열에는 학생의 번호를 1열에는 득표수를 넣는다.
	int n, vote_paper;

	scanf_s("%d %d", &n, &vote_paper);
	for (int i = 0; i < vote_paper; i++)
	{
		int num;

		scanf_s("%d", &num);
		student_m = student_m < num ? num : student_m;
		//지금 입력받은 학생의 번호가 이전까지의 최대값보다 크면 그것이 학생 번호의 최대값이된다.

		vote[num]++;//num이라는 번호를 갖은 학생의 득표수를 1증가시킨다.
		number[num] = i;//num이 투표를 받은 순서는 i번째가 되고
		//나중에 다시 받으면 그때 i로 순서가 초기화된다.
	}
	for (int k = 0; k <= student_m; k++)
	{
		if (vote[k] == 0)
		//득표수가 0인 학생이면 그냥 무시한다.
		{
			continue;
		}
		else
		{
			for (int j = 0; j < n; j++)			
			{
				if (student[j][1] < vote[k])
					//j번째 당선인의 득표수보다 k번째 학생의 득표수가 더 많은경우
				{
					for (int j2 = n - 1; j2 > j; j2--)
					//student배열의 j번째 요소에 vote배열의 k번째 값을 집어넣어야되므로
					//뒤로 한칸씩 옮긴다.
					{
						student[j2][1] = student[j2 - 1][1];//득표수를 뒤로 한 칸씩 옮긴다.
						student[j2][0] = student[j2-1][0];//학생의 번호도 뒤로 한 칸씩 옮긴다.
					}
					student[j][1] = vote[k];
					student[j][0] = k;
					break;
				}
				else if(student[j][1] == vote[k])
				//student배열에 j번째 학생의 득표수가 k번째 학생이랑 일치할때
				{
					//j+1번째 학생의 득표수가 k보다 작으면 j번째에 k학생을 쓰고
					//같으면 다시 j+2번째 학생의 득표수랑 비교한다.
					while(j<n)
					//오래된 것을 뒤에다가 배열한다.
					{
						int change;
						//순서가 더 오래된것을 저장한다.
						if (student[j + 1][1] == vote[k])
						{
							if (number[student[j][0]] < number[student[j + 1][0]])
							//student[j]에 해당하는 학생의 득표순서가 student[j+1]에 해당하는 학생의 득표순서보다 작으면
							//더 빨리 받은 것이 된다. 즉 더 오래되었다.
							{
								change = student[j][0];
								student[j][0] = student[j+1][0];
								student[j + 1][0] = change;
								
							}
							j++;
							//이 조건문 후 다음 반복의 조건중 j+1은 j++을 고려하여 (++j)+1이 된다.
						}
//오래된 것을 뒤에다가 놓으면서 student[j+1]학생이 k번째 학생보다 득표수가 작아지면(큰 순서대로 배열하므로 클리는 없다.)
//가장 오래된 것을 k번째 학생이 대체한다.
						else
						{
							student[j][0] = k;
							//student[j]가 k학생과 득표수가 같으며 가장 오랜되 애이므로
							//애를 k번째 학생으로 대체한다.
							break;
						}
					}
					
				}
			}
		}
	}
	//오름차순을 위한 반복문
	for (int o = 1; o <= student_m; o++)
	{
		
		for (int o2 = 0; o2 < n; o2++)
		{
			
			if (student[o2][0] == o)
			//o가 1부터 학생 번호의 최대값까지 커지는데
			//
			//student배열에 o2에 o가 존재하면 그것을 출력한다.
			{
				printf("%d", o);
				break;
			}
		}
	}
	return 0;
}