#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
int chcode()
{
	int i, m = 0;
	char arr2[50] = "1234";
	char arr[50] = { 0 }, ch;
	char ter[50] = "blueisok";
	char ter2[50] = { 0 };
	while (m < 3)
	{
		printf("�������˺�\n");
		scanf("%s", ter2);
		printf("����������\n");
		i = 0;
		while ((ch = _getch()) != '\r')//�������
		{
			if (ch == '\b' && i > 0)
			{
				printf("\b \b");
				i--;
			}
			else if (ch != '\b')
			{
				arr[i++] = ch;
				printf("*");
			}
		}
		arr[i] = '\0';
		printf("\n");
		if (strcmp(arr, arr2) != 0 || strcmp(ter2, ter) != 0)
		{
			printf("����������˺Ŵ���\n");
			m++;
		}
		else if (strcmp(arr, arr2) == 0 && strcmp(ter2, ter) == 0)
		{

			printf("�˺�������ȷ\n");
			return 1;

		}

	}
	printf("����������Σ��˳�����\n");
	return 0;
}
void initcontact(struct Contact* ps)
{
	ps->date = (struct Peoinfo*)malloc(DEFINESZ * sizeof(struct Peoinfo));
	if (ps->date == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFINESZ;
	readcontact(ps);
}
void checkcapacity(struct Contact* ps);//����checkcapacity
void readcontact(struct Contact* ps)
{
	struct Peoinfo tmp = { 0 };
	FILE* pr = fopen("C:\\c\\c2\\contact.date", "rb");
	if (pr == NULL)
	{
		printf("readcontact:%s", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(struct Peoinfo), 1, pr))
	{
		checkcapacity(ps);
		ps->date[ps->size] = tmp;
		ps->size++;
	}
	fclose(pr);
	pr = NULL;
}
void checkcapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//����
		struct Peoinfo* ptr = realloc(ps->date, (ps->capacity + 2) * sizeof(struct Peoinfo));
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}
void addcontact(struct Contact* ps)
{
	checkcapacity(ps);
	printf("����������\n");
	scanf("%s", ps->date[ps->size].name);
	printf("����������\n");
	scanf("%d", &(ps->date[ps->size].age));//���䲻������Ҫ��&
	printf("�������Ա�\n");
	scanf("%s", ps->date[ps->size].sex);
	printf("������绰\n");
	scanf("%s", ps->date[ps->size].tele);
	printf("�������ַ\n");
	scanf("%s", ps->date[ps->size].addr);
	printf("��ӳɹ�\n");
	ps->size++;

}
void showcontact(const struct Contact* ps)
{
	int i = 0;
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].addr);
		}
	}
}
int findname(const struct Contact* ps, char name[])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			return i;//�ҵ������±�
		}
	}
	return -1;//δ�ҵ�����-1
}
void delcontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("����Ҫɾ���˵����֣�\n");
	scanf("%s", name);
	int ret = findname(ps, name);
	if (-1 == ret)
	{
		printf("δ�ҵ�����\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}
void searchcontact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ����֣�\n");
	scanf("%s", name);
	int ret = findname(ps, name);
	if (-1 == ret)
	{
		printf("δ���ҵ��������\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			ps->date[ret].name,
			ps->date[ret].age,
			ps->date[ret].sex,
			ps->date[ret].tele,
			ps->date[ret].addr);
	}
}
void modifycontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("����Ҫ�޸ĳ�Ա�����֣�\n");
	scanf("%s", name);
	int ret = findname(ps, name);
	if (-1 == ret)
	{
		printf("δ�ҵ�����\n");
	}
	else
	{

		printf("����������\n");
		scanf("%s", ps->date[ret].name);
		printf("����������\n");
		scanf("%d", &(ps->date[ret].age));//���䲻������Ҫ��&
		printf("�������Ա�\n");
		scanf("%s", ps->date[ret].sex);
		printf("������绰\n");
		scanf("%s", ps->date[ret].tele);
		printf("�������ַ\n");
		scanf("%s", ps->date[ret].addr);
		printf("�޸ĳɹ�\n");
	}
}
//void sortcontact(struct Contact* ps)//����������ð������
//{
//	int i = 0;
//	int j = 0;
//	for ( i = 0; i < ps->size-1; i++)
//	{
//		for (j = 0; j < ps->size - 1 - i; j++)
//		{
//			if (strcmp(ps->date[j].name,ps->date[j+1].name)>0)
//			{
//				struct Peoinfo tem = ps->date[j];
//				ps->date[j] = ps->date[j + 1];
//				ps->date[j + 1] = tem;
//			}
//		}
//	}
//
//}

//ð������ĵڶ���ʵ��
void sortcontact(struct Contact* ps)
{
	int j = 0;
	int flag = 0;
	while (1)
	{
		flag = 0;
		for (j = 0; j < ps->size - 1; j++)
		{
			if (strcmp(ps->date[j].name, ps->date[j + 1].name) > 0)
			{
				struct Peoinfo tem = ps->date[j];
				ps->date[j] = ps->date[j + 1];
				ps->date[j + 1] = tem;
				flag = 1;//�����򣬸�ֵΪ1
			}
		}
		if (0 == flag)//��ȫû������ʱ������ѭ��
		{
			break;
		}

	}
}
void destroycontact(struct Contact* ps)//�ͷŶ�̬�ڴ�
{
	free(ps->date);
	ps->date = NULL;
}
void savecontact(struct Contact* ps)
{
	FILE* pr = fopen("C:\\c\\c2\\contact.date", "wb");
	if (pr == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(struct Peoinfo), 1, pr);
	}
	fclose(pr);
	pr = NULL;
}


