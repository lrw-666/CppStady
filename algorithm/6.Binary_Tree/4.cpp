/*力扣题号: 0226反转二叉树
使用前序遍历和后序遍历都可以，唯独中序遍历不方便,因为中序遍历会把某些节点的左右孩子反转两次
层序遍历也可
递归三部曲:1)确认递归函数参数和返回值 2)确定终止条件 3)确定单层递归逻辑
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 递归法
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        swap(root->left, root->right);  // 中
        invertTree(root->left);         // 左
        invertTree(root->right);        // 右
        return root;
    }
    // 迭代法:前序遍历
    TreeNode* invertTree2(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            swap(node->left, node->right);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        return root;
    }
    // 迭代法:层序遍历
    TreeNode* invertTree3(TreeNode* root) {
        queue<TreeNode*> que;
        if (root!= NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right); //节点处理
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
    }
};