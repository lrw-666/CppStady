/*
力扣题号: 111.二叉树的最小深度
[题目描述]
求一棵二叉树的最小深度,根节点的深度为l.
最小深度:从根节点到最近叶子节点的最短路径上的节点数量
[思路]
后序遍历(要比较递归返回之后的结果)
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
        int leftDepth = getDepth(node->left);    // 左
        int rightDepth = getDepth(node->right);  // 右

        // 当左子树为空、右不为空时，并不是最小深度
        if (node->left == NULL && node->right != NULL) {
            return rightDepth + 1;
        }
        // 当左不为空、右为空时，并不是最小深度
        if (node->left != NULL && node->right == NULL) {
            return leftDepth + 1;
        }
        // 当左右都不为空时，才是最小深度
        return min(leftDepth, rightDepth) + 1;
    }

    int minDepth(TreeNode* root) {
        return getDepth(root);
    }

    // 精简代码
    int minDepth2(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right != NULL) {
            return 1 + minDepth2(root->right);
        }
        if (root->left != NULL && root->right == NULL) {
            return 1 + minDepth2(root->left);
        }
        return 1 + min(minDepth2(root->left), minDepth2(root->right));
    }
};

// 迭代法
class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++; //记录最小深度
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) {
                    // 当左右孩子都为空时，说明是二叉树的底层了，退出
                    return depth;
                }
            }
        }
        return depth;
    }
};

int main() {
    Solution2 s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << s.minDepth(root) << endl; // 2
    return 0;
}