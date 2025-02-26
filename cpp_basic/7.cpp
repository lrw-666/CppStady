/**
 * 结构体的各个部分详细介绍
    * struct 关键字：用于定义结构体，它告诉编译器后面要定义的是一个自定义类型。
    * 成员变量：成员变量是结构体中定义的数据项，它们可以是任何基本类型或其他自定义类型。在 struct 中，这些成员默认是 public，可以直接访问。
    * 成员函数：结构体中也可以包含成员函数，这使得结构体在功能上类似于类。成员函数可以操作结构体的成员变量，提供对数据的封装和操作。
    * 访问权限：与 class 类似，你可以在 struct 中使用 public、private 和 protected 来定义成员的访问权限。在 struct 中，默认所有成员都是 public，而 class 中默认是 private。
 *
    * 结构体与类的区别
    * 在 C++ 中，struct 和 class 本质上非常相似，唯一的区别在于默认的访问权限：
    * struct 默认的成员和继承是 public。
    * class 默认的成员和继承是 private。
    * 你可以将 struct 当作一种简化形式的 class，适合用于没有太多复杂功能的简单数据封装。
    */
#include <iostream>
#include <string>
 
using namespace std;
 
// 声明一个结构体类型 Books 
struct Books
{
    string title;
    string author;
    string subject;
    int book_id;
 
    // 构造函数
    Books(string t, string a, string s, int id)
        : title(t), author(a), subject(s), book_id(id) {}
};
 
// 打印书籍信息的函数
void printBookInfo(const Books& book) {
    cout << "书籍标题: " << book.title << endl;
    cout << "书籍作者: " << book.author << endl;
    cout << "书籍类目: " << book.subject << endl;
    cout << "书籍 ID: " << book.book_id << endl;
}
 
int main()
{
    // 创建两本书的对象
    Books Book1("C++ 教程", "Runoob", "编程语言", 12345);
    Books Book2("CSS 教程", "Runoob", "前端技术", 12346);
 
    // 输出书籍信息
    printBookInfo(Book1);
    printBookInfo(Book2);
 
    return 0;
}