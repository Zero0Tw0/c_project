#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SeqList* ps)					//˳����ʼ��
{
	assert(ps);
	ps->a = NULL;
	//��ʼָ��ָ��
	ps->size = 0;
	//��ʼ��������Ϊ��
	ps->capacity = 0;
	//��ʼ��������Ϊ��
}

void SeqListDestory(SeqList* ps)				//˳�������
{
	assert(ps);
	free(ps->a);
	//�ͷſ��ٵĿռ�
	ps->a = NULL;
	//ָ��ָ��
	ps->size = 0;
	//���ÿռ�����
	ps->capacity = 0;
	//���ÿռ�����
}

void SeqListPrint(SeqList* ps)                 //˳����ӡ
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
	//��˳�����������δ�ӡ
}

void CheckSeqList(SeqList* ps)
{	
	assert(ps);

	int new_capacity = ps->capacity;
	SLDataType* new_a = NULL;
	//����������ʱ�����Է�ֹ����ʧ��
	if (ps->size == ps->capacity)
	{
		(new_capacity == 0) ? (new_capacity = 4) : (new_capacity = 2 * new_capacity);
		//���״ο���ֱ�ӿ����ĸ��ռ䣬���򿪱�ԭ�ռ������
		new_a = (SLDataType*)realloc(ps->a, new_capacity * sizeof(SLDataType));
		//����ԭ���ռ������
		if (new_a == NULL)
		{
			printf("���ٿռ�ʧ��");
			exit(-1);
			//new_a�ǿ�ָ���ʾ����ʧ��
		}
		else
		{
			ps->capacity = new_capacity;
			ps->a = new_a;
			//���ٳɹ����ռ�Ϳռ䳤�ȸ�SeqList
		}
	}
	
}

void SeqListPushFront(SeqList* ps, SLDataType x)		//˳���ͷ��
{
	assert(ps);
	CheckSeqList(ps);
	//����ڴ��Ƿ�����
	for (int i = ps->size -1 ; i >=0 ; i--)
	{
		ps->a[i+1] = ps->a[i];
		//�Ӻ�ǰһ�������һλ
	}
	ps->a[0] = x;
	//��һλΪ��������
	ps->size++;
	//���ÿռ�+1
}

void SeqListPushBack(SeqList* ps, SLDataType x)			//˳���β��
{
	assert(ps);
	CheckSeqList(ps);
	ps->a[ps->size] = x;
	//��˳���������x
	ps->size++;
	//˳������ÿռ�+1
}

void SeqListPopFront(SeqList* ps)					//˳���ͷɾ
{
	assert(ps);
	for (int i = 0; i < ps->size -1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	//��˳���������ǰ��
	ps->size--;
	//˳�����ÿռ�-1
}

void SeqListPopBack(SeqList* ps)					//˳���βɾ
{
	assert(ps);
	ps->size--;
	//˳�����ÿռ�-1
}

int SeqListFind(const SeqList* ps, SLDataType x)					//˳���ֵ����
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;								
			//������xƥ�䣬�ҵ���������λ��
		}
	}
	return -1;										
	//�Ҳ�������-1
}

void SeqListInsert(SeqList* ps, int pos, SLDataType x)       //˳���λ����
{
	assert(ps);
	CheckSeqList(ps);
	//����ڴ��Ƿ�����
	if (pos > ps->size)
	{
		printf("�����ɼ�ⷶΧ");
		exit(-1);
	}
	//Ҫ����λ���Ƿ�Ϊ�ϸ�Ϊֹ
	for (int i = ps->size - 1; i >= pos - 1; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	//�Ӻ�ǰ����������һλ
	ps->a[pos - 1] = x;
	//��pos-1λΪ��������
	ps->size++;
	//���ÿռ�+1
}

void SeqListErase(SeqList* ps, int pos)		//˳���λɾ	
{
	assert(ps);
	if (pos > ps->size)
	{
		printf("�����ɼ�ⷶΧ");
		exit(-1);
	}
	//Ҫɾ��λ���Ƿ�Ϊ�ϸ�Ϊֹ
	for (int i = pos - 1; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i+1];
	}
	//��ǰ���������ǰ��һλ
	ps->size--;
	//���ÿռ�-1
}