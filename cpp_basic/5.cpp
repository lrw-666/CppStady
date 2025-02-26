#include <iostream>
#include <string>
 
using namespace std;
 
int main ()
{
   string str1 = "runoob";
   string str2 = "google";
   string str3;
   int  len ;
 
   // 复制 str1 到 str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;
 
   // 连接 str1 和 str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;
 
   // 连接后，str3 的总长度
   len = str3.size();
   cout << "str3.size() :  " << len << endl;

   /* 指针 */
   int  var = 20;   // 实际变量的声明
   int  *ip;        // 指针变量的声明
 
   ip = &var;       // 在指针变量中存储 var 的地址
 
   cout << "Value of var variable: ";
   cout << var << endl;
 
   // 输出在指针变量中存储的地址
   cout << "Address stored in ip variable: ";
   cout << ip << endl;
 
   // 访问指针中地址的值
   cout << "Value of *ip variable: ";
   cout << *ip << endl;

   /***
    * 特性	            引用	指针
    定义与初始化	    必须初始化，且不能为 null。	可以不初始化，可以在后续代码中指向其他对象，可以为 null。
    语法	            使用 & 声明，例如：int &ref = a;	使用 * 声明，例如：int *ptr = &a;
    重新绑定	        不能重新绑定，一旦初始化后始终引用同一个对象。	可以重新指向其他对象，例如：ptr = &b;
    空值（Nullability）	不能为 null，必须绑定到有效的对象。	可以为 null，表示不指向任何对象。
    内存占用	        不占用额外内存（编译器通常将其优化为直接操作所引用的对象）。	占用额外内存（存储地址，通常是一个机器字长，如4字节或8字节）。
    访问方式	        直接使用，无需解引用操作符，例如：ref = 10;	需要使用 * 解引用操作符访问或修改所指向的对象，例如：*ptr = 10;
    多级间接访问	    不支持多级间接访问（不能有引用的引用）。	支持多级间接访问（如指针的指针：int **pptr;）。
    函数参数传递	    常用于函数参数传递，语法简洁，例如：void func(int &x) { x = 10; }	也可以用于函数参数传递，但需要使用解引用操作符，例如：void func(int *x) { *x = 10; }
    数组与引用	        不能直接创建引用数组，但可以创建数组的引用，例如：int (&ref)[10] = arr;	可以创建指针数组，也可以创建指向数组的指针，例如：int *ptrArr[10];
    安全性	            更安全，不能为 null，且语法更直观。	更灵活，但容易出错（如空指针、野指针等）。
    底层实现	        通常通过指针实现，但编译器会优化为直接操作所引用的对象。	直接存储目标对象的内存地址。
    */
    // 声明简单的变量
   int    i;
   double d;
 
   // 声明引用变量
   int&    r = i;
   double& s = d;
   
   i = 5;
   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;
 
   d = 11.7;
   cout << "Value of d : " << d << endl;
   cout << "Value of d reference : " << s  << endl;
   
   return 0;
}