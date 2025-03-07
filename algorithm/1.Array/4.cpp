/*
力拍题号: 209长度最小的子数组° 』
［题目描述］
在-个正整数数组nums中找到最小长度的连续子数组,使子数组元素之禾日大于或等于s。
返回满足条件的连续子数组的最小长度’如果没找到则返回0·
［示例］
输入: s＝l2’ nums＝［4,6,2,4’9,8’7］。
输出: 2°
［解释］
连续子数组［4,9］、［9,8］租［8,7］满定条件,长度皆为2。
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 暴力解法:时间复杂度:O（n^2）空间复杂度:O（l）。
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX; // 最终的结果
        int sum = 0; // 子数组的元素之和
        int subLength = 0; // 子数组的长度
        for (int i = 0; i < nums.size(); i++) { // 设置子数组起点为i
            sum = 0;
            for (int j = i; j < nums.size(); j++) { // 设置子数组终点为j
                sum += nums[j];
                if (sum >= s) { // 子数组元素之和大于等于s
                    subLength = j - i + 1; // 子数组的长度
                    result = result < subLength ? result : subLength; // 更新结果
                    break;
                }
            }
        }
        return result == INT32_MAX? 0 : result; // 若没找到则返回0
    }
    // 滑动窗口：根据当前子数组和的大小）不断调节子数组的起始位置
    // 时间复杂度:O(n) 空间复杂度:O(1)
    int minSubArrayLen2(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;        // 滑动窗口的元素之和
        int i = 0;          // 滑动窗口的起始位置
        int subLength = 0;  // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 这里使用while，每次更新i(起始位置)并不断比较子数组是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 滑动窗口的长度
                result = result < subLength ? result : subLength; 
                // 精髓：不断变更i(子数组起始位置)
                sum -= nums[i++];
            }
        }
        // 若result没有被赋值，则返回0，说明没有符合条件的子数组
        return result == INT32_MAX ? 0 : result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 6, 2, 4, 9, 8, 7};
    int s1 = 20;
    int result = s.minSubArrayLen2(s1, nums);
    cout << "result: " << result << endl;
    return 0;
}