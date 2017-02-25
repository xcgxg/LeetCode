#include <iostream>

using namespace std;

struct TreeNode 
{
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

//输入先序遍历和中序遍历字符串构造二叉树
/*例: 1. 平衡二叉树，先序“abdecf”， 后序“dbeafc”；
      2. 非平衡二叉树，先序“abdec”，后序“edbac”.
*/
struct TreeNode *create_tree(string,string);

//后序遍历输出二叉树
//void post(TreeNode *);

//销毁二叉树
void destroy_tree(struct TreeNode *);

//是否时平衡二叉树
bool isBalanced(struct TreeNode *);

//二叉树高度（叶子结点高度算 1）
int TreeHight(struct TreeNode *);

int main()
{
	string a,b;
    while(cin>>a>>b)
    {
        struct TreeNode *tree=create_tree(a, b);

        printf("%d\n", isBalanced(tree));

        destroy_tree(tree);
    }
}

/*submission*/
int TreeHight(struct TreeNode *root)
{
	if(NULL == root)
	{
		return 0;
	}

	int hight_left=TreeHight(root->left);
	int hight_right=TreeHight(root->right);

	return (hight_left>hight_right)?(hight_left+1):(hight_right+1);
}

bool isBalanced(struct TreeNode *root)
{
	if(NULL == root)
	{
		return true;
	}

	bool is_left_balanced=isBalanced(root->left);
	bool is_right_balanced=isBalanced(root->right);
	int hight_left;
	int hight_right;

	if(is_left_balanced && is_right_balanced)
	{
		hight_left=TreeHight(root->left);
		hight_right=TreeHight(root->right);

		return (((hight_left>hight_right)?(hight_left - hight_right):(hight_right - hight_left))>1)?false:true;
	}

	return false;
}
/*submission*/

TreeNode *create_tree(string a,string b)
{
    if(a.length()<=0)
    {
        return  NULL;
    }
    
    int position=b.find(a[0]);
    struct TreeNode *node=new TreeNode;
    
    node->val=a[0];
    node->left=create_tree(a.substr(1,position), b.substr(0,position));
    node->right=create_tree(a.substr(position+1,a.length()-position-1), b.substr(position+1,b.length()-position-1));
    
    return  node;
}

void post(struct TreeNode *node)
{
    if(NULL!=node)
    {
        post(node->left);
        post(node->right);

        cout<<node->val;
    }
}

void destroy_tree(struct TreeNode *node)
{
    if (NULL!=node)
    {
        destroy_tree(node->left);
        destroy_tree(node->right);
        
        delete node;
    }
}