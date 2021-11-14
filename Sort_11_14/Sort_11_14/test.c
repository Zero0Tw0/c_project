#include"sort.h"

void SelectSortTest()
{
	int str1[] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz1 = sizeof(str1) / sizeof(str1[0]);
	int str2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz2 = sizeof(str2) / sizeof(str2[0]);
	int str3[] = { 1,6,9,10,2,8,3,7,4,5 };
	int sz3 = sizeof(str3) / sizeof(str3[0]);

	printf("SelectSortTest:\n");
	SelectSort(str1, sz1);
	StrPrint(str1, sz1);

	SelectSort(str2, sz2);
	StrPrint(str2, sz2);

	SelectSort(str3, sz3);
	StrPrint(str3, sz3);
}

void HeapSortTest()
{
	int str1[] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz1 = sizeof(str1) / sizeof(str1[0]);
	int str2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz2 = sizeof(str2) / sizeof(str2[0]);
	int str3[] = { 1,6,9,10,2,8,3,7,4,5 };
	int sz3 = sizeof(str3) / sizeof(str3[0]);

	printf("HeapSortTest:\n");
	HeapSort(str1, sz1);
	StrPrint(str1, sz1);

	HeapSort(str2, sz2);
	StrPrint(str2, sz2);

	HeapSort(str3, sz3);
	StrPrint(str3, sz3);
}


void ShellSortTest()
{
	int str1[] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz1 = sizeof(str1) / sizeof(str1[0]);
	int str2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz2 = sizeof(str2) / sizeof(str2[0]);
	int str3[] = { 1,6,9,10,2,8,3,7,4,5 };
	int sz3 = sizeof(str3) / sizeof(str3[0]);

	printf("ShellSortTest:\n");
	ShellSort(str1, sz1);
	StrPrint(str1, sz1);

	ShellSort(str2, sz2);
	StrPrint(str2, sz2);

	ShellSort(str3, sz3);
	StrPrint(str3, sz3);
}

void InsertSortTest()
{
	int str1[] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz1 = sizeof(str1) / sizeof(str1[0]);
	int str2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz2 = sizeof(str2) / sizeof(str2[0]);
	int str3[] = { 1,6,9,10,2,8,3,7,4,5 };
	int sz3 = sizeof(str3) / sizeof(str3[0]);

	printf("InsertSortTest:\n");
	InsertSort(str1, sz1);
	StrPrint(str1, sz1);

	InsertSort(str2, sz2);
	StrPrint(str2, sz2);

	InsertSort(str3, sz3);
	StrPrint(str3, sz3);
}

int main()
{
	InsertSortTest();
	ShellSortTest();
    HeapSortTest();
	SelectSortTest();

	return 0;
}