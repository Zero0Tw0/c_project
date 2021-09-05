#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


void InitContact(struct Contact* ps)
{
	memset(ps->data,0,sizeof(ps->data));
	ps->size = 0;
}

void ShowContact(struct Contact* ps)
{
	int i;
	if (ps->size == 0)
	{
		printf("通讯录为空，请先输入！\n");
	}
	else
	{
		printf("%-20s%-5s%-5s%-12s%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s%-5d%-5s%-12s%-30s\n",	ps->data[i].name, 
												ps->data[i].age, 
												ps->data[i].sex, 
												ps->data[i].tele, 
												ps->data[i].addr);
		}
	}
}

void AddContact(struct Contact *ps)
{
	if (ps->size >= MAX)
	{
		printf("通讯录已满!\n");
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", &ps->data[ps->size].name);
		printf("请输入年龄：");
		scanf("%d", &ps->data[ps->size].age);
		printf("请输入性别：");
		scanf("%s", &ps->data[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", &ps->data[ps->size].tele);
		printf("请输入地址：");
		scanf("%s", &ps->data[ps->size].addr);
		ps->size++;
	}

}

int FindByName(struct Contact* ps, char fname[MAX_NAME])
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, fname) == 0)
		{
			return  i;
		}
	}
	return -1;
}

void DelContact(struct Contact* ps)
{
	char dname[MAX_NAME];
	int ret;
	int i;
	ShowContact(ps);
	printf("请输入要删除人联系人的名字：");
	scanf("%s", dname);
	ret = FindByName(ps, dname);
	if (ret != -1)
	{
		for (i = ret; i < ps->size - 1; i++)
		{
			ps->data[ret] = ps->data[ret + 1];
		}
		ps->size--;
		printf("该联系人已删除!\n");
	}
	else
	{
		printf("查无此人\n");
	}
}

void FindContact(struct Contact* ps)
{
	char fname[MAX_NAME];
	int ret;
	printf("请输入要查找联系人的名字:");
	scanf("%s", fname);
	ret = FindByName(ps, fname);
	if (ret == -1)
	{
		printf("查无此人！\n");
	}
	else
	{
		printf("%-20s%-5s%-5s%-12s%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s%-5d%-5s%-12s%-30s\n", ps->data[ret].name,
											ps->data[ret].age,
											ps->data[ret].sex,
											ps->data[ret].tele,
											ps->data[ret].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char mname[MAX_NAME];
	int ret;
	printf("请输入要修改联系人的名字:");
	scanf("%s", mname);
	ret = FindByName(ps, mname);
	if (ret == -1)
	{
		printf("查无此人！\n");
	}
	else 
	{
		printf("%-20s%-5s%-5s%-12s%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s%-5d%-5s%-12s%-30s\n", ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,
			ps->data[ret].addr);
		printf("请重新输入姓名：");
		scanf("%s", &ps->data[ret].name);
		printf("请重新输入年龄：");
		scanf("%d", &ps->data[ret].age);
		printf("请重新输入性别：");
		scanf("%s", &ps->data[ret].sex);
		printf("请输入电话：");
		scanf("%s", &ps->data[ret].tele);
		printf("请输入地址：");
		scanf("%s", &ps->data[ret].addr);

	}
}