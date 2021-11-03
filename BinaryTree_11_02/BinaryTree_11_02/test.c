#include"BinaryTree.h"

void test1()
{
	BTNode* A = CreatTreeNode('A');				//创建二叉树结点
	BTNode* B = CreatTreeNode('B');
	BTNode* C = CreatTreeNode('C');
	BTNode* D = CreatTreeNode('D');
	BTNode* E = CreatTreeNode('E');
	BTNode* F = CreatTreeNode('F');
		
	A->left = B;								//手动链接二叉树结点
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;

	PrevOrder(A);								//前序遍历打印
	printf("\n");

	InOrder(A);									//中序遍历打印
	printf("\n");

	PostOrder(A);								//后续遍历打印
	printf("\n\n");

	int size = TreeSize(A);
	printf("BinaryTreeSize:%d\n", size);		//结点个数测试

	int depth = MaxDepth(A);
	printf("BinaryTreeDepth:%d\n", depth);		//二叉树高度测试

	int leafsize = BinaryTreeLeafSize(A);
	printf("BinaryTreeLeafSize:%d\n", leafsize);

	int ksize = BinaryTreeLevelKSize(A, 3);		//第k层结点个数测试
	printf("BinaryTreeLevel3size:%d\n", ksize);
	ksize = BinaryTreeLevelKSize(A, 2);
	printf("BinaryTreeLevel2size:%d\n", ksize);
	ksize = BinaryTreeLevelKSize(A, 4);
	printf("BinaryTreeLevel4size:%d\n", ksize);

	BTNode* cpos = BinaryTreeFind(A, 'C');
	printf("BinaryTreeCpos:%c\n", cpos->val);
}

int main()
{
	test1();
	return 0;
}