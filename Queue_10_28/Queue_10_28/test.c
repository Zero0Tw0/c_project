#include"Queue.h"

void test1()
{
	Queue queue;
	QueueInit(&queue);						//���г�ʼ������

	QueuePush(&queue, 1);					//����в���
	printf("%d ", QueueBack(&queue));		//��βԪ�ز���
	QueuePush(&queue, 2);
	printf("%d ", QueueBack(&queue));
	QueuePush(&queue, 3);
	printf("%d ", QueueBack(&queue));
	QueuePush(&queue, 4);
	printf("%d\n", QueueBack(&queue));
	printf("size:%d\n", QueueSize(&queue));	//���г��Ȳ���

	while (!QueueEmpty(&queue))				//�����пղ���
	{
		printf("%d ", QueueFront(&queue));	//��ͷԪ�ز���
		QueuePop(&queue);					//�����в���
	}
	printf("\n");
	printf("size:%d\n", QueueSize(&queue));	//���г���Ϊ0���ԣ�

	//QueuePop(&queue);						//���������в���

	QueuePush(&queue, 0);					//���ն����������
	printf("%d ", QueueBack(&queue));

	QueueDestroy(&queue);					//�������ٲ���
}

int main()
{
	test1();
	return 0;
}