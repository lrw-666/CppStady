/*前中后序统一迭代法——标记法
将将要访问的节点放入栈，将要处理的节点也放入栈中但要做标记
即将要处理的节点放入栈后，紧接着放入一个空指针作为标记。
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
public:
    // 统一迭代法实现中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();// 将该节点弹出，避免重复操作，下面再将左中右节点添加到栈中
                if (node->right) st.push(node->right);// 添加右节点(空节点不入栈)
                st.push(node); // 添加中节点
                st.push(NULL); // 中节点访问过，但还没有处理，加入空节点作为标记
                if (node->left) st.push(node->left);// 添加左节点(空节点不入栈)
            } else {// 只有遇到空节点时，才将下一个节点放入结果集
                st.pop();
                node = st.top();    // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入结果集
            }
        }
        return result;
    }
    // 统一迭代法实现前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right) st.push(node->right); // 右
                if (node->left) st.push(node->left); // 左
                st.push(node); // 中
                st.push(NULL); // 中节点访问过，但还没有处理，加入空节点作为标记
            } else {
                st.pop();
                node = st.top();    // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入结果集
            }
        }
        return result;
    }
    // 统一迭代法实现后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node); // 中
                st.push(NULL); // 中节点访问过，但还没有处理，加入空节点作为标记
                if (node->right) st.push(node->right); // 右
                if (node->left) st.push(node->left); // 左
            } else {
                st.pop();
                node = st.top();    // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入结果集
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
    vector<int> inorder = s.inorderTraversal(root);
    for (int i = 0; i < inorder.size(); i++) {
        cout << inorder[i] << " ";
    }
    cout << endl;
    vector<int> preorder = s.preorderTraversal(root);
    for (int i = 0; i < preorder.size(); i++) {
        cout << preorder[i] << " ";
    }
    cout << endl;
    vector<int> postorder = s.postorderTraversal(root);
    for (int i = 0; i < postorder.size(); i++) {
        cout << postorder[i] << " ";
    }
    cout << endl;
    return 0;
}