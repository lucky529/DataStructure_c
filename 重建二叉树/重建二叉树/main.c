#include"test.h"
BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->_data = x;
	newnode->_left = NULL;
	newnode->_right = NULL;

	return newnode;
}
BTNode* BinaryTreeCreate(BTDataType* a, int* pindex)
{
	if (a[*pindex] == '#')
	{
		++(*pindex);
		return NULL;
	}
	BTNode* root = BuyNode(a[*pindex]);
	++(*pindex);

	root->_left = BinaryTreeCreate(a, pindex);
	root->_right = BinaryTreeCreate(a, pindex);
	return root;
}
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL) return;

	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);

}
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL) return 0;

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL) return 0;
	if (root->_right == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelKSize(BTNode* root, int k){	if (root == NULL) return 0;	if (k == 1) return 1;	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);}
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL) return;
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)//{//	if (root == NULL) return NULL;//	if (root->_data == x)//	{//		return root;//	}//	BTNode* root = BinaryTreeFind(root->_left, x);//	if (root)//		return root;////	return BinaryTreeFind(root->_right, x);//}
void test()
{
	char arr[100] = "abc##de#g##f###";
	int index = 0;
	BTNode* root = BinaryTreeCreate(arr, &index);

	BinaryTreePrevOrder(root);//Ç°Ðò±éÀú¶þ²æÊ÷
	printf("\n");

	printf("%d\n", BinaryTreeSize(root));
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("%d\n", BinaryTreeLevelKSize(root,3));
	BinaryTreeDestory(root);
	root = NULL;	
}