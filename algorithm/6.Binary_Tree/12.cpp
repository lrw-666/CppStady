/*
力扣题号: 106使用中序与后序遍历序列构造二叉树
给出中序遍历和后序遍历的两个数组(没有重复元素),通过这两个数组构造一棵二叉树
[思路]
根据两个遍历顺序构造一个唯一的二叉树的原理:
以后序数组的最后一个元素作为切割点,先切割中序数组,然后根据中序数组,反过来再切割后序数组。
一层一层切下去,每次后序数组的最后一个元素就是节点元素。
说到一层一层切割，就应该想到递归:
· 第一步:如果数组长度为零,则说明是空节点。
· 第二步:如果数组不为空，那么将后序数组的最后一个元素作为节点元素。
· 第三步:找到后序数组的最后一个元素在中序数组中的位置并将具作为切割点
· 第四步:切割中序数组，切成中序左数组和中序右数组(一定是先切割中序数组)。
· 第五步:切割后序数组,切成后序左数组和后序右数组.
· 第六步:递归处理左区间和右区间。
切割标准:左闭右开[0,delimiterIndex)和[delimiterIndex+1,end)
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

class Solution {
private:
    TreeNode* traverssal (vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;
        // 后序遍历数组的最后一个元素就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);
        // 叶子节点
        if (postorder.size() == 1) return root;
        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }
        // 切割中序数组
        // 左闭右开区间: [0,delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex+1,end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
        // postorder,舍弃末尾元素
        postorder.resize(postorder.size() - 1);
        // 切割后序数组,依然为左闭右开区间,使用左中序数组的长度作为切割点
        // [0, leftInorder.size())
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
        // 递归处理左右子树
        root->left = traverssal(leftInorder, leftPostorder);
        root->right = traverssal(rightInorder, rightPostorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() ==0 || postorder.size() == 0) return NULL;
        return traverssal(inorder, postorder);
    }
};

// 性能优化:使用下标分割数组(思路一致,不用重复定义vector)
class Solution2 {
private:
    // 中序区间:[inorderBegin, inorderEnd), 后序区间:[postorderBegin, postorderEnd)
    TreeNode* traverssal (vector<int>& inorder, int inorderBegin, int inorderEnd,
         vector<int>& postorder, int postorderBegin, int postorderEnd) {
        if (postorderEnd - postorderBegin == 0) return NULL;

        int rootValue = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootValue);
        
        if (postorderEnd - postorderBegin == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }
        // 切割中序数组
        // 左中序区间,左闭右开[leftInorderBegin, leftInorderEnd)
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        // 右中序区间,左闭右开[rightInorderBegin, rightInorderEnd)
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;
        // 切割后序数组
        // 左后序区间,左闭右开[leftPostorderBegin, leftPostorderEnd)
        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin +delimiterIndex - inorderBegin;// 终止位置需要加上中序区间的长度
        // 右后序区间,左闭右开[rightPostorderBegin, rightPostorderEnd)
        int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
        // 舍弃最后一个元素,其已经作为节点了
        int rightPostorderEnd = postorderEnd - 1;
        // 递归处理左右子树
        root->left = traverssal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traverssal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() ==0 || postorder.size() == 0) return NULL;
        // 左闭右开原则
        return traverssal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution2 solution;
    TreeNode* root = solution.buildTree(inorder, postorder);
    // 打印二叉树
    if (root != NULL) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
        }
    }
    return 0;
}