#include"Sort.h"

void InsertSortTest()
{
	printf("InsertSortTest:\n");
	int str1[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size1 = sizeof(str1) / sizeof(str1[0]);
	int str2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size2 = sizeof(str2) / sizeof(str2[0]);
	int str3[] = { 6,9,4,3,8,1,5,2,10,7 };
	int size3 = sizeof(str3) / sizeof(str3[0]);

	InsertSort(str1, size1);
	StrPrint(str1, size1);
	InsertSort(str2, size2);
	StrPrint(str2, size2);
	InsertSort(str3, size3);
	StrPrint(str3, size3);
}

void ShellSortTest()
{
	printf("ShellSortTest:\n");
	int str1[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size1 = sizeof(str1) / sizeof(str1[0]);
	int str2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size2 = sizeof(str2) / sizeof(str2[0]);
	int str3[] = { 6,9,4,3,8,1,5,2,10,7 };
	int size3 = sizeof(str3) / sizeof(str3[0]);

	ShellSort(str1, size1);
	StrPrint(str1, size1);
	ShellSort(str2, size2);
	StrPrint(str2, size2);
	ShellSort(str3, size3);
	StrPrint(str3, size3);
}

void SelectSortTest()
{
	printf("SelectSortTest:\n");
	int str1[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size1 = sizeof(str1) / sizeof(str1[0]);
	int str2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size2 = sizeof(str2) / sizeof(str2[0]);
	int str3[] = { 6,9,4,3,8,1,5,2,10,7 };
	int size3 = sizeof(str3) / sizeof(str3[0]);

	SelectSort(str1, size1);
	StrPrint(str1, size1);
	SelectSort(str2, size2);
	StrPrint(str2, size2);
	SelectSort(str3, size3);
	StrPrint(str3, size3);
}

void HeapSortTest()
{
	printf("HeapSortTest:\n");
	int str1[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size1 = sizeof(str1) / sizeof(str1[0]);
	int str2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size2 = sizeof(str2) / sizeof(str2[0]);
	int str3[] = { 6,9,4,3,8,1,5,2,10,7 };
	int size3 = sizeof(str3) / sizeof(str3[0]);

	HeapSort(str1, size1);
	StrPrint(str1, size1);
	HeapSort(str2, size2);
	StrPrint(str2, size2);
	HeapSort(str3, size3);
	StrPrint(str3, size3);
}

void BubbleSortTest()
{
	printf("BubbleSortTest:\n");
	int str1[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size1 = sizeof(str1) / sizeof(str1[0]);
	int str2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size2 = sizeof(str2) / sizeof(str2[0]);
	int str3[] = { 6,9,4,3,8,1,5,2,10,7 };
	int size3 = sizeof(str3) / sizeof(str3[0]);

	BubbleSort(str1, size1);
	StrPrint(str1, size1);
	BubbleSort(str2, size2);
	StrPrint(str2, size2);
	BubbleSort(str3, size3);
	StrPrint(str3, size3);
}

void QuickSortTest()
{
	printf("QuickSortTest:\n");
	int str1[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size1 = sizeof(str1) / sizeof(str1[0]);
	int str2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size2 = sizeof(str2) / sizeof(str2[0]);
	int str3[] = { 6,1,2,7,9,3,4,5,10,8 };
	int size3 = sizeof(str3) / sizeof(str3[0]);

	QuickSort(str1, 0, size1-1);
	StrPrint(str1, size1);
	QuickSort(str2, 0, size2 - 1);
	StrPrint(str2, size2);
	QuickSort(str3, 0, size3 - 1);
	StrPrint(str3, size3);
}

int main()
{
	/*InsertSortTest();
	ShellSortTest();
	SelectSortTest();
	HeapSortTest();
	BubbleSortTest();*/
	QuickSortTest();
}
	
