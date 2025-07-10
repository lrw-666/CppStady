/*
力扣题号: 105.使用前序与中序遍历序列构造二叉树
原理与前者一致
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;    
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* traversal (vector<int>& inorder, int inorderBegin, int inorderEnd,
                        vector<int>& preorder, int preorderBegin, int preorderEnd) {
        if (preorderBegin == preorderEnd) return NULL;
        // 注意用preorderBegin，不要用0
        int rootValue = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootValue);

        if (preorderEnd - preorderBegin == 1) return root;
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex <= inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }
        // 切割中序数组
        // 中序左区间，左闭右开[leftInorderBegin, leftInorderEnd)
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        // 中序右区间，左闭右开[rightInorderBegin, rightInorderEnd)
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;
        
        // 切割前序数组
        // 前序左区间，左闭右开[leftPreorderBegin, leftPreorderEnd)
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + 1 +delimiterIndex - inorderBegin;// 终止位置是起始位置加上中序左区间的长度
        // 前序右区间，左闭右开[rightPreorderBegin, rightPreorderEnd)
        int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
        int rightPreorderEnd = preorderEnd;
        
        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, preorder, leftPreorderBegin, leftPreorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin, rightPreorderEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
        if (inorder.size() == 0 || preorder.size() == 0) return NULL;
        // 坚持左闭右开原则
        return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }
};

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,20,15,7};
    Solution solution;
    TreeNode* root = solution.buildTree(inorder, preorder);
    // 打印二叉树
    if (root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return 0;
}