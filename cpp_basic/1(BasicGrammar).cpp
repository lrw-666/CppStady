#include <iostream>
 
class Base {
public:
    virtual ~Base() = default; // 基类必须具有虚函数
};
 
class Derived : public Base {
public:
    void show() {
        std::cout << "Derived class method" << std::endl;
    }
};
 
int main() {
    int i = 10;
    float f = static_cast<float>(i); // 静态将int类型转换为float类型
    float g = reinterpret_cast<float&>(i); // 重新解释将int类型转换为float类型
    Base* ptr_base = new Derived; // 基类指针指向派生类对象
 
    // 将基类指针转换为派生类指针
    Derived* ptr_derived = dynamic_cast<Derived*>(ptr_base);
 
    if (ptr_derived) {
        ptr_derived->show(); // 成功转换，调用派生类方法
    } else {
        std::cout << "Dynamic cast failed!" << std::endl;
    }
 
    delete ptr_base;
    return 0;
}

// int main() {
    const int i = 10;
    int& r = const_cast<int&>(i); // 常量转换，将const int转换为int
//     Derived derived_obj;
//     Base& ref_base = derived_obj; // 基类引用绑定到派生类对象

//     try {
//         // 将基类引用转换为派生类引用
//         Derived& ref_derived = dynamic_cast<Derived&>(ref_base);
//         ref_derived.show(); // 成功转换，调用派生类方法
//     } catch (const std::bad_cast& e) {
//         std::cout << "Dynamic cast failed: " << e.what() << std::endl;
//     }

//     return 0;
// }