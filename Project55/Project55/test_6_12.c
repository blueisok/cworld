#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void menu()
{
	printf("******�绰ͨѶ¼����ϵͳ********\n");
	printf("**1.���ͨѶ¼    2.ɾ��ͨѶ¼**\n");
	printf("***3.����ͨѶ¼   4.�޸�ͨѶ¼***\n");
	printf("***5.չʾ��Ա     6.ͨѶ¼����***\n");
	printf("***7.����ͨѶ¼   0.�˳�ͨѶ¼***\n");
	printf("********************************\n");
}
int main()
{
	int input = 0;
	struct Contact con;
	initcontact(&con);//��ʼ��ͨѶ¼
	if (chcode())
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
	return 0;
}