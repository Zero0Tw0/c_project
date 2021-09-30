#include"SList.h"



void SListPrint(SListNode* plist)			//链表打印(自己实现)
{
	while (plist != NULL)
	{
		printf("%d ", plist->data);
		plist = plist->next;
	}
	printf("\n");
}
//void SListPrint(SListNode* plist)			//链表打印(标准实现)
//{											//可读性更强
//	SListNode* cur = plist;
//	while (cur != NULL)
//	{
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}



SListNode* BuySListNode(SListDataType x)	//创建新结点
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)					
	{
		printf("开辟内存失败\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}



//链表插入
void SListPushBack(SListNode** pplist, SListDataType x)		//尾插
{
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)						//当链表为空
	{
		*pplist = BuySListNode(x);				//直接创建新节点，plist指向新结点
	}
	else
	{
		SListNode* backnode = *pplist;	
		while (backnode->next != NULL)
		{
			backnode = backnode->next;			//链表不为空找尾结点
		}
		backnode->next = newnode;				//在尾结点插入新结点
	}
}

void SListPushFront(SListNode** pplist, SListDataType x)	//头插
{
	SListNode* newnode = BuySListNode(x);	//创建新结点
	newnode->next = *pplist;				//新节点指向头指针
	*pplist = newnode;						//头指针指向新节点
}

void SListInsert(SListNode** pplist, int pos, SListDataType x)	//按位插入
{
	SListNode* cur = *pplist;
	SListNode* pre = NULL;
	SListNode* newnode;
	int i = 0;

	//特殊情况1：在首位置插入(链表为空)
	//特殊情况2：在首位置插入(链表不为空)

	if (pos == 0)
	{
		newnode = BuySListNode(x);
		*pplist = newnode;
		newnode->next = cur;
		//printf("在首位置插入\n");					//调试用
		return;
	}
	
	while (cur != NULL)
	{
		//特殊情况3：在除首位置及末位置插入
		if (pos == i)
		{
			newnode = BuySListNode(x);
			pre->next = newnode;
			newnode->next = cur;
			//printf("在除首位置及末位置插入\n");	//调试用
			return;
		}
		pre = cur;
		cur = cur->next;
		i++;
	}
	//特殊情况4：在末位置插入
	if (pos == i)
	{
		newnode = BuySListNode(x);
		pre->next = newnode;
		newnode->next = cur;
		//printf("在末位置插入\n");					//调试用
	}
	//特殊情况5：超出可插入范围
	else
	{
		printf("超出可插入范围\n");					//错误提示
		return;
	}
}



//链表删除
void SListPopBack(SListNode** pplist)		//尾删
{
	SListNode* pre = NULL;
	SListNode* backnode = *pplist;

	//特殊情况1：当链表为空
	if (backnode == NULL)
	{	
		//printf("链表为空\n");				//调试用
		return;
	}

	//特殊情况2：当链表只有一个元素
	else if (backnode->next == NULL)
	{
		//printf("链表只有一个结点\n");		//调试用
		free(*pplist);
		*pplist = NULL;
	}

	//正常情况
	else
	{
		while (backnode->next != NULL)		//找尾
		{
			pre = backnode;
			backnode = backnode->next;
		}

		free(backnode);						//释放结点
		backnode = NULL;

		pre->next = NULL;					//上一结点的next指向NULL
	}
}

void SListPopFront(SListNode** pplist)		//头删
{
	SListNode* frontnode = *pplist;
	*pplist = frontnode->next;
	free(frontnode);
	frontnode = NULL;
}

void SListErase(SListNode** pplist, int pos)					//位删
{
	SListNode* cur = *pplist;
	SListNode* pre = NULL;
	int i = 0;

	//特殊情况1:当链表为空
	if (cur == NULL)
	{
		printf("链表为空\n");
		return;
	}

	//特殊情况2：在首位置删除
	else if (pos == 0)
	{
		*pplist = cur->next;
		free(cur);
		cur = NULL;
		printf("首位置删除\n");
		return;
	}

	//特殊情况3；中间与末位置删除
	while (cur != NULL)
	{	
		if (pos == i)
		{
			pre->next = cur->next;
			free(cur);
			cur = NULL;
			printf("当链表不为空删除\n");
			return;
		}
		pre = cur;
		cur = cur->next;
		i++;
	}

	//特殊情况4：超出可删除范围
	printf("超出可删除位置\n");
	return;
}



//链表查找
int SListFind(SListNode* plist, SListDataType x)	//按值查找
{
	int pos = 0;
	while (plist != NULL)
	{
		if (plist->data == x)							
			return pos;								//找到查找值返回位置
		else
		{
			pos++;
			plist = plist->next;					//没找到值往链表下一位走
		}
	}
	return - 1;										//没找到该值返回-1
}







