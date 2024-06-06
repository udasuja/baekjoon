/*
 * 입력
 * 첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.
 *
 * 단어는 크로아티아 알파벳으로 이루어져 있다. 문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.
 *
 * 출력
 * 입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
 *
 * č	c=
 * ć	c-
 * dž	dz=
 * đ	d-
 * lj	lj
 * nj	nj
 * š	s=
 * ž	z=
 * 
 * 문자열을 입력받고 switch문을 이용하여 입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이뤄졌는지 출력한다.
 */
#include <stdio.h>
#include <string.h>

void other(int *i,int*al_num)
{
	*i +=1;
	*al_num +=1;
}

int main(void)
{
	int str_len;
	int i=0;
	int al_num=0;
	char arr[101];//널문자 포함
	
	scanf("%s",arr);
	str_len=strlen(arr);
	while(arr[i]>'\0')
	{
	
		switch(arr[i])
		{
			case'c':
				if(arr[i+1]=='='||arr[i+1]=='-')//c=이나 c-일때
				{
					i+=2;
					al_num+=1;
				}
				else//c@일경우 c만 인식
					other(&i,&al_num);
				break;

			case's':case'z':
				if(arr[i+1]=='=')//s=이나 z=일때
				{
					i+=2;
					al_num+=1;
				}
				else//s@나 z@일 경우 s나 z만 인식한다.
					other(&i,&al_num);
				break;

			case'd':
				if(arr[i+1]=='z'&&arr[i+2]=='=')//dz=일때
				{
					i+=3;
					al_num+=1;
				}
				else if(arr[i+1]=='-')//d-일때
				{
					i+=2;
					al_num+=1;
				}
				else//d@일 경우 d만 인식한다.
					other(&i,&al_num);	
				break;
			case'n':case'l':
				if(arr[i+1]=='j')
				{
					i+=2;
					al_num+=1;
				}
				else
					other(&i,&al_num);	
				break;
			
			default://a나 k와 같은 크로아티아 알파벳을 구성하지 않는 영문자 알파벳
				other(&i,&al_num);
				break;
		}
	}
	printf("%d",al_num);
}
