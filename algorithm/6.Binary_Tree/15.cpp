/*
力扣题号: 700二叉搜索树中的搜索
[题目描述]
确定一个节点是否在二叉搜索树中,如果在,则返回这个节点,如果不在，则返回NULL。
*/
# include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 递归法
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) return root;
        if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
    // 迭代法
    TreeNode* searchBST2(TreeNode* root, int val) {
        while (root != NULL) {
            if (root->val > val) root = root->left;
            else if (root->val < val) root = root->right;
            else return root;
        }
        return NULL;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    TreeNode* res = s.searchBST(root, 2);
    if (res) {
        cout << "The node " << res->val << " is in the BST." << endl;
    } else {
        cout << "The node is not in the BST." << endl;
    }
    return 0;
}