/*
力扣题号: 501二叉搜索树中的众数。
*/
/*
普通二叉树：遍历全树，map统计
二叉搜索树：中序遍历
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归法：普通二叉树
class Solution1 {
private:
    void searchBST(TreeNode* cur, unordered_map<int, int>& map) {
        if (cur == NULL) return;
        map[cur->val]++;// 统计元素出现的频率
        searchBST(cur->left, map);
        searchBST(cur->right, map);
        return;
    }
    bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map; // key:元素值，value:出现频率
        vector<int> result;
        if (root == NULL) return result;
        searchBST(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end()); // 转换为vector
        sort(vec.begin(), vec.end(), cmp); // 排序
        result.push_back(vec[0].first); // 众数
        for (int i = 1; i < vec.size(); i++) {
            // 将出现频率最高的元素放入result数组
            if (vec[i].second == vec[0].second) {
                result.push_back(vec[i].first);
            } else {
                break;
            }
        }
        return result;
    }
};

// 递归法：二叉搜索树
class Solution2 {
private:
    int maxCount; // 最大频率
    int count; // 统计频率
    TreeNode* pre;
    vector<int> result;
    void searchBST(TreeNode* cur) {
        if (cur == NULL) return;
        searchBST(cur->left);
        if (pre == NULL) { // 第一个节点
            count = 1;
        } else if (pre->val == cur->val) { // 与前一个节点的数值相同
            count++;
        } else { // 与前一个节点的数值不同
            count = 1;
        }
        pre = cur; // 更新前一个节点
        if (count == maxCount) { // 如果和最大值相同，则将其放入result
            result.push_back(cur->val);
        }
        if (count > maxCount) { // 如果计数大于最大频率
            maxCount = count; // 更新最大频率
            result.clear(); // 清空result
            result.push_back(cur->val); // 将当前节点值放入result
        }
        searchBST(cur->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        pre = NULL; // 记录前一个节点
        result.clear();

        searchBST(root);
        return result;
    }
};

// 迭代法
class Solution3 {
public:
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int count = 0;
        int maxCount = 0;
        vector<int> result;
        while (cur!= NULL ||!st.empty()) {
            if (cur!= NULL) {
                st.push(cur); // 将访问的节点放入栈
                cur = cur->left; 
            } else {
                cur = st.top(); // 弹出栈顶节点
                st.pop();
                if (pre == NULL) { // 第一个节点
                    count = 1;
                } else if (pre->val == cur->val) { // 与前一个节点的数值相同
                    count++;
                } else { // 与前一个节点的数值不同
                    count = 1;
                }
                if (count == maxCount) { // 如果和最大值相同，则将其放入result
                    result.push_back(cur->val);
                }
                if (count > maxCount) { // 如果计数大于最大频率
                    maxCount = count; // 更新最大频率
                    result.clear(); // 清空result
                    result.push_back(cur->val); // 将当前节点值放入result
                }
                pre = cur; // 更新前一个节点
                cur = cur->right; // 访问右子树
            }
        }
        return result;
    }
};

int main() {
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(2);
    root->right->right->right = new TreeNode(3);
    root->right->right->right->right = new TreeNode(3);
    root->right->right->right->right->right = new TreeNode(4);
    root->right->right->right->right->right->right = new TreeNode(4);
    vector<int> result1 = s1.findMode(root);
    vector<int> result2 = s2.findMode(root);
    vector<int> result3 = s3.findMode(root);
    cout << "Solution1: ";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;
    cout << "Solution2: ";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;
    cout << "Solution3: ";
    for (int i = 0; i < result3.size(); i++) {
        cout << result3[i] << " ";
    }
    cout << endl;
    return 0;
}