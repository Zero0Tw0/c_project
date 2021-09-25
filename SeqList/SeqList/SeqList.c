#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SeqList* ps)					//顺序表初始化
{
	assert(ps);
	ps->a = NULL;
	//初始指针指空
	ps->size = 0;
	//初始已用容量为零
	ps->capacity = 0;
	//初始可用容量为零
}

void SeqListDestory(SeqList* ps)				//顺序表销毁
{
	assert(ps);
	free(ps->a);
	//释放开辟的空间
	ps->a = NULL;
	//指针指空
	ps->size = 0;
	//已用空间置零
	ps->capacity = 0;
	//可用空间置零
}

void SeqListPrint(SeqList* ps)                 //顺序表打印
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
	//将顺序表的内容依次打印
}

void CheckSeqList(SeqList* ps)
{	
	assert(ps);

	int new_capacity = ps->capacity;
	SLDataType* new_a = NULL;
	//开辟两个临时变量以防止开辟失败
	if (ps->size == ps->capacity)
	{
		(new_capacity == 0) ? (new_capacity = 4) : (new_capacity = 2 * new_capacity);
		//当首次开辟直接开辟四个空间，否则开辟原空间的两倍
		new_a = (SLDataType*)realloc(ps->a, new_capacity * sizeof(SLDataType));
		//开辟原来空间的两倍
		if (new_a == NULL)
		{
			printf("开辟空间失败");
			exit(-1);
			//new_a是空指针表示开辟失败
		}
		else
		{
			ps->capacity = new_capacity;
			ps->a = new_a;
			//开辟成功将空间和空间长度给SeqList
		}
	}
	
}

void SeqListPushFront(SeqList* ps, SLDataType x)		//顺序表头插
{
	assert(ps);
	CheckSeqList(ps);
	//检查内存是否已满
	for (int i = ps->size -1 ; i >=0 ; i--)
	{
		ps->a[i+1] = ps->a[i];
		//从后到前一次往后放一位
	}
	ps->a[0] = x;
	//第一位为插入内容
	ps->size++;
	//已用空间+1
}

void SeqListPushBack(SeqList* ps, SLDataType x)			//顺序表尾插
{
	assert(ps);
	CheckSeqList(ps);
	ps->a[ps->size] = x;
	//在顺序表最后放入x
	ps->size++;
	//顺序表已用空间+1
}

void SeqListPopFront(SeqList* ps)					//顺序表头删
{
	assert(ps);
	for (int i = 0; i < ps->size -1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	//将顺序表依次往前移
	ps->size--;
	//顺序表可用空间-1
}

void SeqListPopBack(SeqList* ps)					//顺序表尾删
{
	assert(ps);
	ps->size--;
	//顺序表可用空间-1
}

int SeqListFind(const SeqList* ps, SLDataType x)					//顺序表按值查找
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;								
			//依次与x匹配，找到返回所在位置
		}
	}
	return -1;										
	//找不到返回-1
}

void SeqListInsert(SeqList* ps, int pos, SLDataType x)       //顺序表按位插入
{
	assert(ps);
	CheckSeqList(ps);
	//检查内存是否已满
	if (pos > ps->size)
	{
		printf("超出可检测范围");
		exit(-1);
	}
	//要插入位置是否为合格为止
	for (int i = ps->size - 1; i >= pos - 1; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	//从后到前依次往后移一位
	ps->a[pos - 1] = x;
	//第pos-1位为插入内容
	ps->size++;
	//已用空间+1
}

void SeqListErase(SeqList* ps, int pos)		//顺序表位删	
{
	assert(ps);
	if (pos > ps->size)
	{
		printf("超出可检测范围");
		exit(-1);
	}
	//要删除位置是否为合格为止
	for (int i = pos - 1; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i+1];
	}
	//从前向后依次往前移一位
	ps->size--;
	//已用空间-1
}