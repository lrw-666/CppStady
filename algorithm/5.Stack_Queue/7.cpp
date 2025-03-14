/*
力扣题号: 42接雨水.
给出一排宽度为1、高度为n的柱子,求可以接到雨水的面积
[示例一]
输入: height＝[1,0,2,1,3,1,0,1,2,0,1]
输出: 7
*/
/*双指针解法:每一列雨水的高度取决于该列左侧最高的柱子和右侧最高的柱子之间的最矮柱子的高度
只要从头遍历一遍所有的列,然后求出每一列雨水的面积,相加之后就是总雨水的体积
当前位置的雨水面积: [min(左边柱子的最高高度,右边柱子的最高高度)-当前柱子高度]×单位宽度
这里的单位宽度是1;每到一个柱子都向两边遍历一遍,这其实是有重复计算的
*/
/*动态规划解法:
我们将每个位置的左边最高高度记录在一个数组中(maxLeft),将右边最高高度记录在另一个数组中(maxRight),
避免了重复计算,这时就用到了动态规划。当前位置的左边最高高度是前一个位置的左边最高高度和本高度比较后的最大值
· 从左向右遍历:maxLeft[i]＝max(height[i],maxLeft[i-l]).
· 从石向左遍历:maxRight[j]＝max(height[j],maxRight[i+1］).
*/
/*单调栈解法:单调栈即保持栈内元素有序
1、单调栈按照行方向计算雨水面积，从栈头到栈底的元素应该是从小到大;一旦发现添加的柱子高度大于栈头元素,说明出现凹槽
2、遇到相同高度柱子:更新元素,将栈内元素(旧下标)弹出,将新元素(新下标)加入栈
3、栈内保存数值:int类型下标,通过height[stack.top()]即可知道弹出的下标对应的高度
处理逻辑：
1、将下标0的柱子加入栈:st.push(0);
2、从下标1开始遍历,若当前元素高度小于栈顶元素高度，入栈(保持栈头到栈尾从小到大)
3.若当前元素高度等于栈顶元素高度，更新栈顶元素(使用最右边柱子计算)
4、若当前元素高度大于栈顶元素高度，出现凹槽
    1)弹出栈顶元素，即凹槽底部高度下标(中间位置),下标记为mid
    2)此时的栈顶元素为凹槽左边柱子，下标为st.top()
    3)当前遍历的元素就是凹槽右边的柱子，下标为i
    4)雨水高度h即min(凹槽左边高度，凹槽右边高度)-凹槽底部高度
    5)雨水宽度2即凹槽右边下标-凹槽左边下标-1
    6)当前凹槽雨水面积=雨水高度h*雨水宽度w
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // 双指针解法:时间复杂度O(n^2),空间复杂度O(1)
    int trap(vector<int>& height) {
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            // 第一个柱子和最后一个柱子不接雨水
            if (i == 0 || i == height.size() - 1) continue;

            int rHeight = height[i]; // 右侧柱子高度
            int lHeight = height[i]; // 左侧柱子高度
            for (int r = i + 1; r < height.size(); r++) {
                if (height[r] > rHeight) rHeight = height[r];
            }
            for (int l = i - 1; l >= 0; l--) {
                if (height[l] > lHeight) lHeight = height[l];
            }
            int h = min(rHeight, lHeight) - height[i];
            if (h > 0) sum += h;
        }
        return sum;
    }

    // 动态规划解法
    int trap2(vector<int>& height) {
        if (height.size() <= 2) return 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int size = maxRight.size();

        // 记录每个柱子左边柱子的最大高度
        maxLeft[0] = height[0];
        for (int i = 1; i < size; i++){
            maxLeft[i] = max(height[i], maxLeft[i-1]);
        }
        // 记录每个柱子右边柱子的最大高度
        maxRight[size-1] = height[size-1];
        for (int i = size-2; i >= 0; i--){
            maxRight[i] = max(height[i], maxRight[i+1]);
        }
        // 求和
        int sum = 0;
        for (int i = 0; i < size; i++){
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0) sum += count;
        }
        return sum;
    }

    // 单调栈解法
    int trap3(vector<int>& height) {
        if (height.size() <= 2) return 0;
        stack<int> st;// 存放下标,计算时使用下标对应柱子高度
        st.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++){
            if (height[i] < height[st.top()]) {    //情况一
                st.push(i);
            } else if (height[i] == height[st.top()]) {    //情况二可不加,效果一样，思路不同
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && height[i] > height[st.top()]) {    //情况三
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {    //凹槽左边柱子
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1; // 注意减一，只求中间宽度
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
    // 单调栈精简写法
    int trap4(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();
                st.pop();
                if (!st.empty()) {
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1;
                    sum += h * w;
                }
            }
            st.push(i);
        }
        return sum;
    }
};

int main() {
    vector<int> height = {1, 0, 2, 1, 3, 1, 0, 1, 2, 0, 1};
    Solution sol;
    cout << sol.trap(height) << endl;
    return 0;
}