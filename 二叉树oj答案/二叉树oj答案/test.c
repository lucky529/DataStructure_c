二叉树基础面试题OJ答案
1.
https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return GetTreeSize(root->left)
		+ GetTreeSize(root->right)
		+ 1;
}

void _preorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;

	array[*pIndex] = root->val;
	++(*pIndex);
	_preorderTraversal(root->left, array, pIndex);
	_preorderTraversal(root->right, array, pIndex);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc(*returnSize * sizeof(int));
	int index = 0;

	_preorderTraversal(root, array, &index);

	return array;
}

2.
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return GetTreeSize(root->left) + GetTreeSize(root->right) + 1;
}

void _inorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;

	_inorderTraversal(root->left, array, pIndex);

	array[*pIndex] = root->val;
	(*pIndex)++;

	_inorderTraversal(root->right, array, pIndex);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc(*returnSize*sizeof(int));
	int index = 0;
	_inorderTraversal(root, array, &index);

	return array;
}

3.
https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return GetTreeSize(root->left) + GetTreeSize(root->right) + 1;
}

void _postorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;

	_postorderTraversal(root->left, array, pIndex);
	_postorderTraversal(root->right, array, pIndex);
	array[*pIndex] = root->val;
	(*pIndex)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc(*returnSize*sizeof(int));
	int index = 0;
	_postorderTraversal(root, array, &index);

	return array;
}

4.
https://leetcode-cn.com/problems/same-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	// 都为空
	if (p == NULL && q == NULL)
		return true;

	// 其中一个为空
	if (p == NULL || q == NULL)
		return false;

	return p->val == q->val
		&& isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}

5.
https://leetcode-cn.com/problems/subtree-of-another-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSameTree(struct TreeNode* t1, struct TreeNode* t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;

	if (t1 == NULL || t2 == NULL)
		return false;

	return t1->val == t2->val
		&& isSameTree(t1->left, t2->left)
		&& isSameTree(t1->right, t2->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (t == NULL)
		return true;

	if (s == NULL)
		return false;

	if (s->val == t->val && isSameTree(s, t))
		return true;

	return isSubtree(s->left, t)
		|| isSubtree(s->right, t);
}

6.
https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

7.
https://leetcode-cn.com/problems/balanced-binary-tree/
// O(N^2)的算法
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int _maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = _maxDepth(root->left);
	int rightDepth = _maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;

	int leftDepth = _maxDepth(root->left);
	int rightDepth = _maxDepth(root->right);
	return abs(leftDepth - rightDepth) < 2
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}

// O(N)的算法
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool _isBalanced(struct TreeNode* root, int* pDepth) {
	if (root == NULL) {
		*pDepth = 0;
		return true;
	}

	int leftDepth = 0, rightDepth = 0;
	if (_isBalanced(root->left, &leftDepth)
		&& _isBalanced(root->right, &rightDepth)
		&& abs(leftDepth - rightDepth) < 2)
	{
		*pDepth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
		return true;
	}
	else
	{
		return false;
	}

}

bool isBalanced(struct TreeNode* root) {
	int depth = 0;
	return _isBalanced(root, &depth);
}

8.
https://leetcode-cn.com/problems/symmetric-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool _isSymmetric(struct TreeNode* left, struct TreeNode* right) {
	if (left == NULL && right == NULL)
		return true;

	if (left == NULL || right == NULL)
		return false;

	return left->val == right->val
		&& _isSymmetric(left->left, right->right)
		&& _isSymmetric(left->right, right->left);
}



bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;

	return _isSymmetric(root->left, root->right);
}

9.
https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking

#include<stdio.h>
#include<malloc.h>
typedef struct BTNode
{
	struct BTNode* _left;
	struct BTNode* _right;
	char _data;
}BTNode;

BTNode* CreateTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = str[*pi];
		++(*pi);
		root->_left = CreateTree(str, pi);
		++(*pi);
		root->_right = CreateTree(str, pi);
		return root;
	}
}

void InOrder(BTNode* root)
{
	if (root == NULL) return;

	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

int main()
{
	char str[100] = { 0 };
	scanf("%s", str);
	int i = 0;
	BTNode* tree = CreateTree(str, &i);
	InOrder(tree);
	return 0;
}