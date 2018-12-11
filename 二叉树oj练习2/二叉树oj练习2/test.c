//int maxDepth(struct TreeNode* root) {//二叉树的最大深度
//    if(root == NULL)
//    {
//        return 0;
//    }
//    int left = maxDepth(root -> left) + 1;
//    int right = maxDepth(root -> right) + 1;
//    
//    return left > right? left: right;
//}

int maxDepth(struct TreeNode* root) {
    if(root == NULL)
    {
        return 0;
    }
    int left = maxDepth(root -> left) + 1;
    int right = maxDepth(root -> right) + 1;
    
    return left > right? left: right;
}
bool isBalanced(struct TreeNode* root) {//平衡二叉树
    if(root == NULL)
    {
        return true;
    }
    if(abs(maxDepth(root -> left) - maxDepth(root -> right)) > 1)
    {
        return false;
    }
    else
    {
        if(isBalanced(root -> left) && isBalanced(root -> right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}