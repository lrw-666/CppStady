/*
力扣题号: 617.合并二叉树
[题目描述] 合并两裸二叉树
同位置的节点值相加，思路与遍历一棵树的逻辑一致
*/
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归法:前序遍历
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return t2; // 若t1为空，两树合并为t2
        if (t2 == NULL) return t1; // 若t2为空，两树合并为t1
        // 修改了t1的数值和结构
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left); // 递归合并左子树
        t1->right = mergeTrees(t1->right, t2->right); // 递归合并右子树
        return t1; // 返回合并后的根节点
    }
    // 也可以不修改t1与t2的结构，重新定义一棵树
    TreeNode* mergeTrees2(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return t2; // 若t1为空，两树合并为t2
        if (t2 == NULL) return t1; // 若t2为空，两树合并为t1
        // 定义新树的根节点
        TreeNode* root = new TreeNode(0);
        root->val = t1->val + t2->val;
        root->left = mergeTrees2(t1->left, t2->left); // 递归合并左子树
        root->right = mergeTrees2(t1->right, t2->right); // 递归合并右子树
        return root; // 返回合并后的根节点
    }
};

// 迭代法:队列模拟层序遍历
class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;
        queue<TreeNode*> que;
        que.push(t1);
        que.push(t2);
        while (!que.empty()) {
            TreeNode* node1 = que.front(); que.pop();
            TreeNode* node2 = que.front(); que.pop();
            // 此时两个节点一定不为空,val相加
            node1->val += node2->val;
            // 若两棵树左节点都不为空,加入队列
            if (node1->left != NULL && node2->left != NULL) {
                que.push(node1->left);
                que.push(node2->left);
            }
            // 若两棵树右节点都不为空,加入队列
            if (node1->right != NULL && node2->right != NULL) {
                que.push(node1->right);
                que.push(node2->right);
            }
            // t1左节点为空、t2左节点不为空,则将t2的左节点赋给t1的左节点
            if (node1->left == NULL && node2->left != NULL) {
                node1->left = node2->left;
            }
            // t1右节点为空、t2右节点不为空,则将t2的右节点赋给t1的右节点
            if (node1->right == NULL && node2->right != NULL) {
                node1->right = node2->right;
            }
        }
        return t1;
    }
};

int main() {
    Solution2 s;
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);
    t1->left->right = new TreeNode(3);
    t1->right->right = new TreeNode(4);
    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);
    TreeNode* t3 = s.mergeTrees(t1, t2);
    cout << t3->val << endl; // 3
    cout << t3->left->val << endl; // 4
    cout << t3->right->val << endl; // 5
    cout << t3->left->left->val << endl; // 5
    cout << t3->left->right->val << endl; // 7
    cout << t3->right->right->val << endl; // 11
    return 0;
}