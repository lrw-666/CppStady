/*
力扣题号: 704二分宣找。
［题目描述］
在＿个有序无重复元素的数组nums中’寻找＿个元素target,如果找到了就返回对应的下标,
如果没找到就返回ˉ1。
［示例l
输入: ［l’2’3’4’7’9’10］, 2°
输出: 1°
输入: ［l,2,3,4,7,9’l0］〗 8°
输出: ˉl
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
        // 写法一：左闭右闭
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            while (left <= right) {
                // 防止溢出,等同于(right+left)/2
                int mid = left + (right - left) / 2;
                if (nums[mid] > target) {
                    right = mid - 1;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    return mid;
                }
            }
            // 未找到目标值
            return -1;
        }

        // 写法二：左闭右开
        int search2(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size();
            while (left < right) {
                // 结果右移一位,相当于除以2并取整
                int mid = left + ((right - left) >> 1);
                if (nums[mid] > target) {
                    right = mid;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    return mid;
                }
            }
            // 未找到目标值
            return -1;
        }
};

int main() {
    vector<int> nums = {2, 3, 4, 7, 9, 10};
    int target = 3;
    Solution solution;
    int result = solution.search2(nums, target);
    cout << result << endl;
    return 0;
}