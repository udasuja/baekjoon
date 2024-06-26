/*
 * 입력으로 항승이가 작성한 내용에 있는 정수가 주어진다. 예를 들면, "정확하게 i개의 말은 참이다" 에서 i가 입력으로 주어진다. 
 *
 * 항승이가 칠판에 작성한 내용이 주어졌을 때, 총 몇 개의 내용이 참인지 구해보자.
 *
 * 입력
 * 첫째 줄에 항승이가 한 말의 개수 N이 주어진다. N은 1보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄에 항승이가 칠판에 작성한 내용에 있는 정수가 주어진다. 이 정수는 50보다 작거나 같은 음이 아닌 정수이다.
 *
 * 출력
 * 첫째 줄에 항승이가 칠판에 작성한 내용 중 몇 개가 참인지 출력한다. 만약 내용이 모순이라면 -1을 출력하고, 가능한 답이 여러가지라면 가장 큰 값을 출력한다.
 *
 * 1
 * 0
 * =>
 * 정확하게 0개의 말은 참이다.
 * 출력 -1(모순)
 * 이 명제가 참이라 가정하면 전체 명제 중 참인 명제는 1개가 된다. 즉 이 명제는 거짓이 된다. 만약 이 명제가 거짓이라 가정하면 전체 명제 중 참인 명제는 0개가 된다. 이때 이 명제는 참이 되므로 참이면서 거짓이 되기에 모순이 발생한다.
 *
 * 4
 * 0 1 2 3
 * 출력 1
 * =>
 * 정확하게 0개의 말은 참이다.--1
 * 정확하게 1개의 말은 참이다.--2
 * 정확하게 2개의 말은 참이다.--3
 * 정확하게 3개의 말은 참이다.--4
 *
 * 1번째 명제가 참이라 가정하면 이 명제는 거짓이 된다.
 * 2번째 명제가 참이라 가정하면 이 명제는 참이 된다.
 * 3번째 명제가 참이라 가정하면 나머지 1,2,4 명제들은 거짓이 되기에 전체 명제 중 참인 명제는 1개가 되기에 이 명제는 거짓이 된다.
 * 4번째 명제가 참이라 가정하면 나머지 1,2,3 명제들은 거짓이 되기에 전체 명제 중 참인 명제는 1개가 되기에 이 명제는 거짓이 된다.
 * 즉 2번째 명제 1개만 참이다.
 *
 * 2
 * 1 1
 * 출력 0
 * =>
 * 정확하게 1개의 말은 참이다. --1
 * 정확하게 1개의 말은 참이다. --2
 *
 * 1번째 명제가 참이라 가정하면 2번째 명제는 첫번째 명제와 동일한 명제이기에 2번째 명제 또한 참이 되므로 전체 명제 중 참인 명제는 2개가 되므로 1번째 명제와 2번째 명제는 거짓이 된다.
 *
 * 6
 * 0 3 1 3 2 3
 * 출력 3
 * =>
 * 정확하게 0개의 말은 참이다. --1
 * 정확하게 3개의 말은 참이다. --2
 * 정확하게 1개의 말은 참이다. --3
 * 정확하게 3개의 말은 참이다. --4
 * 정확하게 2개의 말은 참이다. --5
 * 정확하게 3개의 말은 참이다. --6
 *
 * 1번째 명제가 참이라 가정하면 이 명제는 거짓이 된다.
 * 2번째 명제가 참이라 가정하면 4번째 명제와 6번째 명제는 이 2번째 명제와 같기에 이 또한 참이 되고 1,3,5번째 명제는 자연스레 거짓이 된다. 즉 전체 명제 중 참인 명제는 3개가 된다.
 *
 * 알고리즘:
 * 51개의 요소를 갖는 배열을 선언하고 두 번째 입력 각각의 값에 해당하는 요소 번호에 그와 같은 명제의 빈도수를 저장한다.
 *
 * 그리고 그 중에서 빈도수가 가장 큰 값을 출력한다. 
 */

#include <stdio.h>
#define MAX(a,b) a>b?a:b

int main(void)
{
	int n;
	int i=0,max=-1;//만약 모든 명제가 거짓이면 arr[0]==0이기에 max의 최종 출력은 0이된다.
		       //하지만 명제가 0만이 존재하여 모순이 발생하면 arr[0]<1이 되기에 
		       //if(arr[0]==0)에 걸리지 않게 되므로 출력은 max의 초기값인 -1이 출력된다. 
	int arr[51]={0};
	scanf("%d",&n);
						
	for(i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
														
		arr[k]+=1;
																}
	for(i=0;i<52;i++)
	{
		if(arr[i]==i)
			max=MAX(max,i);
	}
		printf("%d",max);
		return 0;
}

