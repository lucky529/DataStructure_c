#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef char BTDataType;

typedef struct BTreeNode
{
	struct BTreeNode* _left;
	struct BTreeNode* _right;
	BTDataType _data;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a,int* pi);
void BinaryTreeDestory(BTNode* root);
void BinaryTreePrevOrder(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);//BTNode* BinaryTreeFind(BTNode* root, BTDataType x);void test();