#include <iostream>
using namespace std;
 
// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
   // 第二个命名空间
   namespace second_space{
      void func(){
         cout << "Inside second_space" << endl;
      }
   }
}
using namespace first_space::second_space;
int main ()
{
 
   // 调用第二个命名空间中的函数
   func(); // Inside second_space

   
   return 0;
}

/*
命名空间的定义使用关键字 namespace，后跟命名空间的名称
使用 using namespace 指令，这样在使用命名空间时就可以不用在前面加上命名空间的名称。
    这个指令会告诉编译器，后续的代码将使用指定的命名空间中的名称

不连续的命名空间：
    命名空间可以定义在几个不同的部分中，因此命名空间是由几个单独定义的部分组成的。一个命名空间的各个组成部分可以分散在多个文件中。
    所以，如果命名空间中的某个组成部分需要请求定义在另一个文件中的名称，则仍然需要声明该名称

嵌套的命名空间：
    命名空间可以嵌套，您可以在一个命名空间中定义另一个命名空间
*/