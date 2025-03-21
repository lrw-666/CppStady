/*
C++中map、set、multimap、multiset的底层实现都是平衡二叉树，因此map、set的增删操作的时间复杂度为O(log n)
而unordered_map、unordered_set的底层实现是哈希表

二叉树前中后序的递归遍历:
需要传入数组(C++中使用vector)来存放节点数值
*/
#include<iostream>
#include<vector>
#include <stack>
#include <algorithm>

using namespace std;

//二叉树定义:
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

// 递归遍历
class Solution{
public:
    //前序遍历:根左右
    void traversalpre(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val); //中
        traversalpre(cur->left, vec); //左
        traversalpre(cur->right, vec); //右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversalpre(root, result);
        return result;
    }
    //中序遍历:左根右
    void traversalmid(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversalmid(cur->left, vec); //左
        vec.push_back(cur->val); //中
        traversalmid(cur->right, vec); //右
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversalmid(root, result);
        return result;
    }
    //后序遍历:左右根
    void traversalpost(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversalpost(cur->left, vec); //左
        traversalpost(cur->right, vec); //右
        vec.push_back(cur->val); //中
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversalpost(root, result);
        return result;
    }
};

// 迭代遍历:借助栈
class Solution2{
public:
    //前序遍历:根左右    力扣题号: 144二叉树的前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return result;
    }
    //中序遍历:左根右    力扣题号: 94二叉树的中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur!= NULL) {
                st.push(cur);
                cur = cur->left;    // 左
            } else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);  // 中
                cur = cur->right;    // 右
            }
        }
        return result;
    }
    //后序遍历:左右根    力扣题号: 145二叉树的后序遍历
    // 后序遍历的顺序是左->右->中,只需要调整前序遍历的代码顺序,变成中->右->左的遍历顺序,然后反转result数组,输出结果的顺序就是左→右→中了
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            // 调整前序遍历的代码顺序,变成中->右->左的遍历顺序
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        // 反转result数组,输出结果的顺序就是左→右→中了
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int> result = s.preorderTraversal(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    result = s.inorderTraversal(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;    
    result = s.postorderTraversal(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}