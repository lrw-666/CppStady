/*
力扣题号: 15三数之和
在一个数组中,找到三个元素(这三个元素就是一个三元组),使具相加等于0.这个数组中可
以找到多少组这样的元组(三元组不可重复)？
[示例一]
输入: nums＝［-1,3,4,-3,0,-1,3,-3］
输出: [[-3,-l,4][-3,0,3]].
注意[0, 0, 0, 0]这组数据。
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 哈希解法：时间复杂度为O(n²)，通过哈希集合的动态更新实现了高效去重。
    // 通过两层for循环就可以确定a和b的数值了,可以使用哈希法来确定0-(a＋b)是否在数组中出现过
    // 把符合条件的三元组放进vector中,然后去重
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出 a+b+c=0, a= nums[i], b=nums[j], c=-(a+b)
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后若第一个元素已经大于0，那么不可能凑成三元组
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) { // 三元组元素a去重
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2
                        && nums[j] == nums[j-1]
                        && nums[j-1] == nums[j-2]) { // 三元组元素b去重
                    continue;
                }
                int c = 0 - nums[i] - nums[j];
                if (set.find(c) != set.end()) {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c); // 三元组元素c去重，将匹配成功的c值从集合中删除，用于避免重复三元组。
                } else {
                    set.insert(nums[j]); // set.insert(nums[j]) 作用：将当前遍历到的数字nums[j]存入哈希集合，用于后续匹配三元组
                }
            }
        }
        return result;
    }

    // 双指针法：首先将数组排序,然后有—层for循环, i从下标0的地方开始,
    // 同时将一个下标left定义在i＋l的位置上,将下标right定义在数组结尾的位置上
    // 如果nums[i]＋nums[left]＋nums[right]＞0, 则说明此时三数之和大了,因为数组是排序后的数组,所以right下标就应该向左移动,这样才能让三数之和小—些。
    // 如果nums[i]＋nums[left]＋nums[right]＜0, 则说明此时三数之和小了,所以left向右移动,才能让三数之和大—些,直到left和right相遇。
    vector<vector<int>> threeSum2(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出 a+b+c=0, a= nums[i], b=nums[left], c=nums[right]
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) { // 若第一个元素已经大于0，那么不可能凑成三元组
                break;
            }
            // 错误去重方法，会漏掉[-1,-1,2]的情况
            /*
            if (nums[i] == nums[i-1]) {
                continue;
            }
            */
           // 正确去重方法
           if (i > 0 && nums[i] == nums[i-1]) {
               continue;
           }
           int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                // 若去重复逻辑放到这里，可能导致right<=left,从而漏掉了[0,0,0]
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (right > left && nums[right] == nums[right-1]) {
                        right--;
                    }
                    while (right > left && nums[left] == nums[left+1]) {
                        left++;
                    }
                    // 找到答案时，双指针同时收缩
                    left++;
                    right--;
                }
            }
        }
        return result;
    } // 时间复杂度为O(n^2), 空间复杂度为O(1)
};

int main() {
    vector<int> nums = {-1, 3, 4, -3, 0, -1, 3, -3};
    Solution solution;
    vector<vector<int>> result = solution.threeSum2(nums);
    for (auto item : result) {
        for (auto num : item) {
            cout << num << " ";
        }
        cout << endl;
    } // 输出结果：[-3 -1 4][-3 0 3]
    return 0;
}