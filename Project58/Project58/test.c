#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
int input = 0, ter = 0;
struct Contact con;
struct code id;
void mainmenu()
{
	printf("**********账号管理**********\n");
	printf("***1.登入账号**************\n");
	printf("***2.修改账号**************\n");
    printf("***3.创建用户ID**************\n");
	printf("***0.直接退出**************\n");
	printf("***************************\n");
}
void menu()
{
	printf("******电话通讯录管理系统********\n");
	printf("**1.添加通讯录    2.删除通讯录**\n");
	printf("***3.查找通讯录   4.修改通讯录***\n");
	printf("***5.展示成员     6.通讯录排序***\n");
	printf("***7.保存通讯录   0.退出通讯录***\n");
	printf("********************************\n");
}
void mainfun() //主要的功能函数
{
	if (chcode(&id))
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
}
int main()
{
	
	initcontact(&con);//初始化通讯录
	mainmenu();
	printf("请选择->");
	scanf("%d", &ter);
	switch (ter)
	{
	case 1: mainfun();//进入登入系统，然后进入通讯录
	       break;
	case 2: modifycode(&id);//修改账号
		   break;
	case 3: addid(&id);//添加账号
		   mainfun();
		   break;
	case 0: break;
	default: printf("输入错误，直接退出\n");
		break;
	}
	return 0;
}