/*
力扣题号: 701.二叉搜索树中的插入操作。
［题目描述］
二叉搜索树中节点的数值是唯一的,新插入的节点的数值和树中节点的数值也不同。
［思路］
如图8-51所示,在二叉搜索树中先后插入节点10和节点6。可以发现插入的过程中并不需要修
改原有二叉搜索树的结构.只要遍历二叉搜索树,找到空节点插入元素即可
*/
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* parent;
    void traversal(TreeNode* cur, int val) {
        if (cur == NULL) {
            TreeNode* node = new TreeNode(val);
            if (val > parent->val) parent->right = node;
            else parent->left = node;
            return;
        }
        if (cur->val > val) traversal(cur->left, val);
        if (cur->val < val) traversal(cur->right, val);
        return;
    }
public:
    // 递归法:通过递归函数的返回值完成父子节点的赋值非常方便
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        parent = new TreeNode(0);
        if (root == NULL) {
            root = new TreeNode(val);
        }
        traversal(root, val);
        return root;
    }
    // 迭代法:记录当前遍历的节点的父节点,这样才能做插入节点的操作
    TreeNode* insertIntoBST2(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* cur = root;
        // 记录上一个节点
        TreeNode* parent = root;
        while (cur!= NULL) {
            parent = cur;
            if (cur->val > val) cur = cur->left;
            else cur = cur->right;
        }
        TreeNode* node = new TreeNode(val);
        // 使用parent节点进行赋值
        if (val < parent->val) parent->left = node;
        else parent->right = node;
        return root;
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
    s.insertIntoBST(root, 5);
    s.insertIntoBST2(root, 10);
    s.insertIntoBST(root, 6);
    // 输出结果:4 2 7 1 3 6 10 9
    cout << root->val << " " << root->left->val << " " << root->right->val << " " << root->left->left->val << " " << root->left->right->val << " " << root->right->left->val << " " << root->right->right->right->val << " "  << root->right->right->val << endl;
    return 0;
}

