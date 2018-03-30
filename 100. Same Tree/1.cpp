/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if(NULL == p && NULL == q)
	{
		return true;
	}
	else if(NULL != p && NULL != q)
	{
		if(p->val != q->val)
		{
			return false;
		}

		if(!isSameTree(p->left, q->left))
		{
			return false;
		}

		if(!isSameTree(p->right, q->right))
		{
			return false;
		}

		return true;
	}
	else
	{
		return false;
	}
}