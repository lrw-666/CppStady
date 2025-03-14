/*
力扣题号: 18.四数之和.
在一个数组中，找到四个元素，(这四个元素就是一个四元组),使其相加等于target。问在这个
数组中可以找到多少组这样的元组(四元组不可重复)?
[示例一]
输入: nums＝[-1,3,4,-3,0,-1,3,-3], target＝0。
输出:
[
    [-3,-3,3,3]
    [-3,-1,0,4]
]
[思路]
与三数之和一个思路，双指针法，在其基础上再套一层for循环
四数之和的双指针解法是两层for循环遍历，得到的nums[k]+nums[i]+nums[left]+nums[right]==target的情况
三数之和的时间复杂度是O(n^2)，四数之和的时间复杂度是O(n^3),同理，五数之和、六数之和等都采用这种解法
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            if (k > 0 && nums[k] == nums[k-1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 去重,且target是任意值
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1, right = nums.size() - 1;
                while (left < right) {
                    if (nums[k] + nums[i] > target - (nums[left] + nums[right])) {
                        right--;
                    }else if (nums[k] + nums[i] < target - (nums[left] + nums[right])) {
                        left++;
                    }else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 去重逻辑应该放在找到一个四元组之后
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;
                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-1, 3, 4, -3, 0, -1, 3, -3};
    int target = 0;
    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums, target);
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    } // [-3 -3 3 3] [-3 -1 0 4]
    return 0;
}