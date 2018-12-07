#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SqListType;

typedef struct SeqList
{
	SqListType* arry;
	size_t size;
	size_t capicity;
}SeqList;

void SeqListInit(SeqList* ps, size_t capacity);
void SeqListDestory(SeqList* ps);
void CheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps,SqListType x);
void SeqListPopBack(SeqList* ps);
void SeqListprintf(SeqList* ps);
void SeqListPushFront(SeqList* ps, SqListType x);
void SeqListPopFront(SeqList* ps);
int SeqListFind(SeqList* ps, SqListType x);
void SeqListInsert(SeqList* ps, size_t pos, SqListType x);
void SeqListErase(SeqList* ps, size_t pos);
void SeqListModify(SeqList* ps, size_t pos, SqListType x);
void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, SqListType x);
void SeqListRemoveAll(SeqList* ps, SqListType x); 


	