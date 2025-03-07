/*
力拍题号: 59螺旋矩阵Ⅱ。
［题目描述]给出一个正整数n,按从外向内的螺旋顺序打印1到n^2的所有数值.
［示例]
输入: 3.
输出:
[
    ［ 1, 2, 3 ］,
    ［ 8, 9, 4 ］,
    ［ 7, 6, 5 ］
]
[思路]
这道题目在面试中出现的频率较高,本题并不涉及算法,就是模拟螺旋顺序打印的过程,但十分考宣面试者对代码的掌控能力
循环不变量：矩阵的四条边都要坚持一致的左闭右开或者左开石闭的原则，这样才能按照统一的规则“画”下来
顺时针画矩阵过程：从左到右填充上行，从上到下填充右列，从右到左填充下行，从下到上填充左列，直到填满整个矩阵。
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // res 是一个 n x n 的矩阵，所有元素都被初始化为 0
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0; // 定义每循环一圈的起始位置
        int loop = n / 2;   // 每个圈循环几次；如n=3，则仅循环一圈
        int mid = n / 2;    // 矩阵中间的位置；如n=3，则中间位置为(1,1)
        int count = 1;      // 用来给矩阵中每一个空格赋值
        int offset = 1;     // 每一圈都需要控制每一条边遍历的长度
        int i, j;
        while (loop --) {
            i = startx;
            j = starty;
            
            // 下面开始的4个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (j = starty; j < starty + n - offset; j++) {
                res[startx][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i< startx + n - offset; i++) {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }
            // 第二圈开始的时候，起始位置要各自加1：如第一圈起始位置为(0,0),第二圈起始位置为(1,1)
            startx++;
            starty++;
            // offset用于控制每一圈中每一条边遍历的长度
            offset += 2;
        }
        // 如果n为奇数，则需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};

int main() {
    Solution s;
    int n = 3;
    vector<vector<int>> res = s.generateMatrix(n);
    for (int i = 0; i < n; i++) {    // 打印矩阵
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}