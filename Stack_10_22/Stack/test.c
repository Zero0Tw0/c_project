#include"Stack.h"

void test()
{
	Stack stack ;
	StackInit(&stack);
	StackPush(&stack, 10);
	StackPush(&stack, 20);
	StackPush(&stack, 30);
	StackPush(&stack, 40);
	StackPush(&stack, 50);

	while (!StackEmpty(&stack))
	{
		printf("StackTop:%d \n", StackTop(&stack));
		printf("StackSize:%d\n\n", StackSize(&stack));
		StackPop(&stack);
	}

	StackDestroy(&stack);
}

int main()
{
	test();
	return 0;
}