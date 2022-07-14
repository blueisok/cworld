#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int fx[9] = { 0,1,2,2,-1,-2,1,-2,-1 };
const int fy[9] = { 0,2,1,-1,2,1,-2,-1,-2};
int main()
{
    int i, j;
    int bx, by, mx, my;
    int arr[40][40] = { 0 };
    int arr2[40][40] = { 0 };//马控制的点
    printf("输入b点坐标和马坐标\n");
    scanf("%d%d%d%d", &bx, &by, &mx, &my);
    bx += 2; by += 2; mx += 2; my += 2;
    arr[2][1] = 1;//初始化原点上方点为零
    arr2[mx][my] = 1;
    for (i = 0; i <= 8; i++)
        arr2[mx + fx[i]][my + fy[i]] = 1;
    for (i = 2; i <= bx; i++)
    {
        for (j = 2; j <= by; j++)
        {
            if (arr2[i][j] == 1)
                continue;
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    printf("%d", arr[bx][by]);
    return 0;
}