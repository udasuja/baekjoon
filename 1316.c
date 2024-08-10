/*그룹 단어란 단어에 존재하는 모든 문자에 대해서, 
 * 각 문자가 연속해서 나타나는 경우만을 말한다. 
 * 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, 
 * kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, 
 * aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
 * 단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.
 *
 * 입력
 * 첫째 줄에 단어의 개수 N이 들어온다. 
 * N은 100보다 작거나 같은 자연수이다. 
 * 둘째 줄부터 N개의 줄에 단어가 들어온다. 
 * 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.
 *
 * 출력
 * 첫째 줄에 그룹 단어의 개수를 출력한다.
 *
 *
 * algorithm:
 * 배열에 각 알파벳에 해당하는 요소 번호에 마지막으로 입력 받은 번호를 저장한다.
 * 그리고 다음 시행 때 같은 문자가 저장됐을때 마지막으로 입력 받은 번호+1보다 크면 그룹이 아니다. 
 */
#include <stdio.h>

int main(void)
{
	int n;
	int i,group=-1;
	scanf("%d",&n);
	
	for(i=0;i<=n;i++)//조건이 i<=n인 이유는 처음 scanf에 의해 입력버퍼에 \n이 남게되는데 
			 //이를 밑의 반복문의 조건에서 c=getchar()에의해 c에 저장되어 i=0일때는 그냥 날라가니
			 //조건을 i<n이 아닌 i<=n으로 하였다.
	{
		char c;
		int arr[26]={0},k,check=1;
		for(k=1;(c=getchar())!='\n';k++)
		{
			int alphabat=c-'a';
			if(arr[alphabat]!=0&&arr[alphabat]!=k-1)//c라는 변수에 저장된 문자가
								//배열에 적어도 1번 저장되었고
								//마지막으로 저장된 시행번호가
								//현재의 시행번호보다 1적지 않을때
								//즉 현재의 시행번호가 k일때
								//k-1이 아니라면 그룹 조건에서 어긋난다.
				check=0;//그룹이 아님을 표시
			arr[alphabat]=k;
		}

		group+=check;
	}
	printf("%d",group);
	return 0;
}