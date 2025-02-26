#include <iostream>

using namespace std;

/**
 * 多继承与虚继承
 * 多继承(环状继承),A->D, B->D, C->(A，B)，会使D创建两个对象,要解决上面问题就要用虚拟继承格式
 * 格式：class 类名: virtual 继承方式 父类名
 * 虚继承确保即使在多继承的情况下，D 的实例也只会出现一次
 * 在创建 C 类的对象时，构造函数的调用顺序为 D -> B -> A -> C，这是因为虚继承的 D 类首先被构造，然后是它的两个派生类 B 和 A，最后才是 C。
 * 在销毁 C 类的对象时，析构函数的调用顺序为 ~C -> ~A -> ~B -> ~D。析构函数的调用顺序与构造函数的调用顺序相反。
 * 1、与类同名的函数是构造函数。
 * 2、~ 类名的是类的析构函数：用于清理对象在使用过程中动态分配的资源，以及执行其他清理操作
 */
//基类
class D
{
public:
    D(){cout<<"D()"<<endl;}
    ~D(){cout<<"~D()"<<endl;}
protected:
    int d;
};

class B:virtual public D
{
public:
    B(){cout<<"B()"<<endl;}
    ~B(){cout<<"~B()"<<endl;}
protected:
    int b;
};

class A:virtual public D
{
public:
    A(){cout<<"A()"<<endl;}
    ~A(){cout<<"~A()"<<endl;}
protected:
    int a;
};

class C:public B, public A
{
public:
    C(){cout<<"C()"<<endl;}
    ~C(){cout<<"~C()"<<endl;}
protected:
    int c;
};

int main()
{
    cout << "Hello World!" << endl;
    C c;   //D, B, A ,C
    cout<<sizeof(c)<<endl;
    return 0;
}//当 main 函数执行完成后，局部变量 c（类型为 C）的生命周期结束，因此会自动调用其析构函数。