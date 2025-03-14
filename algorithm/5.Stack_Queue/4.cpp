/*
力扣题号: 150逆波兰表达式求值.
逆波兰表达式即后缀表达式.
[题目描述]
给出逆波兰表达式,求得对应的值.
[示例一]
输入: [＂5＂,＂2＂,＂-＂,＂4＂,＂＊＂］.
输出: 12.
解释:该算式转化为常见的中缀算术表达式为((5-2)×4)＝12.
*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                else if (tokens[i] == "-") st.push(num2 - num1);
                else if (tokens[i] == "*") st.push(num2 * num1);
                else if (tokens[i] == "/") st.push(num2 / num1);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        int result = st.top();
        st.pop(); // 把栈中的最后一个元素弹出
        return result;
    }
};

int main() {
    vector<string> tokens = {"5", "2", "-", "4", "*"};
    Solution s;
    cout << s.evalRPN(tokens) << endl;
    return 0;
}