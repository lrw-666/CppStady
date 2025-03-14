/*
时间复杂度分析：
n为文本串长度，m为模式串长度，在匹配的过程中，根据前缀表不断调整匹配的位置。
可以看出匹配过程的事件复杂度为O(n)。之前还要单独生成next数组，时间复杂度为O(m)
所以整个KMP算法的时间复杂度为O(n+m)。
暴力解法的时间复杂度为O(n x m)。
*/
/*
力扣题号: 28实现strStr。
[题目描述]
在文本串s中查找是否出现过模式串，如果出现过则返回匹配的第一个位置，如果没出现过则返回-1
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // next数组为前缀表统一减一之后的实现
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) { // 注意i从1开始
            while(j >= 0 && s[i] != s[j+1]) { // 前后缀不相同
                j = next[j]; // 向前回退
            }
            if (s[i] == s[j+1]) { // 前后缀相同
                j++;
            }
            next[i] = j; // 将j(前缀的长度)赋值给next[i]
        }
    }
    // haystack为文本串，needle为模式串
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) { // 空串匹配任意字符串
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle); // 生成next数组
        int j = -1; // next数组中记录的起始位置为-1
        for(int i = 0; i < haystack.size(); i++) { // i从0开始
            while(j >= 0 && haystack[i] != needle[j+1]) { // 前后缀不相同
                j = next[j]; // j寻找之前的匹配位置
            }
            if (haystack[i] == needle[j+1]) { // 匹配，j和i同时向后移动
                j++; // i的增加逻辑在for循环中
            }
            if (j == needle.size() - 1) { // 文本串s中出现了模式串t
                return (i - needle.size() + 1); // 返回匹配的第一个位置
            }
        }
        return -1; // 没有匹配
    }

    // 前缀表(不减一)的代码实现:通过j=next[j-1]进行回退
    void getNext2(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) { // 注意i从1开始
            // j要保证大于0，因为下面有取j-1作为数组下标的操作
            while ( j > 0 && s[i] != s[j] ) { // 前后缀不相同
                j = next[j-1]; // 向前回退
            }
            if ( s[i] == s[j] ) { // 前后缀相同
                j++;
            }
            next[i] = j; // 将j(前缀的长度)赋值给next[i]
        }
    }
    int strStr2(string haystack, string needle) {
        if (needle.size() == 0) { // 空串匹配任意字符串
            return 0;
        }
        int next[needle.size()];
        getNext2(next, needle); // 生成next数组
        int j = 0; // next数组中记录的起始位置为0
        for(int i = 0; i < haystack.size(); i++) { // i从0开始
            while ( j > 0 && haystack[i] != needle[j] ) { // 前后缀不相同
                j = next[j-1]; // j寻找之前的匹配位置
            }
            if ( haystack[i] == needle[j] ) { // 匹配，j和i同时向后移动
                j++; // i的增加逻辑在for循环中
            }
            if (j == needle.size()) { // 文本串s中出现了模式串t
                return (i - needle.size() + 1); // 返回匹配的第一个位置
            }
        }
        return -1; // 没有匹配
    }
};

int main() {
    Solution s;
    string s1 = "hello world";
    string s2 = "wor";
    cout << s.strStr2(s1, s2) << endl;
    return 0;
}