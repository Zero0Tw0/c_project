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
	printf("��ѡ���ͨѶ¼�Ĳ�����");
}



int main()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);

	//ͨѶ¼����
	do
	{
		//ͨѶ¼�˵�
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
			printf("�Ƿ����룬������ѡ��\n");
		}
	} while (input);
	
}
