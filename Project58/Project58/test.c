#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
int input = 0, ter = 0;
struct Contact con;
struct code id;
void mainmenu()
{
	printf("**********�˺Ź���**********\n");
	printf("***1.�����˺�**************\n");
	printf("***2.�޸��˺�**************\n");
    printf("***3.�����û�ID**************\n");
	printf("***0.ֱ���˳�**************\n");
	printf("***************************\n");
}
void menu()
{
	printf("******�绰ͨѶ¼����ϵͳ********\n");
	printf("**1.���ͨѶ¼    2.ɾ��ͨѶ¼**\n");
	printf("***3.����ͨѶ¼   4.�޸�ͨѶ¼***\n");
	printf("***5.չʾ��Ա     6.ͨѶ¼����***\n");
	printf("***7.����ͨѶ¼   0.�˳�ͨѶ¼***\n");
	printf("********************************\n");
}
void mainfun() //��Ҫ�Ĺ��ܺ���
{
	if (chcode(&id))
	{
		do
		{
			menu();
			printf("��ѡ��:>\n");
			scanf("%d", &input);
			switch (input)
			{
			case ADD:
				addcontact(&con);//���ͨѶ¼
				break;
			case DEL:
				delcontact(&con);//ɾ��ͨѶ¼
				break;
			case SEARCH://����ĳ���˵���Ϣ
				searchcontact(&con);
				break;
			case MODIFY://�޸�ĳ������Ϣ
				modifycontact(&con);
				break;
			case SHOW:
				showcontact(&con);//����ַ���ٶȿ�
				break;
			case SORT:
				sortcontact(&con);
				break;
			case SAVE:
				savecontact(&con);//�����ļ�
				break;
			case EXIT:
				savecontact(&con);//�����ļ�
				destroycontact(&con);
				printf("�˳�����\n");
				break;
			default:
				printf("�����������������\n");
				break;
			}
		} while (input);
	}
}
int main()
{
	
	initcontact(&con);//��ʼ��ͨѶ¼
	mainmenu();
	printf("��ѡ��->");
	scanf("%d", &ter);
	switch (ter)
	{
	case 1: mainfun();//�������ϵͳ��Ȼ�����ͨѶ¼
	       break;
	case 2: modifycode(&id);//�޸��˺�
		   break;
	case 3: addid(&id);//����˺�
		   mainfun();
		   break;
	case 0: break;
	default: printf("�������ֱ���˳�\n");
		break;
	}
	return 0;
}