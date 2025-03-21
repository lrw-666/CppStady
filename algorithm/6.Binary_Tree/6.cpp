/*
力扣题号: 104二叉树的最大深度。
[题目描述]
求一棵二叉树的最大深度,根节点的深度为1。
[示例一]
如图8-22所示,该二叉树的深度为3(假设每一层的节点为一度)
递归法：
后序遍历，先求左子树深度，再求右子树深度，最后取左右深度中的最大值再加1，即为当前节点为根节点的树的深度
*/
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归法
class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left); // 左
        int rightDepth = getDepth(node->right); // 右
        return max(leftDepth, rightDepth) + 1; // 中
    }
    
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }

    // 精简
    int maxDepth2(TreeNode* root) {
        if (root == NULL) return 0;
        return max(maxDepth2(root->left), maxDepth2(root->right)) + 1;
    }
};
// 迭代法:层序遍历
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth =0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++; // 记录深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
};

int main() {
    Solution2 sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sol.maxDepth(root) << endl; // 3
    return 0;
}