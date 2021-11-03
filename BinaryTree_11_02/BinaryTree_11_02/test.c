#include"BinaryTree.h"

void test1()
{
	BTNode* A = CreatTreeNode('A');				//�������������
	BTNode* B = CreatTreeNode('B');
	BTNode* C = CreatTreeNode('C');
	BTNode* D = CreatTreeNode('D');
	BTNode* E = CreatTreeNode('E');
	BTNode* F = CreatTreeNode('F');
		
	A->left = B;								//�ֶ����Ӷ��������
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;

	PrevOrder(A);								//ǰ�������ӡ
	printf("\n");

	InOrder(A);									//���������ӡ
	printf("\n");

	PostOrder(A);								//����������ӡ
	printf("\n\n");

	int size = TreeSize(A);
	printf("BinaryTreeSize:%d\n", size);		//����������

	int depth = MaxDepth(A);
	printf("BinaryTreeDepth:%d\n", depth);		//�������߶Ȳ���

	int leafsize = BinaryTreeLeafSize(A);
	printf("BinaryTreeLeafSize:%d\n", leafsize);

	int ksize = BinaryTreeLevelKSize(A, 3);		//��k�����������
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