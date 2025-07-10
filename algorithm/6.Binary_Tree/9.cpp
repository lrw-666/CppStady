/*
力扣题号: 257二叉树的所有路径。
[题目描述]
给出一个二叉树,返回所有从根节点到叶子节点的路径
说明: 叶子节点是指没有子节点的节点
[思路] 回溯操作
求从根节点到叶子节点的所有路径,所以需要使用前序遍历,这样才方便让父节点指向子节点,找到对应的路径
递归函数参数：
传入二叉树根节点的同时还要用两个数组分别记录每一条路径path和最终结果集result,这里不需要返回值
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // 回溯法(回溯、递归一一对应)
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val);
        // 叶子节点
        if (cur->left == NULL && cur->right == NULL) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back();// 回溯
        }
        if (cur->right) {
            traversal(cur->right, path, result);
            path.pop_back();// 回溯
        }
    }
    // 精简
    void traversal2(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val); // 中
        if (cur->left == NULL && cur->right == NULL) {
            result.push_back(path);
            return;
        }
        if (cur->left) traversal2(cur->left, path + "->", result);//左
        if (cur->right) traversal2(cur->right, path + "->", result);//右
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        if (root == NULL) {
            return result;
        }
        traversal(root, path, result);
        return result;
    }
    // 迭代法:用一个栈模拟递归过程，另一个栈来存饭对应的遍历路径
    vector<string> binaryTreePaths2(TreeNode* root) {
        stack<TreeNode*> treeSt;// 保存树的遍历节点
        stack<string> pathSt;// 保存遍历路径的节点
        vector<string> result;//保存最终路径集合
        if (root == NULL)   return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!treeSt.empty()) {
            TreeNode* node = treeSt.top(); treeSt.pop();//取出节点,中
            string path = pathSt.top(); pathSt.pop();//取出该节点对应的路径
            if (node->left == NULL && node->right == NULL) {//遇到叶子节点
                result.push_back(path);
            }
            if (node->right) { //右
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if (node->left) { //左
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }
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
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<string> result = s.binaryTreePaths(root);
    for (string str : result) {
        cout << str << endl;// 1->2->4 1->2->5 1->3->6 1->3->7
    }
    return 0;
}