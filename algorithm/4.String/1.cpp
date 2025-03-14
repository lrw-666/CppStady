/* C++字符串基础
在C语言中,把一个字符串存入一个数组时,也把结束符'\0'存入了数组,并以此作为该字符串是否结束的标志。
char a[5] = "asd";
for (int i = 0; a[i]!= '\0'; i++) {
}
在C++中,提供了一个string类,string类会提供size接口,可以用来判断string类的字符串是否结束，不用'\0'判断字符串是否结束
string a = "asd";
for (int i = 0; i < a.size(); i++) {
}
vector＜char＞和string区别：
在基本操作上没有区别,但string提供了更多的字符串处理的相关接口。例如string重载了"+",而vector却没有
*/
/*
力扣题号; 344反转字符串
[题目描述]
将一个字符串反转.
[示例一]
输入: ["a","s","d","f","g"]
输出: ["g","f","d","s","a"］
[思路]
对于字符串，我们定义两个指针(也可以说是索引下标),一个从字符串前面,另一个从字符串后面,两个指针同时向中间移动并交换元素
*/
#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
        swap(s[i], s[j]);
    }
}// 库函数reverse函数可直接实现功能

int main() {
    vector<char> s = {'a','s','d','f','g'};
    reverseString(s);
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
/*
swap库函数可有两种实现方式，一为常见的交换数值
int tmp = s[i];
s[i] = s[j];
s[j] = tmp;
另一种方式为位运算
s[i] ^= s[j];
s[j] ^= s[i];
s[i] ^= s[j];
*/