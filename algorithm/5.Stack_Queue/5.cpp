/*
力扣: 239滑动窗口最大值。
[题目描述]
一个大小为k的滑动窗口,从前向后在数组nums上移动,返回渭动窗口每移动一次时窗口中的最大值。
要求时间复杂度为:O(n).
[示例一]
输入: [2,4,-2,-4,3,1,5],k=4。
输出: [4,4,3,5]
滑动窗口在数组上每移动一次后取窗口中的最大值
[思路]
需要—个队列,将窗口中的元素放入这个队列,随着窗口的移动,队列也一进一出,每次移动之后,告诉我们队列中的最大值是什么
设计单调队列的时候,pop和push操作要保持如下规则:
(1)pop():如果窗口移除的元素value等于单调队列的出口元素,那么队列弹出元素,否则不进行任何操作。
(2)push(value):如果push的元素value大于入口元素的数值,那么就将队列入口的元素弹出,直到push元素的数值小于或等于队列入口元素的数值
基于以上规则,每次窗口移动的时候,只要调用que.front()就可以返回当前窗口的最大值
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
    class MyQueue { // 单调队列(从大到小)
    public:
        deque<int> que; //使用deque实现单调队列
        void pop(int value) { // que.front()返回双端队列的第一个元素(即最前面的元素)
            if (!que.empty() && que.front() == value) {
                que.pop_front();
            }
        }
        void push(int value) { // que.back() 返回双端队列的最后一个元素(即最后面的元素)
            while (!que.empty() && que.back() < value) {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue que;
        for (int i = 0; i < k; i++) { // 先将前k个元素放入队列
            que.push(nums[i]);
        }
        result.push_back(que.front()); // result,记录前k个元素的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]); // 滑动窗口前移除最前面的元素
            que.push(nums[i]); // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2, 4, -2, -4, 3, 1, 5};
    int k = 4;
    Solution solution;
    vector<int> result = solution.maxSlidingWindow(nums, k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}