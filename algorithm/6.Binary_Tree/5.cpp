/*
力扣题号: 1O1.对称二叉树
[题目描述]
给出一个二叉树,判断其是不是中心轴对称的.
[思路]
递归法:
判断二叉树是否对称,要比较的是根节点的左子树与右子树是不星相互反转的
本题只能是"后序遍历",因为我们要通过递归函数的返回值来判断两棵子树的内侧节点和外侧节点是否相等。
因为要遍历两棵树,而且要比较内侧和外侧节点是否相等,所以准确地说,一棵树的遍历顺序是左→右→中，
另一棵树的遍历顺序是右→左→中。
迭代法:
可使用队列比较两棵树(根节点的左右子树)是否相互反转
队列：两个指针指向根节点的左子树和右子树，然后将队列元素弹出并比较是否相等，若相等，继续把两个元素的左右孩子添加到队列中
继续从队列中取出两个元素并比较是否相同，如果最后队列为空依然没有找到两个不相同的元素，则这棵树就是对称二叉树
栈：迭代法原理即把左右子树要比较的元素按一定顺序放进容器，再成对取出比较；因此栈同理
*/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归法
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        // 首先排除空节点的情况
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val) return false;

        // 此时就是左右节点都不为空且数值相同的情况
        // 递归，做下一层判断
        // 左子树:左;右子树:右
        bool outside = compare(left->left, right->right);
        // 左子树:右;右子树:左
        bool inside = compare(left->right, right->left);
        // 左子树:中;右子树:中
        bool isSame = outside && inside;
        return isSame;
    }

    // 简洁版
    bool compare2(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left->val != right->val) return false;
        else return compare2(left->left, right->right) && compare2(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }

    bool isSymmetric2(TreeNode* root) {
        if (root == NULL) return true;
        return compare2(root->left, root->right);
    }
};

// 迭代法
class Solution2 {
public:
    // 队列法
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left); //将左子树头节点加入队列
        que.push(root->right);//将右子树头节点加入队列
        while (!que.empty()) {//判断两棵树是否相互反转
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            // 左节点为空、右节点为空，说明是对称的
            if (!leftNode && !rightNode) continue;

            // 左右一个节点不为空，或者都不为空但数值不同，返回false
            if ((!leftNode || !rightNode || leftNode->val != rightNode->val)) {
                return false;
            }
            que.push(leftNode->left);  //左子树的左节点加入队列
            que.push(rightNode->right);//右子树的右节点加入队列
            que.push(leftNode->right); //左子树的右节点加入队列
            que.push(rightNode->left); //右子树的左节点加入队列
        }
        return true;
    }
    // 栈法：将队列原封不动改成栈即可
    bool isSymmetric2(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while (!st.empty()) {
            TreeNode* leftNode = st.top(); st.pop();
            TreeNode* rightNode = st.top(); st.pop();
            if (!leftNode && !rightNode) continue;
            if ((!leftNode || !rightNode || leftNode->val != rightNode->val)) {
                return false;
            }
            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
        }
        return true;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << s.isSymmetric(root) << endl; // true
    cout << s.isSymmetric2(root) << endl; // true
    return 0;
}