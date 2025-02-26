#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // 构造函数
    Student(string studentName, int studentAge) {
        name = studentName;
        age = studentAge;
    }

    // 访问器函数（getter）
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    // 修改器函数（setter）
    void setName(string studentName) {
        name = studentName;
    }

    void setAge(int studentAge) {
        if (studentAge > 0) {
            age = studentAge;
        } else {
            cout << "Invalid age!" << endl;
        }
    }

    // 打印学生信息
    void printInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // 创建一个 Student 对象
    Student student1("Alice", 20);

    // 访问和修改数据
    student1.printInfo();

    student1.setName("Bob");
    student1.setAge(22);

    student1.printInfo();

    return 0;
}
/*
所有的 C++ 程序都有以下两个基本要素：
    程序语句（代码）：这是程序中执行动作的部分，它们被称为函数。
    程序数据：数据是程序的信息，会受到程序函数的影响。
封装是面向对象编程中的把数据和操作数据的函数绑定在一起的一个概念，这样能避免受到外界的干扰和误用，从而确保了安全。
数据封装引申出了另一个重要的 OOP 概念，即数据隐藏。
数据封装是一种把数据和操作数据的函数捆绑在一起的机制，数据抽象是一种仅向用户暴露接口而把具体的实现细节隐藏起来的机制。
C++ 通过创建类来支持封装和数据隐藏（public、protected、private）。
我们已经知道，类包含私有成员（private）、保护成员（protected）和公有成员（public）成员。默认情况下，在类中定义的所有项目都是私有的。

设计策略
通常情况下，我们都会设置类成员状态为私有（private），除非我们真的需要将其暴露，这样才能保证良好的封装性。
这通常应用于数据成员，但它同样适用于所有成员，包括虚函数。

数据封装的优点
数据隐藏: 通过将数据成员声明为私有，防止外部代码直接访问这些数据。
提高代码可维护性: 提供公共方法来访问和修改数据，这使得可以在不影响外部代码的情况下修改类的内部实现。
增强安全性: 防止不合法的数据输入和不当的修改操作。
实现抽象: 提供了一种机制，使得用户不需要了解类的内部实现细节，只需要了解如何使用类的公共接口即可。

补充：
C++中, 虚函数可以为private, 并且可以被子类覆盖（因为虚函数表的传递），但子类不能调用父类的private虚函数。
虚函数的重载性和它声明的权限无关。
一个成员函数被定义为private属性，标志着其只能被当前类的其他成员函数(或友元函数)所访问。
而virtual修饰符则强调父类的成员函数可以在子类中被重写，因为重写之时并没有与父类发生任何的调用关系，故而重写是被允许的。
编译器不检查虚函数的各类属性。被virtual修饰的成员函数，不论他们是private、protect或是public的，都会被统一的放置到虚函数表中。
对父类进行派生时，子类会继承到拥有相同偏移地址的虚函数表（相同偏移地址指，各虚函数相对于VPTR指针的偏移），则子类就会被允许对这些虚函数进行重载。
且重载时可以给重载函数定义新的属性，例如public，其只标志着该重载函数在该子类中的访问属性为public，和父类的private属性没有任何关系！
纯虚函数可以设计成私有的，不过这样不允许在本类之外的非友元函数中直接调用它，子类中只有覆盖这种纯虚函数的义务，却没有调用它的权利。
*/