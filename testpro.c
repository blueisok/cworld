#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

////阶乘递归实现
////递归公式 n=1, result=1
////        n>1, result*fun(result-1)
//int fun(int result)
//{
//	if (result == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return result * fun(result - 1);
//
//	}
//}
//int main()
//{
//	printf("result is %d\n", fun(7));
//	return 0;
//}

//阶乘循环实现
//int fun(int n)
//{
//	int result=1;
//	while (n >1)
//	{
//		result *= n;
//		n--;
//	}
//	return result;
//}
//int main()
//{
//	printf("result is %d\n", fun(7));
//	return 0;
//}

//斐波那契数列
//递归实现
//递归公式  n=1,n=2 时 ，result=1；
//          n>2时      ，result=fun(n-1)+fun(n-2);

//int fun(int n)
//{
//	if (1 == n || 2 == n)
//	{
//		return 1;
//	}
//	else
//	{
//		return fun(n - 1) + fun(n - 2);
//	}
//}
//int main()
//{
//	printf("result is %d\n", fun(5));
//	return 0;
//}

//循环实现
int fun(int n)
{
	int a ;
	int b = 1;
	int c=1;
	while (n > 2)
	{
		a= b;
		b = c;
		c = a + b;
		n--;
	}
	return c;

}
int main()
{
	printf("result is %d\n", fun(3));
	return 0;
}