#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu()
{
	printf("..........................................\n");
	printf("....   1.show                 2.add   ....\n");
	printf("....   3.del                  3.find  ....\n");
	printf("....   5.modify               6.sort  ....\n");
	printf("....   0.exit_                         ....\n");
	printf("..........................................\n");
	printf("请选择对通讯录的操作：");
}



int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);

	//通讯录操作
	do
	{
		//通讯录菜单
		menu();
		scanf("%d", &input);
		getchar();
		switch (input)
		{
		case show:
			ShowContact(&con);
			break;
		case add:
			AddContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case find:
			FindContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case sort:
			SortContact(&con);
			break;
		case exit_:
			SaveContact(&con);
			break;
		default:
			printf("非法输入，请重新选择！\n");
		}
	} while (input);
	
}
