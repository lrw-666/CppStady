/*计算两个整数a和b的和！
输入:输入数据有多组，每组为一行，包括两个整数a,b(-2**31<=a,b<=2**31-1)

输出:对每组输入，在单独的行中输出a+b的结果。

示例输入:
1 2
-1 1
示例输出:
3
0
*/

#include <iostream>

using namespace std;

int main() {
    // 考虑溢出可能
    long long a, b;
    // 当cin读取输入时，会自动忽略空格和回车符，因此可以直接使用>>来读取两个整数
    // 在C++中，cin是一个输入流对象（istream），当你使用cin >> a >> b进行输入时，它会返回cin本身。
    // istream 对象可以被隐式转换为 bool 类型(通过重载operator bool()或operator void*())，以判断输入操作是否成功。
    while( cin >> a >> b ) {
        // endl会输出一个换行符，使得输出结果在一行显示并且清空缓冲区
        cout << a + b << endl;
    }
    return 0;
}

// explicit 是C++中的一个关键字，用于修饰单参数的构造函数或转换函数，以防止隐式类型转换和复制初始化
/* 重载示例
class istream {
public:
    // 假设这是读取操作符的重载
    istream& operator>>(int& value) {
        // 读取操作
        // 如果读取失败，设置错误状态
        if (!read_value(value)) {
            setstate(failbit);
        }
        return *this;
    }

    // 重载 bool 操作符：在布尔上下文中（如 while 循环、if 语句等），编译器会自动调用 operator bool() 进行转换。
    explicit operator bool() const {
        return !fail() && !eof();
    }

    // 重载 void* 操作符：在指针上下文中（如 if (p) 等），编译器会自动调用 operator void*() 进行转换。
    explicit operator void*() const {
        return fail() || eof()? 0 : this;
    }

private:
    bool read_value(int& value) {
        // 实际的读取逻辑
        // 返回 true 或 false 表示读取成功或失败
        return true; // 或 false
    }

    void setstate(iostate state) {
        // 设置错误状态
    }

    bool fail() const {
        // 检查是否有失败状态
        return false; // 或 true
    }

    bool eof() const {
        // 检查是否到达文件末尾
        return false; // 或 true
    }
};
*/