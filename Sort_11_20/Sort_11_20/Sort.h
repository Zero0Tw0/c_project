#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

void Swap(int* a, int* b);
void StrPrint(int* str, int size);
void Adjustdown(int* str, int size, int root);
int GetMidIndex(int* str, int left, int right);
int PartSort1(int* str, int left, int right);
int PartSort2(int* str, int left, int right);
int PartSort3(int* str, int left, int right);
void _MergeSort(int* str, int left, int right, int* tmp);
void _MergeSortNonR(int* str, int size, int* tmp);


void InsertSort(int* str, int size);
void ShellSort(int* str, int size);
void SelectSort(int* str, int size);
void HeapSort(int* str, int size);
void BubbleSort(int* str, int size);
void QuickSort(int* str, int left, int right);
void QuickSortNonR(int* str, int left, int right);
void MergeSort(int* str, int size);
void MergeSortNonR(int* str, int size);
void CountSort(int* str, int size);