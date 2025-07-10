/*
力扣题号: 110.平衡二叉树。
[题目描述]
平衡二叉树:每一个节点的左子树和右子树的高度差的绝对值不超过l
[扩展]
二叉树节点的深度:从根节点到该节点的最长简单路径边的条数(或者节点数)
二叉树节点的高度:从该节点到叶子节点的最长简单路径边的条数(或者节点数)
求高度和求深度所用的遍历方式是不一样的,求深度要从上到下去查找，所以需要前序遍历(中
→左→右),而高度只能从下到上去查找,所以需要后序遍历(左→右→中)
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    //迭代法:很多重复计算，效率低
    // 通过栈模拟的后序遍历查找每个节点的高度(求以传入节点为根节点的二叉树的最大深度来求高度)
    int getDepth2(TreeNode* cur) {
        stack<TreeNode*> st;
        if (cur != NULL) st.push(cur);
        int depth = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node!= NULL) {
                st.pop();
                st.push(node);    //中
                st.push(NULL);
                depth++;
                if (node->right) st.push(node->right); //右
                if (node->left) st.push(node->left); //左
            } else {
                st.pop();
                node = st.top();
                st.pop();
                depth--;
            }
            result = result > depth? result : depth;
        }
        return result;
    }
public:
    // 返回以该节点为根节点的二叉树高度,如果不是二叉搜索树则返回-1
    // 递归法
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);
        if (leftDepth == -1) return -1; //说明左子树已不是二叉平衡树
        int rightDepth = getDepth(node->right);
        if (rightDepth == -1) return -1; //说明右子树已不是二叉平衡树
        return abs(leftDepth - rightDepth) <= 1? max(leftDepth, rightDepth) + 1 : -1;
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) == -1 ? false : true;
    }
    // 迭代法
    int result;
    bool isBalanced2(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == NULL) return true;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top(); // 中
            st.pop();
            if (abs(getDepth2(node->left) - getDepth2(node->right)) > 1) {
                return false;
            }
            if (node->right) st.push(node->right); // 右(空节点不入栈)
            if (node->left) st.push(node->left); // 左(空节点不入栈)
        }
        return true;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << s.isBalanced(root) << endl; // 1
    cout << s.isBalanced2(root) << endl; // 1
    return 0;
}