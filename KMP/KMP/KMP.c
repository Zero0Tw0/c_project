#define _CRT_SECURE_NO_WARNINGS 1

//�������
//
//#include<stdio.h>
//#include<string.h>
//char* KMP(char* str, char* dest)
//{
//	int pos = 0;											//��¼ƥ�����λ��
//	int i = pos;											
//	int j = 0;
//	int len1 = strlen(str);
//	int len2 = strlen(dest);
//	if (len1 == 0 && len2 == 0 || len2 == 0) return str;	//��str��dest��Ϊ�ջ�destΪ��ʱֱ�ӷ���
//	else if (len1 == 0 || len2 > len1) return NULL;			//��strΪ�ջ��ߵڶ����ַ����ȵ�һ���ַ�����
//	while (i < len1 && j < len2)							
//	{
//		if (str[i] == dest[j])								//��str[i]��dest[i]���
//		{
//			if (j == 0)										
//				pos = i;									//��¼ƥ����׵�ַ
//			i++;											//���i��jͬʱ�����
//			j++;
//		}
//		else
//		{
//			i = ++pos;										//str[i]��dest[i]����ȼ�¼��λ����iͬʱ�����
//			j = 0;											//j����
//		}
//	}
//	if (j >= len2)
//		return str + pos;									//����ƥ����׵�ַ
//	return NULL;
//}
//
//int main()
//{
//	char arr1[] = "ababcd";
//	char arr2[2] = "a";
//	char* back;
//	back = KMP(arr1, arr2);
//	puts(back);
//	return 0;
//}



//KMP�㷨
//
//#include<stdio.h>
//#include<string.h>
//
//char* KMP(char* str, char* dest)
//{
//	int i = 0;												//������Ҫ��¼ƥ�����λ�ã���Ϊkmp�㷨i����Ҫ����
//	int j = 0;
//	int len1 = strlen(str);
//	int len2 = strlen(dest);
//	if (len1 == 0 && len2 == 0 || len2 == 0) return str;	//��str��dest��Ϊ�ջ�destΪ��ʱֱ�ӷ���
//	else if (len1 == 0 || len2 > len1) return NULL;			//��strΪ�ջ��ߵڶ����ַ����ȵ�һ���ַ�����
//	while (i < len1 && j < len2)
//	{
//		if (str[i] == dest[j])								
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[i];									//j���ص�λ��
//		}
//	}
//	if (j >= len2)
//		return str + (i-j);									//����ƥ���λ��
//	return NULL;
//}
//
//int main()
//{
//	char arr1[] = "ababcd";
//	char arr2[2] = "a";
//	char* back;
//	back = KMP(arr1, arr2);
//	puts(back);
//	return 0;
//}



//���ʹ���
//
//#include<stdio.h>
//#include<string.h>
//
//void GetNext(int* Next, const char* arr2)           //����Next�����ַ�������Ӵ��׵�ַ
//{
//	int j = 1;										//��ʼ��֪�� j = 1
//	int i = j + 1;									//��ʼ������ j+1 = 2
//	int k = 0;                                      //�����Next[j+1]ǰһ���kֵ
//	
//	int len2 = strlen(arr2);                        //�Ӵ�����
//	
//	Next[0] = -1;									//Next����ǰ����Ĭ��ֵ
//	Next[1] = 0;
//	
//	while (i < len2)                                //���������ߵ�arr2��ͷ������Next����
//	{
//		if ((k == -1) || arr2[k] == arr2[i - 1])	//����1������3���
//		{
//			Next[i] = k + 1;
//			k = k + 1;                              //�����Next[j+1]ǰһ���kֵ
//			i++;                                    //������������һλ
//		}
//		else
//		{
//			k = Next[k];							//����2���
//		}
//	}
//}
//
//int KMP(char* arr1, char* arr2)
//{
//	int i = 0;											//����Ҫ��¼ƥ�����λ�ã�
//	int j = 0;                                          //��Ϊkmp�㷨i����Ҫ����
//	
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	
//	int Next[len2] = {0};                               //����Next�Ѿ��õ����䳤��Ϊ�Ӵ��ĳ���
//	
//	if (len1 == 0 && len2 == 0 || len2 == 0) return 0;	//��arr1��arr2��Ϊ�ջ�arr1Ϊ��ʱֱ�ӷ���
//	else if (len1 == 0 || len2 > len1) return -1;		//��arr1Ϊ�ջ��ߵڶ����ַ����ȵ�һ���ַ�����
//	
//	while (i < len1 && j < len2)						//��arr1��arr2��û�ߵ���ͷ
//	{
//		if (arr1[i] == arr2[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = Next[j];						        //���������Ӵ���ͬʱj���ݵ�Next[j]��i���û���
//		}
//	}
//	if (j >= len2)
//		return i - j;							        //����Ӵ��ߵ���ͷ�������ҵ��˷��ؿ�ʼƥ��ʱ��λ��
//	return -1;											//������������ߵ���ͷ������û�ҵ�
//}
//
//int main()
//{
//	char arr1[] = "abababcabc";
//	char arr2[] = "abcabc";
//	char pos;
//	pos = KMP(arr1, arr2);
//	printf("%d", pos);
//}



//KMPȫ������
//
#include<stdio.h>
#include<string.h>

void GetNext(int* Next, const char* arr2)           //����Next�����ַ�������Ӵ��׵�ַ
{
	int j = 1;										//��ʼ��֪�� j = 1
	int i = j + 1;									//��ʼ������ j+1 = 2
	int k = 0;                                      //�����Next[j+1]ǰһ���kֵ
	
	int len2 = strlen(arr2);                        //�Ӵ�����
	
	Next[0] = -1;									//Next����ǰ����Ĭ��ֵ
	Next[1] = 0;
	
	while (i < len2)                                //���������ߵ�arr2��ͷ������Next����
	{
		if ((k == -1) || arr2[k] == arr2[i - 1])	//����1������3���
		{
			Next[i] = k + 1;
			k = k + 1;                              //�����Next[j+1]ǰһ���kֵ
			i++;                                    //������������һλ
		}
		else
		{
			k = Next[k];							//����2���
		}
	}
}

int KMP(char* arr1, char* arr2)
{
	int i = 0;											//����Ҫ��¼ƥ�����λ�ã�
	int j = 0;                                          //��Ϊkmp�㷨i����Ҫ����
	
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	
	int* Next = (int*)malloc(len2 * sizeof(int));       //ΪNext���鿪��һ�����Ӵ�һ�����Ŀռ�
	
	GetNext(Next, arr2);                                //����Next�����õ�Next���������

	if (len1 == 0 && len2 == 0 || len2 == 0) return 0;	//��arr1��arr2��Ϊ�ջ�arr1Ϊ��ʱֱ�ӷ���
	else if (len1 == 0 || len2 > len1) return -1;		//��arr1Ϊ�ջ��ߵڶ����ַ����ȵ�һ���ַ�����
	
	while (i < len1 && j < len2)						//��arr1��arr2��û�ߵ���ͷ
	{
		if (arr1[i] == arr2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = Next[j];						        //���������Ӵ���ͬʱj���ݵ�Next[j]��i���û���
		}
	}
	if (j >= len2)
		return i - j;							        //����Ӵ��ߵ���ͷ�������ҵ��˷��ؿ�ʼƥ��ʱ��λ��
	return -1;											//������������ߵ���ͷ������û�ҵ�
}

int main()
{
	char arr1[] = "abababcabc";         //������             
	char arr2[] = "abcabc";
	char pos;
	pos = KMP(arr1, arr2);
	printf("%d", pos);
}