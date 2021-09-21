#define _CRT_SECURE_NO_WARNINGS 1

//暴力求解
//
//#include<stdio.h>
//#include<string.h>
//char* KMP(char* str, char* dest)
//{
//	int pos = 0;											//记录匹配的首位置
//	int i = pos;											
//	int j = 0;
//	int len1 = strlen(str);
//	int len2 = strlen(dest);
//	if (len1 == 0 && len2 == 0 || len2 == 0) return str;	//当str与dest都为空或dest为空时直接返回
//	else if (len1 == 0 || len2 > len1) return NULL;			//当str为空或者第二个字符串比第一个字符串长
//	while (i < len1 && j < len2)							
//	{
//		if (str[i] == dest[j])								//当str[i]与dest[i]相等
//		{
//			if (j == 0)										
//				pos = i;									//记录匹配的首地址
//			i++;											//相等i和j同时向后走
//			j++;
//		}
//		else
//		{
//			i = ++pos;										//str[i]与dest[i]不相等记录的位置与i同时向后走
//			j = 0;											//j重置
//		}
//	}
//	if (j >= len2)
//		return str + pos;									//返回匹配的首地址
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



//KMP算法
//
//#include<stdio.h>
//#include<string.h>
//
//char* KMP(char* str, char* dest)
//{
//	int i = 0;												//不再需要记录匹配的首位置，因为kmp算法i不需要返回
//	int j = 0;
//	int len1 = strlen(str);
//	int len2 = strlen(dest);
//	if (len1 == 0 && len2 == 0 || len2 == 0) return str;	//当str与dest都为空或dest为空时直接返回
//	else if (len1 == 0 || len2 > len1) return NULL;			//当str为空或者第二个字符串比第一个字符串长
//	while (i < len1 && j < len2)
//	{
//		if (str[i] == dest[j])								
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[i];									//j返回的位置
//		}
//	}
//	if (j >= len2)
//		return str + (i-j);									//返回匹配的位置
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



//博客代码
//
//#include<stdio.h>
//#include<string.h>
//
//void GetNext(int* Next, const char* arr2)           //传入Next数组地址，传入子串首地址
//{
//	int j = 1;										//初始已知项 j = 1
//	int i = j + 1;									//初始待求项 j+1 = 2
//	int k = 0;                                      //待求的Next[j+1]前一项的k值
//	
//	int len2 = strlen(arr2);                        //子串长度
//	
//	Next[0] = -1;									//Next数组前两个默认值
//	Next[1] = 0;
//	
//	while (i < len2)                                //当待求项走到arr2尽头，找完Next数组
//	{
//		if ((k == -1) || arr2[k] == arr2[i - 1])	//结论1，结论3情况
//		{
//			Next[i] = k + 1;
//			k = k + 1;                              //待求的Next[j+1]前一项的k值
//			i++;                                    //待求项往后走一位
//		}
//		else
//		{
//			k = Next[k];							//结论2情况
//		}
//	}
//}
//
//int KMP(char* arr1, char* arr2)
//{
//	int i = 0;											//不需要记录匹配的首位置，
//	int j = 0;                                          //因为kmp算法i不需要回溯
//	
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	
//	int Next[len2] = {0};                               //假设Next已经得到，其长度为子串的长度
//	
//	if (len1 == 0 && len2 == 0 || len2 == 0) return 0;	//当arr1与arr2都为空或arr1为空时直接返回
//	else if (len1 == 0 || len2 > len1) return -1;		//当arr1为空或者第二个字符串比第一个字符串长
//	
//	while (i < len1 && j < len2)						//当arr1和arr2都没走到尽头
//	{
//		if (arr1[i] == arr2[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = Next[j];						        //当主串与子串不同时j回溯到Next[j]，i不用回溯
//		}
//	}
//	if (j >= len2)
//		return i - j;							        //如果子串走到尽头，代表找到了返回开始匹配时的位置
//	return -1;											//否则就是主串走到尽头，代表没找到
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



//KMP全部代码
//
#include<stdio.h>
#include<string.h>

void GetNext(int* Next, const char* arr2)           //传入Next数组地址，传入子串首地址
{
	int j = 1;										//初始已知项 j = 1
	int i = j + 1;									//初始待求项 j+1 = 2
	int k = 0;                                      //待求的Next[j+1]前一项的k值
	
	int len2 = strlen(arr2);                        //子串长度
	
	Next[0] = -1;									//Next数组前两个默认值
	Next[1] = 0;
	
	while (i < len2)                                //当待求项走到arr2尽头，找完Next数组
	{
		if ((k == -1) || arr2[k] == arr2[i - 1])	//结论1，结论3情况
		{
			Next[i] = k + 1;
			k = k + 1;                              //待求的Next[j+1]前一项的k值
			i++;                                    //待求项往后走一位
		}
		else
		{
			k = Next[k];							//结论2情况
		}
	}
}

int KMP(char* arr1, char* arr2)
{
	int i = 0;											//不需要记录匹配的首位置，
	int j = 0;                                          //因为kmp算法i不需要回溯
	
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	
	int* Next = (int*)malloc(len2 * sizeof(int));       //为Next数组开辟一个与子串一样长的空间
	
	GetNext(Next, arr2);                                //借用Next函数得到Next数组的内容

	if (len1 == 0 && len2 == 0 || len2 == 0) return 0;	//当arr1与arr2都为空或arr1为空时直接返回
	else if (len1 == 0 || len2 > len1) return -1;		//当arr1为空或者第二个字符串比第一个字符串长
	
	while (i < len1 && j < len2)						//当arr1和arr2都没走到尽头
	{
		if (arr1[i] == arr2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = Next[j];						        //当主串与子串不同时j回溯到Next[j]，i不用回溯
		}
	}
	if (j >= len2)
		return i - j;							        //如果子串走到尽头，代表找到了返回开始匹配时的位置
	return -1;											//否则就是主串走到尽头，代表没找到
}

int main()
{
	char arr1[] = "abababcabc";         //测试用             
	char arr2[] = "abcabc";
	char pos;
	pos = KMP(arr1, arr2);
	printf("%d", pos);
}