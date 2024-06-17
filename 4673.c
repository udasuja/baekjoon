/*
 * 양의 정수 n에 대해서 d(n)을 n과 n의 각 자리수를 더하는 함수라고 정의하자. 
 * 예를 들어, d(75) = 75+7+5 = 87이다.
 *
 * 양의 정수 n이 주어졌을 때, 이 수를 시작해서 n, d(n), d(d(n)), d(d(d(n))), ...과 같은 무한 수열을 만들 수 있다. 
 *
 * 예를 들어, 33으로 시작한다면 다음 수는 33 + 3 + 3 = 39이고, 
 * 그 다음 수는 39 + 3 + 9 = 51,
 *  다음 수는 51 + 5 + 1 = 57이다. 
 *  이런식으로 다음과 같은 수열을 만들 수 있다.
 *
 * 33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...
 *
 * n을 d(n)의 생성자라고 한다. 
 * 위의 수열에서 33은 39의 생성자이고, 39는 51의 생성자, 51은 57의 생성자이다. 
 * 생성자가 한 개보다 많은 경우도 있다. 예를 들어, 101은 생성자가 2개(91과 100) 있다. 
 *
 * 생성자가 없는 숫자를 셀프 넘버라고 한다. 
 * 100보다 작은 셀프 넘버는 총 13개가 있다. 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97
 *
 * 10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
 * 
 * algorithm:
 * arr[10000]={0};//0으로 초기화
 *
 * i를 1부터 10000까지 키워간다.
 * for(i=1;i<=10000;i++)
 * 	if(arr[i]==1)
 * 		continue;
 * 각 숫자 마다의 수열을 생성한다.
 * 	sequence<-i;
 * 	while(sequence<=10000)
 * 		k=10;
 * 		sum<-sequence;
 * 		while(sequence>=k) //sequence는 k로 나누면서 각 1의 자리수를 sum에 더하고
 * 				  //sequence=n1n2n3...nk(ni는 각 자리수의 10이하의 수)일때 10의 몫의 나누기로
 *				 //sequence=n1n2n3...n(k-1)로 만든다.
 * 			sum<-sum+(sequence%k);
 * 			sequence<-sequence/k;
 * 		sum<-sum+sequence;//반복문 이후 sequence은 n1만 남을 것이고 이를 sum에 더해준다.
 * 		arr[sum]=1;
 * 		sequence<-sum;
 *
 *			
 * 그리고 수열로 쓰인 숫자는 제외한다.
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int * arr=(int*)calloc(10001,sizeof(int));

	for(i=1;i<=10000;i++)
	{
		if(arr[i]==1)
			continue;
		int sequence=i;
		printf("%d\n",i);
		while(sequence<=10000)//10000보다 작거나 같은 셀프 넘버를 구하는 것이 목표이기에 
				      //수열의 범위도 10000이하로 함
		{
			int k=10;
			int sum=sequence;
			while(sequence>=k)
			{
				sum=sum+(sequence%k);
				sequence=sequence/k;
			}
			sum=sum+sequence;
			if(sum<=10000)//sum의 값이 10000을 넘어가면 배열의 요소 번호를 초월하므로 그 이하로 함 
				arr[sum]=1;
			sequence=sum;
		}
	}
	free(arr);


	return 0;
}

