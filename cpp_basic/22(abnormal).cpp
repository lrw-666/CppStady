#include <iostream>
using namespace std;
 
/*
异常提供了一种转移程序控制权的方式。C++ 异常处理涉及到三个关键字：try、catch、throw。
throw: 当问题出现时，程序会抛出一个异常。这是通过使用 throw 关键字来完成的。
catch: 在您想要处理问题的地方，通过异常处理程序捕获异常。catch 关键字用于捕获异常。
try: try 块中的代码标识将被激活的特定异常。它后面通常跟着一个或多个 catch 块。
*/

double division(int a, int b)
{
    if( b == 0 )
    {
        throw "Division by zero condition!";
    }
    return (a/b);
}

// 通过继承和重载 exception 类来定义新的异常
struct MyException : public exception
{
  const char * what () const throw ()
  {
    return "C++ Exception";
  }
};
 
 
int main ()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    }catch (const char* msg) {
        cerr << msg << endl;
    }// Division by zero condition!

    try // 自定义异常
    {
        throw MyException();
    }
    catch(MyException& e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch(std::exception& e)
    {
        //其他的错误
    }
    // MyException caught
    // C++ Exception
    return 0;
}

/*
C++ 提供了一系列标准的异常，定义在 <exception> 中，我们可以在程序中使用这些标准的异常。它们是以父子类层次结构组织起来的，如下所示：
异常	            描述
std::exception	    该异常是所有标准 C++ 异常的父类。
std::bad_alloc	    该异常可以通过 new 抛出。
std::bad_cast	    该异常可以通过 dynamic_cast 抛出。
std::bad_typeid	    该异常可以通过 typeid 抛出。
std::bad_exception	这在处理 C++ 程序中无法预期的异常时非常有用。
std::logic_error	理论上可以通过读取代码来检测到的异常。
    std::domain_error	当使用了一个无效的数学域时，会抛出该异常。
    std::invalid_argument	当使用了无效的参数时，会抛出该异常。
    std::length_error	当创建了太长的 std::string 时，会抛出该异常。
    std::out_of_range	该异常可以通过方法抛出，例如 std::vector 和 std::bitset<>::operator[]()。
std::runtime_error	理论上不可以通过读取代码来检测到的异常。
    std::overflow_error	当发生数学上溢时，会抛出该异常。
    std::range_error	当尝试存储超出范围的值时，会抛出该异常。
    std::underflow_error	当发生数学下溢时，会抛出该异常。

const throw() 不是函数，这个东西叫异常规格说明，表示 what 函数可以抛出异常的类型，
类型说明放到 () 里，这里面没有类型，就是声明这个函数不抛出异常，通常函数不写后面的 throw() 就表示函数可以抛出任何类型的异常。
异常规格说明

1、异常规格说明的目的是为了让函数使用者知道该函数可能抛出的异常有哪些。 可以在函数的声明中列出这个函数可能抛掷的所有异常类型。例如：
void fun() throw(A，B，C，D);
2、若无异常接口声明，则此函数可以抛掷任何类型的异常。
3、不抛掷任何类型异常的函数声明如下：
#include 
#include 
using namespace std;

class MyException
{
public:
    MyException(const char *message)
        : message_(message)
    {
        cout << "MyException ..." << endl;
    }
    MyException(const MyException &other) : message_(other.message_)
    {
        cout << "Copy MyException ..." << endl;
    }
    virtual ~MyException()
    {
        cout << "~MyException ..." << endl;
    }

    const char *what() const
    {
        return message_.c_str();
    }
private:
    string message_;
};

class MyExceptionD : public MyException
{
public:
    MyExceptionD(const char *message)
        : MyException(message)
    {
        cout << "MyExceptionD ..." << endl;
    }
    MyExceptionD(const MyExceptionD &other)
        : MyException(other)
    {
        cout << "Copy MyExceptionD ..." << endl;
    }
    ~MyExceptionD()
    {
        cout << "~MyExceptionD ..." << endl;
    }
};

void fun(int n) throw (int, MyException, MyExceptionD)
{
    if (n == 1)
    {
        throw 1;
    }
    else if (n == 2)
    {
        throw MyException("test Exception");
    }
    else if (n == 3)
    {
        throw MyExceptionD("test ExceptionD");
    }

}

void fun2() throw()
{

}

int main(void)
{
    try
    {
        fun(2);
    }

    catch (int n)
    {
        cout << "catch int ..." << endl;
        cout << "n=" << n << endl;
    }
    catch (MyExceptionD &e)
    {
        cout << "catch MyExceptionD ..." << endl;
        cout << e.what() << endl;
    }
    catch (MyException &e)
    {
        cout << "catch MyException ..." << endl;
        cout << e.what() << endl;
    }

    return 0;
}

*/