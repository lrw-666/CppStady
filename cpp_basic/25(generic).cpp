#include <iostream>
#include <string>
 
using namespace std;

/*C++ 模板
模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。
模板是创建泛型类或函数的蓝图或公式。库容器，比如迭代器和算法，都是泛型编程的例子，它们都使用了模板的概念。
每个容器都有一个单一的定义，比如 向量，我们可以定义许多不同类型的向量，比如 vector <int> 或 vector <string>。

泛型函数模板:
template <typename type> ret-type func-name(parameter list)
{
   // 函数的主体
}

代码说明：
template 是 C++ 中用于定义模板的关键字。它告诉编译器接下来的代码是一个模板。
    <typename T> 是模板参数列表。typename 表示后面的 T 是一个类型占位符（也可以用 class 关键字代替 typename，两者在模板中功能相同）
    T 是一个占位符，表示在调用函数时，T 会被替换为实际的类型（如 int、double、string 等）
    T const& 表示函数接受两个常量引用类型的参数，并返回一个常量引用类型的值
    inline 关键字建议编译器将函数内联展开，以提高性能
*/

// 定义一个函数模板，用于求两个数的最大值
template <typename T> 
inline T const& Max (T const& a, T const& b) //这是函数模板的定义。T 是模板参数，表示函数的参数和返回值类型
{ 
    return a < b ? b:a; 
} 
int main ()
{
 
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl; 
 
    double f1 = 13.5; 
    double f2 = 20.7; 
    cout << "Max(f1, f2): " << Max(f1, f2) << endl; 
 
    string s1 = "Hello"; 
    string s2 = "World"; 
    cout << "Max(s1, s2): " << Max(s1, s2) << endl; 
 
    return 0;
}