/*
力相题号: 459重复的子字符串.
[题目描述]
给出一个非空字符串,判断是否有重复子字符串。
[示例一]
输入: "abcabc".
输出: True。
[思路]：KMP算法
next数组记录的就是最长相等前后缀的长度,如果next[len-l]!≡-1,则说明字符串有相同的前后缀
最长相等前后缀的长度为next[len-1]+1,数组长度为len
如果len%(len-(next[len-1]+1))==0,则说明(数组长度-最长相等前后缀的长度)正好可以被数组的长度整除，该字符串有重复的子字符串
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 使用前缀表统一减一的实现方式
    void getNext (int* next, const string& s) {
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j+1]) {
                j = next[j];
            }
            if(s[i] == s[j+1]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len-1] != -1 && len % (len - (next[len-1]+1)) == 0) {
            return true;
        }
        return false;
    }

    // 直接使用前缀表构造next数组
    void getNext2 (int* next, const string& s) {
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j-1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern2(string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext2(next, s);
        int len = s.size();
        if (next[len-1] != 0 && len % (len - next[len-1]) == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    string str = "abcabc";
    bool res = s.repeatedSubstringPattern2(str);
    cout << res << endl;
    return 0;
}