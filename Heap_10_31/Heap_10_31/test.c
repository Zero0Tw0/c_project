//´ó¶Ñ

#include"Heap.h"

void test1()
{
	HeapDataType str[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap heap;
	int strsize = sizeof(str) / sizeof(str[0]);
	HeapInit(&heap, str, strsize);			//¶Ñ³õÊ¼²âÊÔ
	HeapPrint(&heap);						//¶Ñ´òÓ¡²âÊÔ

	HeapPush(&heap, 88);					//Èë¶Ñ²âÊÔ
	HeapPrint(&heap);

	while (!HeapEmpty(&heap))				//ÅĞ¿Õ²âÊÔ
	{
		printf("top:%d\n", HeapTop(&heap));	//¶Ñ¶¥Êı¾İ²âÊÔ
		HeapPop(&heap);						//³ö¶Ñ²âÊÔ
		HeapPrint(&heap);		
	}

	HeapPush(&heap, 88);					//³ö¿ÕÔÙÈë²âÊÔ
	HeapPrint(&heap);

	HeapDestroy(&heap);						//¶ÑÏú»Ù²âÊÔ

}

int main()
{
	test1();
	return 0;
}