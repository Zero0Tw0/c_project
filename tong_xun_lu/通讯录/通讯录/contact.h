#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>

enum peole
{
	exit,
	show,
	add,
	del,
	find,
	modify,
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
	struct PeoInfo data[MAX];
	int size;
};


void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void DelContact(struct Contact* ps);
void FindContact(struct Contact* ps);
void ModifyContact(struct Contact* ps);