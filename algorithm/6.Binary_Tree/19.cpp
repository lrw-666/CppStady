/*
力扣题号: 236.二叉树的最近公共祖先
普通二叉树思路：
  自底而上进行回溯——后序遍历
  如何判断一个节点是不是节点q和节点p的公共祖先呢?
  如果找到一个节点,发现左子树出现节点p，右子树出现节点q，或者左子树出现节点q,右子
树出现节点p,那么该节点就是节点p和q的最近公共祖先
*/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if ( root == p || root == q || root == NULL ) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if ( left != NULL && right != NULL ) return root;

        if ( left == NULL && right != NULL ) return right;
        else if ( left != NULL && right == NULL ) return left;
        else {
          return NULL;
        }
    }

    // 精简版
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if ( root == q || root == p || root == NULL ) return root;
        TreeNode* left = lowestCommonAncestor2(root->left, p, q);
        TreeNode* right = lowestCommonAncestor2(root->right, p, q);
        if ( left != NULL && right != NULL ) return root;
        if ( left == NULL ) return right;
        return left;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* p = root->left->right->left;
    TreeNode* q = root->left->right->right;
    TreeNode* lca = s.lowestCommonAncestor(root, p, q);
    cout << lca->val << endl;

    TreeNode* lca2 = s.lowestCommonAncestor2(root, p, q);
    cout << lca2->val << endl;

    return 0;
}