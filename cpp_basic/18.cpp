#include <iostream>
using namespace std;
 
class Adder{
   public:
      // 构造函数
      Adder(int i = 0)
      {
        total = i;
      }
      // 对外的接口
      void addNum(int number)
      {
          total += number;
      }
      // 对外的接口
      int getTotal()
      {
          return total;
      };
   private:
      // 对外隐藏的数据
      int total;
};
int main( )
{
   Adder a;
   
   a.addNum(10);
   a.addNum(20);
   a.addNum(30);
 
   cout << "Total " << a.getTotal() <<endl;
   return 0;
}

/*
访问标签强制抽象
在 C++ 中，我们使用访问标签来定义类的抽象接口。一个类可以包含零个或多个访问标签：
    使用公共标签定义的成员都可以访问该程序的所有部分。一个类型的数据抽象视图是由它的公共成员来定义的。
    使用私有标签定义的成员无法访问到使用类的代码。私有部分对使用类型的代码隐藏了实现细节。
访问标签出现的频率没有限制。每个访问标签指定了紧随其后的成员定义的访问级别。
指定的访问级别会一直有效，直到遇到下一个访问标签或者遇到类主体的关闭右括号为止。

数据抽象的好处
数据抽象有两个重要的优势：
    类的内部受到保护，不会因无意的用户级错误导致对象状态受损。
    类实现可能随着时间的推移而发生变化，以便应对不断变化的需求，或者应对那些要求不改变用户级代码的错误报告。
如果只在类的私有部分定义数据成员，编写该类的作者就可以随意更改数据。
如果实现发生改变，则只需要检查类的代码，看看这个改变会导致哪些影响。
如果数据是公有的，则任何直接访问旧表示形式的数据成员的函数都可能受到影响。

设计策略
抽象把代码分离为接口和实现。所以在设计组件时，必须保持接口独立于实现，这样，如果改变底层实现，接口也将保持不变。
在这种情况下，不管任何程序使用接口，接口都不会受到影响，只需要将最新的实现重新编译即可。
*/