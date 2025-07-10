/* 力扣题号：699.修建二叉搜索树
［题目描述］
将二叉搜索树修剪为三节点数值只在［low,high］范围内（左闭右闭区间）.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归法
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) return NULL;
        if (root->val < low) {
            // 寻找符合[low,high]区间的节点
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        if (root->val > high) {
            // 寻找符合[low,high]区间的节点
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        // 符合[low,high]区间的节点
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

    // 精简版
    TreeNode* trimBST2(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;
        if (root->val < low) return trimBST2(root->right, low, high);
        if (root->val > high) return trimBST2(root->left, low, high);
        root->left = trimBST2(root->left, low, high);
        root->right = trimBST2(root->right, low, high);
        return root;
    }
};

// 迭代法
class Solution2 {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        // 处理头节点，让root移动到[low,high]范围内，注意是左闭右闭区间
        while (root != nullptr && (root->val < low || root->val > high)) {
            if (root->val < low) root = root->right; // 小于low则往右遍历
            else root = root->left; // 大于high则往左遍历
        }
        TreeNode* cur = root;
        // 此时root已经在[low,high]范围内,处理左孩子元素小于low的情况
        while (cur != nullptr) {
            while (cur->left && cur->left->val < low) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;
        // 此时root已经在[low,high]范围内,处理右孩子元素大于high的情况
        while (cur != nullptr) {
            while (cur->right && cur->right->val > high) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};