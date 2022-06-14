#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void menu()
{
	printf("******电话通讯录管理系统********\n");
	printf("**1.添加通讯录    2.删除通讯录**\n");
	printf("***3.查找通讯录   4.修改通讯录***\n");
	printf("***5.展示成员     6.通讯录排序***\n");
	printf("***7.保存通讯录   0.退出通讯录***\n");
	printf("********************************\n");
}
int main()
{
	int input = 0;
	struct Contact con;
	initcontact(&con);//初始化通讯录
	if (chcode())
	{
		do
		{
			menu();
			printf("请选择:>\n");
			scanf("%d", &input);
			switch (input)
			{
			case ADD:
				addcontact(&con);//添加通讯录
				break;
			case DEL:
				delcontact(&con);//删除通讯录
				break;
			case SEARCH://查找某个人的信息
				searchcontact(&con);
				break;
			case MODIFY://修改某个人信息
				modifycontact(&con);
				break;
			case SHOW:
				showcontact(&con);//传地址，速度快
				break;
			case SORT:
				sortcontact(&con);
				break;
			case SAVE:
				savecontact(&con);//保存文件
				break;
			case EXIT:
				savecontact(&con);//保存文件
				destroycontact(&con);
				printf("退出程序\n");
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
			}
		} while (input);
	}
	return 0;
}