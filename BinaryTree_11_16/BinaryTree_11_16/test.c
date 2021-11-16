#include"BinaryTree.h"
#include"Queue.h"

void test()
{
	BTDataType src[] = "ABD##E#H##CF##G##";		//����ȫ������
	//BTDataType src1[] = "ABD##E##CF##G##";	//��ȫ������
	//BTDataType src[] = "#";					//�������1
	//BTDataType src[] = "";					//�������2

	int i = 0;
	int size = strlen(src);
	BTNode* root = BinaryTreeCreat(src, size, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	
	int treesize = BinaryTreeSize(root);
	printf("treesize:%d\n", treesize);

	int leafsize = BinaryTreeLeafSize(root);
	printf("leafsize:%d\n", leafsize);

	int ksize = BinaryTreeLevelKSize(root, 2);
	printf("ksize:%d\n", ksize);

	BTNode* tmp = BinaryTreeFind(root, 'B');
	if(tmp)
		printf("find:%c\n", tmp->val);

	
	if (BinaryTreeComplete(root))
	{
		printf("����ȫ������\n");
	}
	else
	{
		printf("������ȫ������\n");
	}
	BinaryTreeDestroy(root);
}

int main()
{
	test();
}

