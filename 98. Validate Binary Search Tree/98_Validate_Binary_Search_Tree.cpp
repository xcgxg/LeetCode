#include <iostream>

using namespace std;

struct TreeNode 
{
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

//输入先序遍历和中序遍历字符串构造二叉树
struct TreeNode *create_tree(string,string);

//后序遍历输出二叉树
//void post(TreeNode *);

//销毁二叉树
void destroy_tree(struct TreeNode *);

//是否是平衡二叉树
bool isValidBST(struct TreeNode* root);

//中序遍历
void middle(struct TreeNode* root, int tree[], int &count);

//二叉树高度（叶子结点高度算 1）
int TreeHight(struct TreeNode *);

int main()
{
	string a,b;

    while(cin>>a>>b)
    {
        struct TreeNode *tree=create_tree(a, b);

        printf("%d\n", isValidBST(tree));

        destroy_tree(tree);
    }
}

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

/*submission*/
void middle(struct TreeNode* root, int tree[], int &count)
{
    if(NULL == root)
    {
        return;
    }

    middle(root->left, tree, count);
    tree[count++]=root->val;
    middle(root->right, tree, count);
}

bool isValidBST(struct TreeNode* root)
{
	int tree[10000];
    int count=0;

    middle(root, tree, count);

    int res=true;

    for(int i=0;i<count-1;i++)
    {
        if(tree[i]>=tree[i+1])
        {
            res=false;
            break;
        }
    }

    return res;
}
/*submission*/

struct TreeNode *create_tree(string a,string b)
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