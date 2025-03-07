/*
力扣题号: 454四数相加II。
给出四个长度相同数组,找出有几种元组可以使A[i]+B[j]+C[k]+D[l]＝0。
[示例一]
输入:A＝［3,1,4],B＝［-2,4,3］,C＝［-1,3,2］,D＝［3,-2,0］
输出: 2
两种元组如下:
● A［0］＋B［0］＋C［0］＋D［2］＝3十(-2)＋(-1)＋0＝0。
● A［1］＋B［0］＋C［1］＋D［1］＝1＋(-2)＋3＋(-2)＝0。
*/
/*
本题解题步骤如下:
（1）定义—个unordered_map,key为a和b两数之和,value为a和b两数之和出现的次数
（2）遍历A、B数组，统计两个数组的元素之和及出现的次数,并放到map中
（3）定义int类型的变量count,用来统计a＋b＋c＋d=0出现的次数
（4）在遍历C、D数组时,如果0-(c＋d)在map中出现,就使用count统计map中key对应的value,
即两数之和出现的次数。
（5）返回统计值count
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> umap; // key: a+b, value: count
        // 遍历A、B数组，统计两个数组的元素之和及出现的次数,并放到map中
        for (int a : A) {
            for (int b : B) {
                umap[a + b]++;
            }
        }
        int count = 0;// 统计a+b+c+d=0出现的次数
        // 在遍历C、D数组时,如果0-(c+d)在map中出现,就使用count统计map中key对应的value,即两数之和出现的次数
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> A = { 3, 1, 4 };
    vector<int> B = { -2, 4, 3 };
    vector<int> C = { -1, 3, 2 };
    vector<int> D = { 3, -2, 0 };
    Solution solution;
    int count = solution.fourSumCount(A, B, C, D);
    cout << "count: " << count << endl; // 输出: 2
    return 0;
}