#include <iostream>
using namespace std;
 
/**虚函数特点：
 * 在基类中可以有实现。通常虚函数在基类中提供默认实现，但子类可以选择重写。
 * 动态绑定：在运行时根据对象的实际类型调用相应的函数版本。
 * 可选重写：派生类可以选择性地重写虚函数，但不是必须。
 * 
 * 纯虚函数特点：
 * 必须在基类中声明为 = 0，表示没有实现，子类必须重写。
 * 抽象类：包含纯虚函数的类不能直接实例化，必须通过派生类实现所有纯虚函数才能创建对象。
 * 接口定义：纯虚函数通常用于定义接口，让派生类实现具体行为
 * 
 * 虚函数与纯虚函数的对比
 * 特性	    虚函数（Virtual Function）	   纯虚函数（Pure Virtual Function）
 * 定义	    基类中使用 virtual 声明，有实现	基类中使用 = 0 声明，无实现
 * 子类重写	子类可以选择重写	            子类必须实现
 * 抽象性	可以实例化类	               使类变为抽象类，无法实例化
 * 用途	    提供默认行为，允许子类重写      定义接口，强制子类实现具体行为
 */
class Animal {
public:
    virtual void sound() {  // 虚函数
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {  // 重写虚函数
        cout << "Dog barks" << endl;
    }
};

class Shape {
public:
    virtual int area() = 0;  // 纯虚函数，强制子类实现此方法
};
 
class Rectangle : public Shape {
private:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) { }
    
    int area() override {  // 实现纯虚函数
        return width * height;
    }
};
 
int main() {
    // 虚函数
    Animal *animal = new Dog();
    animal->sound();  // 输出: Dog barks
    delete animal;

    // 纯虚函数
    Shape *shape = new Rectangle(10, 5);
    cout << "Rectangle Area: " << shape->area() << endl;  // 输出: Rectangle Area: 50
    delete shape;
}

/*
1、纯虚函数声明如下： virtual void funtion1()=0; 纯虚函数一定没有定义，纯虚函数用来规范派生类的行为，即接口。包含纯虚函数的类是抽象类，抽象类不能定义实例，但可以声明指向实现该抽象类的具体类的指针或引用。

2、虚函数声明如下：virtual ReturnType FunctionName(Parameter) 虚函数必须实现，如果不实现，编译器将报错，错误提示为：

error LNK****: unresolved external symbol "public: virtual void __thiscall ClassName::virtualFunctionName(void)"
3、对于虚函数来说，父类和子类都有各自的版本。由多态方式调用的时候动态绑定。

4、实现了纯虚函数的子类，该纯虚函数在子类中就变成了虚函数，子类的子类即孙子类可以覆盖该虚函数，由多态方式调用的时候动态绑定。

5、虚函数是C++中用于实现多态(polymorphism)的机制。核心理念就是通过基类访问派生类定义的函数。

6、在有动态分配堆上内存的时候，析构函数必须是虚函数，但没有必要是纯虚的。

7、友元不是成员函数，只有成员函数才可以是虚拟的，因此友元不能是虚拟函数。但可以通过让友元函数调用虚拟成员函数来解决友元的虚拟问题。

8、析构函数应当是虚函数，将调用相应对象类型的析构函数，因此，如果指针指向的是子类对象，将调用子类的析构函数，然后自动调用基类的析构函数。
*/