/*
力扣题号: 541.反转字符串II
[题目描述]
分段反转字符串,在字符串中,从前向后遍历,每隔2k个字符的前k个字符需要反转,如果剩
下的字符小于k个,则反转剩下的所有字符,如果剩下的字符小于2k人且大于或等于k个,则反转前k个字符
[示例一]
输入: s＝"asdfghjkl",k=3。
输出: "dsafghlkj"
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2 * k) {
            //1. 每隔2k个字符的前k个字符需要反转
            //2. 剩余字符小于2k但大于或等于k个，则反转前k个字符
            if (i + k <= s.length()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                //3. 剩余字符小于k个，则反转所有剩余字符
                reverse(s.begin() + i, s.begin( + s.length());
            }
        }
        return s;
    }
};

int main() {
    string s = "asdfghjkl";
    int k = 3;
    Solution sol;
    string res = sol.reverseStr(s, k);
    cout << res << endl;
    return 0;
}