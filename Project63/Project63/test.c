#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//    int i, a, b, g, k, x, y, h;
//    int t = 0;
//    printf("输入地毯层数\n");
//    scanf("%d", &h);
//    printf("输入坐标\n");
//    scanf("%d%d", &x, &y);
//    for (i = 0; i < h; i++)
//    {
//        scanf("%d%d%d%d", &a, &b, &g, &k);
//        if (x <= (a + g) && x >= a && y >= b && y <= b + k)
//            t++;
//    }
//    if (t == 0)
//        t = -1;
//    printf("%d", t);
//    return 0;
//}

#include<stdio.h>
int main()
{
    int i, a[100], b[100], g[100], k[100], x, y, h;
    printf("输入地毯层数\n");
    scanf("%d", &h);
    for (i = 0; i < h; i++)
    {
        scanf("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);
    }
    int t = -1;
    scanf("%d%d", &x, &y);
    for (i = 0; i < h; i++)
    {
        if (x >= a[i] && x <= (a[i] + g[i]) && y >= b[i] && y <= (b[i] + k[i]))
            t = i + 1;
    }
    printf("%d", t);
    return 0;
}