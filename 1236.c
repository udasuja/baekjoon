/*
.���� �� ���簢�� ����� ��� ��� ���� �� �� �̻��� X�� �־�� �Ǵµ�
�� ������ �����ϴ� �ּ� X�� ������ ����Ѵ�.

�Է�:�� ��
     .�� X�� �̷��� ���簢��
���:�ּ� X�� ����
ex)
3 5
XX...
.XX..
...XX
���:0

ex)
5 8
....XXXX
........
XX.X.XX.
........
........
���:3

3������ X�� ����.=>1�� ���� ��� ��ȣ�� ���� 1��
2��,4��,5�࿡ X�� ����. => 1�� ���� ��� ��ȣ�� ���� 3��
�� �� �߿� ū 3�� ��µǾߵȴ�.

Ǯ��:malloc�Լ��� 2���� ����� �ุŭ�� ũ��� ����ŭ�� ũ�⸦ ���� 1���� �迭 ������ �����Ѵ�.
getchar()�Լ��� .�� X�� �ٷιٷ� �Է¹����鼭 X�� �ԷµǸ� �׶��� ��� ���� X�� �ִٴ� ǥ�÷� �� 1���� �迭�� ���� 1�� �����.
�ݺ����� ���� ��� ���� �˻��ϸ鼭 1�� ���� ��� ��ȣ�� ������ ���ϸ� ��� �� �� ������ ���� ū ���� ����Ѵ�.
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

    ch = getchar();//scanf�� ���� �Է¹��ۿ� �����ִ� \n ����
    for (i = 0; i < r; i++)//X�� �Էµ� ��� ���� �����ϴ� �ݺ���
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
    for (i = 0; i < r; i++)//�� �߿��� X�� �ϳ��� ���� ���� ������ ����.
    {
        if (matrix.row[i] != 1)
            count.row += 1;
    }
    for (k = 0; k < co; k++)//�� �߿��� X�� �ϳ��� ���� ���� ������ ����.
    {
        if (matrix.col[k] != 1)
            count.column += 1;
    }
    printf("%d", MAX(count.row, count.column));//1�� �ϳ��� ���� ���� ������ ���� ���� �� ū ���� ����Ѵ�.
    return 0;
}