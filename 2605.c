/*
학생들이 번호를 뽑는데 그 번호는 몇 칸 앞으로 갈지에 대한 번호이다.
첫번째 학생은 무조건 0을 뽑고 그 후 두번째 학생은 0,1중에 뽑는다.
1을 뽑으면 첫번째 학생을 기준으로 한칸 앞에서 줄은 선다.
0이면 그 뒤에 줄을 선다.
*/

#include <stdio.h>


int main(void)
{
	int num;
	int i = 1,j,go;
	int line[101] = { 0 };

	scanf_s("%d", &num);
	while (num--)
	{
		int jump_num;

		scanf_s("%d", &jump_num);
		if (jump_num == 0)
		{
			for (j = 0; line[j] != 0; j++);
			line[j] = i;
		}
		else
		{
			for (j = 0; line[j] != 0; j++);
			j -= 1;
			//이때 이 j번째 요소가 맨마지막 요소가 되고
			//이 요소를 jump_num만큼 뒤로 밀고
			//중간에 빈 공간에 student(i값)를 넣는다.
			for (go = jump_num; go; go--,j--)
			{
				line[j+1] = line[j];
			}
			j += 1;
			line[j] = i;
		}

		i++;
	}
	for (j = 0; line[j] != 0; j++)
	{
		printf("%d ", line[j]);
	}
	return 0;
}
