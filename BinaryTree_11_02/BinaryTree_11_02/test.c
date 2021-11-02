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
	printf("BinaryTreeSize:%d", size);			//����������




}

int main()
{
	test1();
	return 0;
}