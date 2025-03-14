/*
力扣题号: 151.反转字符串里的单词.
给定一句英文,要求倒叙输出每一个单词,并删除单词两边冗余的空格(句子前面和后面没有空格,两个单词之间没有空格)。
注意:不可以使用额外的辅助空间,即原地修改字符串
[示例一]
输入: "I am a programmer "
输出: "programmer a am I"

[思路]
1.用split库函数分隔单词，定义一个string字符串把单词倒序相加(无意义，有辅助空间)
2.将整个字符串都反转过来,那么单词的顺序指定是倒序的了，只不过单词本身也倒叙了,再把单词反转一下,单词就"正"过来了
解题思路如下:
(l)删除多余空格.
(2)将整个字符串反转。
(3)将每个单同反转。
注；erase函数可用于删除字符串中指定位置的字符或一定范围内的字符。本身为时间复杂度为O(n),而数组中的元素星不能删除的,只能覆盖，因此不适合用于此处(O(n^2)复杂度)
使用双指针法删除空格,最后重新设置(resize)字符串的大小,就可以实现O(n)的时间复杂度
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 反转整个字符串(反转字符串S中左闭右开的区间[start, end])
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // 使用双指针删除冗余空格
    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0; // 定义快慢指针
        // 去掉字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] ==' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            // 去掉字符串中间部分的冗余空格
            if (fastIndex - 1 > 0
                && s[fastIndex - 1] == s[fastIndex]
                && s[fastIndex] == ' ') {
                    continue;
                } else {
                    s[slowIndex++] = s[fastIndex];
                }
        }
        // 去掉字符串末尾的空格
        if (slowIndex - 1 > 0 && s[slowIndex - 1] ==' ') {
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // 重新设置字符串大小
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); // 删除冗余空格
        reverse(s, 0, s.size() - 1); // 反转整个字符串
        int start = 0, end = 0; // 定义起始、终止指针
        bool entry = false; // 标记枚举字符串的过程中是否已经进入单词区间
        for (int i = 0; i < s.size(); i++) { // 开始反转单词
            if ((!entry) || (s[i] != ' ' && s[i - 1] == ' ')) {
                start = i; // 记录单词起始位置
                entry = true; // 进入单词区间
            }
            // 单词后面有空格的情况，空格就是分词符
            if (entry && (s[i] == ' ' && s[i - 1] != ' ')) {
                end = i - 1; // 记录单词终止位置
                entry = false; // 退出单词区间
                reverse(s, start, end); // 反转单词
            }
            // 最后一个结尾单词后面没有空格
            if (entry && i == s.size() - 1 && s[i] != ' ') {
                end = i; // 记录单词终止位置
                entry = false; // 退出单词区间
                reverse(s, start, end); // 反转单词
            }
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s = "I am a programmer ";
    cout << solution.reverseWords(s) << endl;
    return 0;
}