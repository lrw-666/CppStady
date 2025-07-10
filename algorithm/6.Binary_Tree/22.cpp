/*
力扣题号: 450删除二叉搜索树中的节点。
［思路］
删除二叉搜索树的节点要比增加节点复杂得多,有很多情况需要考虑
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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 情况一：没找到删除的节点，遍历到空节点就直接返回
        if (root == nullptr) return root;
        if (root->val == key) {
            // 情况二：左右孩子都为空(即为叶子节点)，直接删除，返回nullptr为根节点
            // 情况三：其左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
            if (root->left == nullptr) return root->right;
            // 情况四：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            else if (root->right == nullptr) return root->left;
            // 情况五：左右孩子都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
            // 返回删除节点右孩子为新的根节点
            else {
                TreeNode* cur = root->right; // 查找右子树最左面的节点
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
                // 把要删除的节点(root)的左子树放在cur的左孩子的位置
                cur->left = root->left;
                TreeNode* tmp = root; // 保存root节点，下面释放内存
                root = root->right; // 返回旧root的右子树为新root
                delete tmp; // 释放节点内存
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key); // 递归左子树
        if (root->val < key) root->right = deleteNode(root->right, key); // 递归右子树
        return root;
    }
};