// std::set和std::multiset的底层实现都是红黑树,std::unorderedset的底层实现是哈希表
/*
力扣题号: 349.两个数组的交集.
[题目描述]
计算两个数组的交集,交集里的元素都是唯一的
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end()); // 存放nums1所有不重复的元素
        // C++11引入的范围基于for循环（range-based for loop）
        for (int num : nums2) {
            // 发现nums2的元素在nums_set中出现过
            if (nums_set.find(num) != nums_set.end() ) {  // find函数用于在集合中查找指定的元素，如果找到该元素，find函数返回指向该元素的迭代器；如果未找到，则返回end()迭代器，这个迭代器指向集合的末尾（注意，不是最后一个元素，而是最后一个元素之后的位置）
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());  // unordered_set并不能直接转换为vector的初始化列表list
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution solution;
    vector<int> result = solution.intersection(nums1, nums2);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}