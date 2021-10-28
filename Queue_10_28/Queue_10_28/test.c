#include"Queue.h"

void test1()
{
	Queue queue;
	QueueInit(&queue);						//队列初始化测试

	QueuePush(&queue, 1);					//入队列测试
	printf("%d ", QueueBack(&queue));		//队尾元素测试
	QueuePush(&queue, 2);
	printf("%d ", QueueBack(&queue));
	QueuePush(&queue, 3);
	printf("%d ", QueueBack(&queue));
	QueuePush(&queue, 4);
	printf("%d\n", QueueBack(&queue));
	printf("size:%d\n", QueueSize(&queue));	//队列长度测试

	while (!QueueEmpty(&queue))				//队列判空测试
	{
		printf("%d ", QueueFront(&queue));	//对头元素测试
		QueuePop(&queue);					//出队列测试
	}
	printf("\n");
	printf("size:%d\n", QueueSize(&queue));	//队列长度为0测试；

	//QueuePop(&queue);						//过量出队列测试

	QueuePush(&queue, 0);					//出空队列重入测试
	printf("%d ", QueueBack(&queue));

	QueueDestroy(&queue);					//队列销毁测试
}

int main()
{
	test1();
	return 0;
}