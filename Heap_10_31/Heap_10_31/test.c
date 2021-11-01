//���

#include"Heap.h"

void test1()
{
	HeapDataType str[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap heap;
	int strsize = sizeof(str) / sizeof(str[0]);
	HeapInit(&heap, str, strsize);			//�ѳ�ʼ����
	HeapPrint(&heap);						//�Ѵ�ӡ����

	HeapPush(&heap, 88);					//��Ѳ���
	HeapPrint(&heap);

	while (!HeapEmpty(&heap))				//�пղ���
	{
		printf("top:%d\n", HeapTop(&heap));	//�Ѷ����ݲ���
		HeapPop(&heap);						//���Ѳ���
		HeapPrint(&heap);		
	}

	HeapPush(&heap, 88);					//�����������
	HeapPrint(&heap);

	HeapDestroy(&heap);						//�����ٲ���

}

int main()
{
	test1();
	return 0;
}