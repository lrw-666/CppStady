/*
力扣题号: 347前k个高频元素.
[题目描述]
在一个数组中找到出现频率前k高的元素
[示例一]
输入: nums＝［2,2,2,2,2,3,3,3,1］,k=2。
输出: [2,3]
[思路]
这道题目主要涉及如下三部分内容:
· 统计元素出现的次数:map进行统计
· 对次数排序：一种容器适配器——优先级队列(priority_queue,实际是堆，但接口为队列接口),默认利用max-heap(大顶堆)对元素排序(权值)
· 找出前k个高频元素:使用小顶堆,因为要统计最大的前k个元素,所以只有小顶堆可以每次将最小的元素弹
出,最后小顶堆中剩下的就是前k个最大元素
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution { // 时间复杂度为O(nlogk),空间复杂度为O(n)
public:
    // 小顶堆
    class mycomparison {
    public: // 在C++中，std::pair 是一个标准模板库（STL）提供的容器，用于存储两个不同类型的元素
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        } // 重载了函数调用运算符()的类成员函数。这种用法通常被称为“仿函数”(Functor),它允许类实例像普通函数一样被调用
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计元素出现的次数
        unordered_map<int, int> map; // map<nums[i]
        for  (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        // 对元素出现的次数进行排序
        // 定义一个小顶堆,大小为k.pair<int, int>：这是优先队列中存储的元素类型;
        //vector<pair<int, int>>：这是优先队列使用的底层容器;mycomparison：这是一个自定义比较类，用于定义优先队列中元素的排序规则
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        // 用固定大小为k的小顶堆遍历所有元素出现次数的数值:声明并初始化一个迭代器it,该迭代器指向无序映射(unordered_map)map的起始位置
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it); // *it 是为了获取迭代器 it 所指向的具体元素
            if (pri_que.size() > k) { // 若堆的大小大于k,则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }
        // 找出前k个高频元素,因为小顶堆先弹出的是最小的元素，所以倒序输出到result数组中
        vector<int> result(k); // 声明一个大小为 k 的整数向量（vector），自动默认初始化为0(区别数组)
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2, 2, 2, 2, 2, 3, 3, 3, 1};
    int k = 2;
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}