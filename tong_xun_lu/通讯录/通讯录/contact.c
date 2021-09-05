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
		printf("ͨѶ¼Ϊ�գ��������룡\n");
	}
	else
	{
		printf("%-20s%-5s%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼����!\n");
	}
	else
	{
		printf("������������");
		scanf("%s", &ps->data[ps->size].name);
		printf("���������䣺");
		scanf("%d", &ps->data[ps->size].age);
		printf("�������Ա�");
		scanf("%s", &ps->data[ps->size].sex);
		printf("������绰��");
		scanf("%s", &ps->data[ps->size].tele);
		printf("�������ַ��");
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
	printf("������Ҫɾ������ϵ�˵����֣�");
	scanf("%s", dname);
	ret = FindByName(ps, dname);
	if (ret != -1)
	{
		for (i = ret; i < ps->size - 1; i++)
		{
			ps->data[ret] = ps->data[ret + 1];
		}
		ps->size--;
		printf("����ϵ����ɾ��!\n");
	}
	else
	{
		printf("���޴���\n");
	}
}

void FindContact(struct Contact* ps)
{
	char fname[MAX_NAME];
	int ret;
	printf("������Ҫ������ϵ�˵�����:");
	scanf("%s", fname);
	ret = FindByName(ps, fname);
	if (ret == -1)
	{
		printf("���޴��ˣ�\n");
	}
	else
	{
		printf("%-20s%-5s%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸���ϵ�˵�����:");
	scanf("%s", mname);
	ret = FindByName(ps, mname);
	if (ret == -1)
	{
		printf("���޴��ˣ�\n");
	}
	else 
	{
		printf("%-20s%-5s%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s%-5d%-5s%-12s%-30s\n", ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,
			ps->data[ret].addr);
		printf("����������������");
		scanf("%s", &ps->data[ret].name);
		printf("�������������䣺");
		scanf("%d", &ps->data[ret].age);
		printf("�����������Ա�");
		scanf("%s", &ps->data[ret].sex);
		printf("������绰��");
		scanf("%s", &ps->data[ret].tele);
		printf("�������ַ��");
		scanf("%s", &ps->data[ret].addr);

	}
}