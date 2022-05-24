#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int fun(int n)
//{
//    int m, y;
//    y = 0;
//    if (n >= 0)
//        m = n;
//    else
//        m = -n;
//    while (m != 0) {
//        /**********found**********/
//        y = y * 10 + m % 10;
//        /**********found**********/
//        m = m / 10;
//    }
//    y = (n >= 0) ? y : -y;
//    /**********found**********/
//    return y;
//}
//int main()
//{
//    int m1, m2;
//    scanf("%d %d", &m1, &m2);
//    printf("%d��������%d\t", m1, fun(m1));
//    printf("%d��������%d\n", m2, fun(m2));
//    return 0;
//}



//#include <stdio.h>
//void fun(int num, int r)
//{
//    int i = 0, a[32];
//    char b[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
//
//    do
//    {
//        a[i] = num % r;
//        /************found************/
//        num /= r;
//        i++;
//        /************found************/
//    } while (num > 0);
//    /************found************/
//    for (i--; i >= 0; --i)
//        printf("%c", b[a[i]]);
//}
//
//int main()
//{
//    int num, r;
//    printf("\n请输入一个数\n:");
//    scanf("%d %d", &num, &r);
//    fun(num, r);
//    printf("\n");
//    return 0;
//}



#include <stdio.h>
#include <math.h>

int fun(long n)
{
    int s1, s2;
    s1 = sqrt((double)n + 100);
    s2 = sqrt((double)n + 268);
    if (s1 == sqrt((double)n + 100) && s2 == sqrt((double)n + 268))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int main()
{
    long i;
    //FILE* fp = fopen("out.dat", "w");

    for (i = 1; i < 10000; i++)
    {
        if (fun(i))
        {
            printf("%ld\n", i);
           // fprintf(fp, "%ld\n", i);
        }
    }
    return 0;
}