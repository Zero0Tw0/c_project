#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

void StrPrint(int* str, int size);
void Adjustdown(int* str, int size, int root);
int PartSort1(int* str, int left, int right);
int PartSort2(int* str, int left, int right);
int PartSort3(int* str, int left, int right);


void InsertSort(int* str, int size);
void ShellSort(int* str, int size);
void SelectSort(int* str, int size);
void HeapSort(int* str, int size);
void BubbleSort(int* str, int size);
void QuickSort(int* str, int size);