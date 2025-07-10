/*
力扣题号: 98验证二叉搜索树。
[题目描述]
判断二叉树是不是二叉搜索树的条件如下
· 若它的左子树不空,则左子树上所有节点的值均小于它的根节点的值
· 若它的右子树不空,则右子树上所有节点的值均大于它的根节点的值
· 它的左子树和右子树也分别为二叉搜索树
假设树中没有重复元素
[陷阱]
1. 单纯地比较左节点与中间节点, 右节点与中间节点的大小
    我们要比较的是左子树所有节点是否小于中间节点、右子树所有节点是否大于中间节点
2. 建议避免初始化最小值
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> vec;
    void traversal (TreeNode* root) {
        if (root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val);// 将二叉搜索树转换为有序数组
        traversal(root->right);
    }
public:
    // 递归法1:采用中序遍历将二叉搜索树转变成一个数组
    bool isValidBST(TreeNode* root) {
        vec.clear();
        traversal(root);
        for (int i = 1; i < vec.size(); i++) {
            // 注意要使用<=运算符,搜索树中不能有相同元素
            if (vec[i] <= vec[i-1]) return false;
        }
        return true;
    }
    // 递归法2:在递归遍历的过程中直接判断序列是否有序
    // 通过以下方法获取最左面节点的数值来实现判断的逻辑
    TreeNode* pre = NULL;// 记录前一个节点
    bool isValidBST2(TreeNode* root) {
        if (root == NULL) return true;
        bool left = isValidBST2(root->left);

        if (pre != NULL && pre->val >= root->val) return false;
        pre = root;// 记录前一个节点

        bool right = isValidBST2(root->right);
        return left && right;
    }
    // 迭代法:利用栈实现中序遍历
    bool isValidBST3(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;// 记录前一个节点
        while (cur != NULL ||!st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;//左
            } else {
                cur = st.top();//中
                st.pop();
                if (pre != NULL && pre->val >= cur->val) return false;
                pre = cur;// 记录前一个节点
                cur = cur->right;//右
            }
        }
        return true;
    }
};
    
    