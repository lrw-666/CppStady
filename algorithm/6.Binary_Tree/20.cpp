/*
力扣题号：235.二叉搜索树的最近公共祖先
在二叉搜索树中找到节点q和节点p的最近公共祖先。输入的节点q和节点p是存在于树中的节点
思路：在从上到下遍历二叉搜索树的过程中，如果cur节点的数值在[p,q]区间,则说明该节点cur就是最近公共祖先
*/
#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left; 
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
private:
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur == NULL) return cur;
                                                      // 中
        if (cur->val > p->val && cur->val > q->val) { // 左
            TreeNode* left = traversal(cur->left, p, q);
            if (left != NULL) {
                return left;
            }
        }
        if (cur->val < p->val && cur->val < q->val) { // 右
            TreeNode* right = traversal(cur->right, p, q);
            if (right != NULL) {
                return right;
            }
        }
        return cur;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
    // 精简版
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else return root;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    TreeNode* p = root->left->right;
    TreeNode* q = root->left;
    TreeNode* ans = s.lowestCommonAncestor(root, p, q);
    cout << ans->val << endl;
    TreeNode* ans2 = s.lowestCommonAncestor2(root, p, q);
    cout << ans2->val << endl;
    return 0;
}