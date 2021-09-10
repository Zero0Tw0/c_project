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
			printf("非法输入，请重新选择要猜测的数字：\n");
		}
		else if (input == rand_num)
		{
			printf("恭喜你，猜对了！\n");
			return 1;
		}
		else if(--times)
		{
			printf("你还有%d次机会，请重新猜测。\n", times);
		}
	}
	return 0;
}



int main()
{
	int choose;
	int back;
	srand((unsigned int)time(NULL));//生成时间戳
	do
	{
		menu();
		scanf("%d", &choose);
		
		if (choose == 1)
		{
			printf("你有3次机会，请在1-10中猜测:\n");
			back = game();
			if (back == 0)
			{
				printf("游戏失败，未猜到\n");
			}
		}
		else if (choose == 0)
		{
			printf("游戏已退出");
			break;
		}
		else
		{
			printf("非法输入，请重新选择！！\n");
		}
	} while (1);
	return 0;
}