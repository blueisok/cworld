#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<errno.h>
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDE 20
#define DEFINESZ 3
struct Peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDE];
};
struct Contact
{
	struct Peoinfo* date;
	int size;//记录当前信息
	int capacity;
};
struct code  //储存账号密码
{
	char ter[50] ;
	char arr2[50];
};
enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};
void initcontact(struct Contact* ps);
void addcontact(struct Contact* ps);
void showcontact(const struct Contact* ps);//不需要修改数据，加const
void delcontact(struct Contact* ps);
void searchcontact(const struct Contact* ps);
void modifycontact(struct Contact* ps);
void sortcontact(struct Contact* ps);
void destroycontact(struct Contact* ps);
void savecontact(struct Contact* ps);
void readcontact(struct Contact* ps);
int chcode(struct code*ps);
void modifycode(struct code*ps);
void addid(struct code*ps);




