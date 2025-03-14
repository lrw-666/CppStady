/*
力扣题号: 20有效的括号。
[题目描述]
一个字符串只要有左括号"(" ,就要有")"来闭合, "{}" "}", "[" "]" 也同理.
字符串只包含以上字符,判断字符串是否合法·
[示例一]
输入: "(){}[]{[]}"
输出: true
技巧:在匹配左括号时，右括号先入栈，这时只需比较当前元素和栈顶元素是否匹配即可。
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // 第三张情况:在遍历字符串的过程中，栈已空，无匹配的字符,说明右括号没有找到对应的左括号，返回错误
            // 第二种情况:在遍历字符串过程中，发现栈里没有要匹配的字符，所以返回错误
            else if (st.empty() || s[i] != st.top()) return false;
            else st.pop(); // st.top() 与 s[i] 相等，栈弹出元素
        }
        // 第一种情况:此时已遍历完了字符串,但栈不为空，说明有相应的左括号没有右括号匹配，返回错误
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s = "(){}[]{[]}";
    cout << sol.isValid(s) << endl; // true
    return 0;
}