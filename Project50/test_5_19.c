#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int a = 2;
//	printf("%d", 5 > a >1);//结果为0；   5>a为真结果大于等于1，1>1为假
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2, c = 3, d = 4, m = 2, n = 2;
//	(m = a > b) && (n = c > d);
//	printf("%d", n); //结果为n=2?
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//	double x=0.0, y = 0.0;
//	printf("请输入x的值\n");
//	scanf("%lf", &x);
//	if (x<=-10)
//	{
//		y = x;
//	}
//	else if (x > -10 && x <= 0)
//	{
//		y = 2*x + 3;
//	}
//	else if (x > 0 && x <= 10)
//	{
//	    y=3 * x - 11;
//	}
//	else
//	{
//		y = x / 10.0 + 1;
//	}
//	printf("输出y:%lf ", y);
//	return 0;
//}

//#include<stdio.h>
//int fun(int n)
//{
//	if (n==0)
//	{
//		return 0;
//	}
//	return (n+ fun(n-1));
//}
//int main()
//{
//	int i,sum=0;
//	printf("请输入一个n\n");
//	scanf("%d", &i);
//	sum=fun(i);
//	printf("%d", sum);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n = 0, sum = 0;
//	printf("请输入一个n:\n");
//	scanf("%d", &n);
//	while (n)
//	{
//		sum += n;
//		n--;
//	}
//	printf("sum:%d", sum);
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2, c = 3, d = 4;
//	d = a <= b || ++c;
//	printf("%d", c);
//	return 0;
//}