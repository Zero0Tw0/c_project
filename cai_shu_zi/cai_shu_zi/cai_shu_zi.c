#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void menu()
{
	printf("****************************\n");
	printf("*****1.paly      0.exit*****\n");
	printf("****************************\n");
	
}

int game(void)
{
	int rand_num, input =0;
	int times = 3;
	rand_num = rand() % 10 + 1;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &input);
		if (input > 10 || input < 1)
		{
			i--;
			printf("�Ƿ����룬������ѡ��Ҫ�²�����֣�\n");
		}
		else if (input == rand_num)
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			return 1;
		}
		else if(--times)
		{
			printf("�㻹��%d�λ��ᣬ�����²²⡣\n", times);
		}
	}
	return 0;
}



int main()
{
	int choose;
	int back;
	srand((unsigned int)time(NULL));//����ʱ���
	do
	{
		menu();
		scanf("%d", &choose);
		
		if (choose == 1)
		{
			printf("����3�λ��ᣬ����1-10�в²�:\n");
			back = game();
			if (back == 0)
			{
				printf("��Ϸʧ�ܣ�δ�µ�\n");
			}
		}
		else if (choose == 0)
		{
			printf("��Ϸ���˳�");
			break;
		}
		else
		{
			printf("�Ƿ����룬������ѡ�񣡣�\n");
		}
	} while (1);
	return 0;
}