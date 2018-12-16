//int TreeHight(struct TreeNode* root)
//{
//	if(root == NULL) return 0;
//    int left = TreeHight(root -> left);
//	int right = TreeHight(root -> right);
//	return left > right ? left + 1 : right + 1;
//}
//bool isBalanced(struct TreeNode* root)//平衡二叉树的判断
//{
//	if(root == NULL) return true;
//
//	if(abs(TreeHight(root -> left) - TreeHight(root -> right)) > 1)
//	{
//		return false;
//	}
//	else
//	{
//		if(isBalanced(root -> left) && isBalanced(root -> right))
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//}
//
//int TreeHight(struct TreeNode* root)
//{
//	if(root == NULL) return 0;
//    int left = TreeHight(root -> left);
//	int right = TreeHight(root -> right);
//	return left > right ? left + 1 : right + 1;
//}
//
//bool isBalanced(struct TreeNode* root)//简洁版，时间复杂度为n^2
//{
//	if(root == NULL) return true;
//
//	int left = TreeHight(root -> left);
//	int right = TreeHight(root -> right);
//
//	return abs(left - right) < 2 
//		&& isBalanced(root -> left) 
//		&& isBalanced(root -> right);
//}
//
//struct Ret
//{
//	bool isbalance;
//	int height;
//};
//
//struct Ret_isBalanced(root)
//{
//	struct Ret ret;
//	ret.isblance = true;
//	ret.height = 0;
//
//	struct Ret lret = Ret_isBalanced(root -> left);
//	if(lret == false)
//	{
//		return ret;
//	}
//
//	struct Ret rret = Ret_isBalanced(root -> right);
//	if(rret == false)
//	{
//		return ret;
//	}
//
//}
//bool isBalanced(struct TreeNode* root)//使用时间复杂度01来实现平衡树
//{
//	return Ret_isBalanced(root).isblance;
//}

//#include<stdio.h>
//int main()//程序员的爱情
//{
//	char i,her[60]={ 73,32,115,97,119,32,121,
//          111,117,32,97,103,97,105,
//          110,32,105,110,32,109,121,
//          32,100,114,101,97,109,44,32,
//          105,32,109,105,115,115,101,
//          100,32,121,111,117,32,115,
//          111,32,109,117,99,104,32,32,
//          32,76,101,105,32,89,97,110 } ;
//	for  ( i=0 ; i<=60 ; i++)
//    printf("%c", her[i]);
//	return 0;
//}

//#include<stdio.h>//重建二叉树
//#include<stdlib.h>
//#include<malloc.h>
//
//typedef struct BTreeNode
//{
//	struct BTreeNode* _left;
//	struct BTreeNode* _right;
//	char _c;
//}BTNode;
//
//BTNode* CreatTree(char* arr, int* pindex)
//{
//	if(arr[*pindex] == '#')
//	{
//        ++(*pindex);
//        return NULL;
//	}
//	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
//	root ->_c = arr[*pindex];
//	++(*pindex);
//	root ->_left = CreatTree(arr, pindex);    
//
//	root ->_right = CreatTree(arr, pindex);
//        
//    return root;
//}
//	
//void PrevOrder(BTNode* root)
//{
//	if(root == NULL) return;
//	PrevOrder(root ->_left );
//	printf("%c ",root ->_c );
//	PrevOrder(root ->_right);
//
//}
//
//int main()
//{
//	char arr[100] = {};
//	scanf("%s",arr);
//    int index = 0;
//	BTNode* root = CreatTree(arr, &index);
//	PrevOrder(root);
//    
//	return 0;
//}