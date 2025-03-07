/*
力扣题号: 1.两数之租。
在数组中找到两个元素的数值之和为目标值，返回这两个元素的下标。
［示例一］
输入: nums＝［2,7,11,15],targe＝9。
输出: [0,1]
解释:因为nums[0]＋nums[1]＝9,所以返回[0,1]。
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 暴力解法
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    // 哈希表解法
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        // 遍历数组中的每个元素
        for (int i = 0; i < nums.size(); i++) {
            // 在哈希表中查找是否存在与当前元素配对的目标值
            auto iter = map.find(target - nums[i]);
            // 如果找到配对的目标值，返回其索引和当前元素的索引
            if (iter != map.end()) {
                return {iter->second, i}; // iter->second 表示的是哈希表中某个键值对的值部分
            }
            // 如果未找到，将当前元素及其索引插入哈希表
            map.insert(pair<int, int>(nums[i], i)); // pair<int, int>是一个标准库模板类，用于存储一对值，分别是两个整数
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    cout << "result: " << result[0] << " " << result[1] << endl;
    return 0;
}