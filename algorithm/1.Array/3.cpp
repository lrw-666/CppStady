/*
力扣题号: 27移除元素
［题目描述］
原地移除数组中所有等于val的元素,要求不能使用额外的辅助空间,即空间复杂度为O（1）。
返回移除元素后新数组的size。
［提示］
患考题目中为什么没有要求返回移除元素之后的数组呢7
因为数组中的元素无法真正移除,只能靠后一个元素覆盖前一个元素，返回移除后的数组没有
意义。
［示例］
数组为［4,5,6,4,4,4］.
移除的元素为4。
原地移除元素4之后的数组为［5,6］!数组长度为2。
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    // 暴力解法： 时间复杂度:O（n^2） 空间复杂度:O（1）
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(nums[i] == val) { // 发现需要移除的元素就将数组集合向前移动一位
                for(int j = i + 1; j < size; j++) {
                    nums[j-1] = nums[j]; // 向前移动一位
                }
                i--; // 因为向前移动了一位所以i需要减一
                size--; // 数组长度减一
            }
        }
        return size;
    }
    // 双指针法(快慢指针法):时间复杂度:O(n).空间复杂度:O(1)。
    int removeElement2(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main() {
    vector<int> nums = {4,5,6,4,4,4};
    int val = 4;
    Solution solution;
    int size = solution.removeElement2(nums, val);
    cout << "size: " << size << endl;
    for(int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}