#include <stdio.h>
#define max_m_n 25

int main()
{
    int row_a = 0, row_b = 0, column_a = 0, column_b = 0; // 矩阵A/B的行列数
    int a[max_m_n][max_m_n], b[max_m_n][max_m_n];

    scanf("%d %d", &row_a, &column_a);
    for (int i = 0; i < row_a; i++)
        for (int j = 0; j < column_a; j++)
            scanf("%6d", &a[i][j]); // 输入A的矩阵
    scanf("%d %d", &row_b, &column_b);
    for (int i = 0; i < row_b; i++)
        for (int j = 0; j < column_b; j++)
            scanf("%6d", &b[i][j]); // 输入B的矩阵

    // 判断a和b是否可以执行矩阵相乘运算
    if (column_a == row_b ||
        (column_a == 1 && column_a == 1) ||
        (column_b == 1 && row_b == 1))
    { // 可以执行c=a*b运算
        int c[max_m_n][max_m_n];
        for (int i = 0; i < row_a; i++)
            for (int j = 0; j < column_b; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < row_b; k++)
                    c[i][j] += a[i][k] * b[k][j];
            }

        // 对c进行按格式输出
        for (int i = 0; i < row_a; i++)
        {
            for (int j = 0; j < column_b; j++)
                printf("%10d", c[i][j]);
            printf("\n"); // 换行
        }
    }
    else
    { // 无法进行矩阵乘法
        printf("Incompatible Dimensions\n");
    }
    return 0;
}

/*
例子 1
2 2
     1     2
     3     4
3 1
     1
     2
     3

例子 2
2 2
     1     2
     3     4
2 3
     1     2     0
     0     3     4

例子 3
4 1
   123
   345
   567
   789
1 4
  -123   345  -567   789
 */