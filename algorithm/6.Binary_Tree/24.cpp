/*构造一棵平衡二叉搜索树
力扣题号：108. 将有序数组转换为二叉搜索树
［题目描述］
给定一个有序数组（从小到大），构造一棵二叉搜索树。
平衡二叉搜索树即左石子树的高度差的绝对值不超过l。
［思路］
在8.13节中讲解了如何根据数组构造一棵二叉树。本质上就是寻找分割点，将分割点作为当前节点然后递归处理左区间和右区间。
基于有序数组构造二叉搜索树,寻找分割点就比较容易了。分割点就是数组中间位置的节点。
如果数组的长度为偶数，中间节点有两个，那么取哪一个节点作为分割点呢？
取哪一个都可以，只不过会构成不同的平衡二叉搜索树。
*/
#include <iostream>
#include <vector>
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
private:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        // 如果数组长度为偶数,中间位置有两个元素,则取靠左边的元素
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
};

// 迭代法:通过三个队列来模拟迭代法，第一个队列保存遍历的节点，第二个队列保存左区间下标，
// 第三个队列保存右区间下标，模拟不断分割的过程。
class Solution2 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(0); // 初始化根节点
        queue<TreeNode*> nodeQueue;       // 保存遍历的节点
        queue<int> leftQueue;             // 保存左区间下标 
        queue<int> rightQueue;            // 保存右区间下标

        nodeQueue.push(root);             // 根节点入队
        leftQueue.push(0);                // 0为左区间下标的初始位置
        rightQueue.push(nums.size() - 1); // nums.size() - 1为右区间下标的初始位置

        while (!nodeQueue.empty()) {
            TreeNode* curNode = nodeQueue.front(); // 取出队首节点
            nodeQueue.pop();                       // 弹出队首节点
            int left = leftQueue.front(); leftQueue.pop();
            int right = rightQueue.front(); rightQueue.pop();
            int mid = left + (right - left) / 2;

            curNode->val = nums[mid];

            if (left <= mid - 1) {         // 处理左区间
                curNode->left = new TreeNode(0);
                nodeQueue.push(curNode->left);
                leftQueue.push(left);
                rightQueue.push(mid - 1);
            }

            if (right >= mid + 1) {        // 处理右区间
                curNode->right = new TreeNode(0);
                nodeQueue.push(curNode->right);
                leftQueue.push(mid + 1);
                rightQueue.push(right);
            }
        }
        return root;
    }
};