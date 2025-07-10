/*
力扣题号: 113.路径总和II.
找到所有从根节点到叶子节点的路径,使这些路径的节点总和等于目标值
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
    vector<vector<int>> result;
    vector<int> path;
    // 递归函数不需要返回值，因为要遍历整棵树
    void traversal(TreeNode* cur, int count) {
        // 遇到叶子节点且找到了和为sum的路径
        if (!cur->left && !cur->right && count == 0) {
            result.push_back(path);
            return;
        }
        // 遇到叶子节点且没有找到合适的边,直接返回
        if (!cur->left && !cur->right) return;

        if (cur->left) { // 左(空节点不遍历)
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count); // 递归
            count += cur->left->val; // 回溯
            path.pop_back(); // 回溯
        }
        if (cur->right) { // 右(空节点不遍历)
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count); // 递归
            count += cur->right->val; // 回溯
            path.pop_back(); // 回溯
        }
        return ;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
        path.clear();
        if (root == NULL) return result;
        path.push_back(root->val); // 把根节点放入路径
        traversal(root, sum - root->val); // 递归
        return result;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    vector<vector<int>> result = s.pathSum(root, 22);
    for (auto path : result) {
        for (auto num : path) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}