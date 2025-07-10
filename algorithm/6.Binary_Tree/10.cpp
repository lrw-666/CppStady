/*
力扣题号: 112.路径总和。
[题目描述]
找到一条从根节点到叶子节点的路径，使这个路径的节点总和等于目标值。
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

//递归法:深度优先遍历
class Solution {
private:
    bool traversal(TreeNode* cur, int count) {
        // 遇到叶子节点，并计数为0
        if (!cur->left && !cur->right && count == 0) return true;
        if (!cur->left && !cur->right) return false;//遇到叶子节点直接返回

        if (cur->left) { // 左子树
            count -= cur->left->val;// 递归，处理节点
            if (traversal(cur->left, count)) return true;
            count += cur->left->val; // 回溯,撤销处理结果
        }
        if (cur->right) { // 右子树
            count -= cur->right->val;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val;
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return traversal(root, sum - root->val);
    }
    // 简化代码
    bool hasPathSum2(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (!root->left && !root->right && sum == root->val) return true;
        return hasPathSum2(root->left, sum - root->val) || hasPathSum2(root->right, sum - root->val);
    }
};

// 迭代法(栈模拟前序遍历)：pair结构存放栈内元素，pair<TreeNode*, int>
class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        // 此时栈内存放的是pair<TreeNode*, int>
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int>(root, root->val));
        while (!st.empty()) {
            pair<TreeNode*, int> node = st.top();
            st.pop();
            // 叶子节点，同时该节点的路径数值等于sum,则返回true
            if (!node.first->left && !node.first->right && node.second == sum) return true;

            // 右节点,一个节点入栈后，记录该节点的路径数值
            if (node.first->right) {
                st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
            }
            // 左节点,一个节点入栈后，记录该节点的路径数值
            if (node.first->left) {
                st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(5);    // 5
    root->left = new TreeNode(4);      // 4
    root->right = new TreeNode(8);     // 8
    root->left->left = new TreeNode(11); // 11
    root->left = new TreeNode(7); // 7
    root->left->right = new TreeNode(2); // 2
    root->right->left = new TreeNode(13); // 13
    root->right->right = new TreeNode(4); // 4
    root->right->right->left = new TreeNode(5); // 5
    root->right->right->right = new TreeNode(1); // 1
    cout << s.hasPathSum2(root, 22) << endl; // true
    return 0;
}