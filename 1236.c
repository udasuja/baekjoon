/*
.으로 된 직사각형 모양의 모든 행과 열에 한 명 이상의 X가 있어야 되는데
위 조건을 만족하는 최소 X의 개수를 출력한다.

입력:행 열
     .과 X로 이뤄진 직사각형
출력:최소 X의 개수
ex)
3 5
XX...
.XX..
...XX
출력:0

ex)
5 8
....XXXX
........
XX.X.XX.
........
........
출력:3

3열에만 X가 없다.=>1이 없는 요소 번호의 개수 1개
2행,4행,5행에 X가 없다. => 1이 없는 요소 번호의 개수 3개
즉 둘 중에 큰 3이 출력되야된다.

풀이:malloc함수로 2차원 행렬의 행만큼의 크기와 열만큼의 크기를 가진 1차원 배열 각각을 선언한다.
getchar()함수로 .나 X를 바로바로 입력받으면서 X가 입력되면 그때의 행과 열에 X에 있다는 표시로 각 1차원 배열의 값을 1로 만든다.
반복문을 통해 행과 열을 검사하면서 1이 없는 요소 번호의 개수를 구하며 행과 열 중 개수가 가장 큰 값을 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) a>b?a:b


typedef struct
{
    int* row;
    int* col;
}MATRIX;

typedef struct
{
    int row;
    int column;
}COUNT;

int main(void)
{
    COUNT count={0,0};
    MATRIX matrix;
    int r,co,ch,i,k;
    

    scanf_s("%d %d", &r,&co);
    matrix.row = (int*)malloc(sizeof(int) * r);
    matrix.col = (int*)malloc(sizeof(int) * co);

    ch = getchar();//scanf로 인한 입력버퍼에 남아있는 \n 제거
    for (i = 0; i < r; i++)//X가 입력된 행과 열을 구분하는 반복문
    {
        for (k = 0;; k++)
        {
            ch = getchar();
            if (ch == 'X')
            {
                matrix.row[i] = matrix.col[k] = 1;
            }
            else if (ch == '\n')
            {
                break;
            }
        }
    }
    for (i = 0; i < r; i++)//행 중에서 X가 하나도 없는 행의 개수를 센다.
    {
        if (matrix.row[i] != 1)
            count.row += 1;
    }
    for (k = 0; k < co; k++)//열 중에서 X가 하나도 없는 열의 개수를 센다.
    {
        if (matrix.col[k] != 1)
            count.column += 1;
    }
    printf("%d", MAX(count.row, count.column));//1이 하나도 없는 행의 개수와 열의 개수 중 큰 것을 출력한다.
    return 0;
}