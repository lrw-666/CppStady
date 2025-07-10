/*
力扣题号: 530.二叉搜索树的最小绝对差.
[题目描述]
给出一棵所有节点为非负值的二叉搜索树,请计算树中任意两个节点的差的绝对值的最小值.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归法:将二叉搜索树转换为有序数组,然后遍历一遍数组，即可统计最小差值
class Solution {
private:
    vector<int> vec;
    void traversal(TreeNode* root) {
        if (root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val); // 将二叉搜索树转换为有序数组
        traversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        traversal(root);
        if (vec.size() < 2) return 0;
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); i++) { // 统计有序数组的最小差值
            result = min(result, abs(vec[i] - vec[i-1]));
        }
        return result;
    }
};
// 对二叉搜索树进行中序遍历的过程中，可直接找到相邻两个节点的差值-用一个pre节点记录cur节点的前一个节点
class Solution2 {
private:
    int result = INT_MAX;
    TreeNode* pre = NULL;
    void traversal(TreeNode* cur) {
        if (cur == NULL) return;
        traversal(cur->left);
        if (pre!= NULL) {
            result = min(result, abs(cur->val - pre->val));
        }
        pre = cur;
        traversal(cur->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};

// 迭代法
class Solution3 {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int result = INT_MAX;
        while (cur!= NULL ||!st.empty()) {
            if (cur!= NULL) {
                st.push(cur);// 将访问的节点放入栈
                cur = cur->left;// 左
            } else {
                cur = st.top();
                st.pop();
                if (pre!= NULL) { // 中
                    result = min(result, abs(cur->val - pre->val));
                }
                pre = cur; // 记录前一个节点
                cur = cur->right;// 右
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(4);  
    root->left = new TreeNode(2);  
    root->right = new TreeNode(6);  
    root->left->left = new TreeNode(1);  
    root->left->right = new TreeNode(3);  
    root->right->left = new TreeNode(5);  
    root->right->right = new TreeNode(7);  
    cout << s.getMinimumDifference(root) << endl; // 输出: 1
    return 0;
}
