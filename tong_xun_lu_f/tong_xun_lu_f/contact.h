#define INIT_NUM 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>


enum people
{
	exit_,
	show,
	add,
	del,
	find,
	modify,
	sort
};



struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct PeoInfo* data;
	int size;
	int max;
};


void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void DelContact(struct Contact* ps);
void FindContact(struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SortConatct(struct Contact* ps);

void LoadContact(struct Contact*ps);
void SaveContact(struct Contact* ps);