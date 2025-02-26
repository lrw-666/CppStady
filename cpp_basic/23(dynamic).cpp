#include <iostream>
using namespace std;
 
class Box
{
   public:
      Box() { 
         cout << "调用构造函数！" <<endl; 
      }
      ~Box() { 
         cout << "调用析构函数！" <<endl; 
      }
};
 

int main ()
{
    // 示例1
    double* pvalue  = NULL; // 初始化为 null 的指针
    pvalue  = new double;   // 为变量请求内存
    *pvalue = 29494.99;     // 在分配的地址存储值
    cout << "Value of pvalue : " << *pvalue << endl;
    delete pvalue;         // 释放内存

    // 示例2：一维数组
    int m=5, n=3;
    // 动态分配,数组长度为 m
    int *array=new int [m];
    //释放内存
    delete [] array;

    // 示例3：二维数组
    // 动态分配,数组长度为 m*n
    int **array2;
    // 假定数组第一维长度为 m， 第二维长度为 n
    // 动态分配空间
    array2 = new int *[m];
    for( int i=0; i<m; i++ )
    {
        array2[i] = new int [n];
    }
    //释放
    for( int i=0; i<m; i++ )
    {
        delete [] array2[i];
    }
    delete [] array2;

    // 示例4：对象的动态内存分配
    Box* myBoxArray = new Box[4];
    delete [] myBoxArray; // 删除数组

    return 0;
}
/*
如果自由存储区已被用完，可能无法成功分配内存。所以建议检查 new 运算符是否返回 NULL 指针，并采取以下适当的操作：
double* pvalue  = NULL;
if( !(pvalue  = new double ))
{
   cout << "Error: out of memory." <<endl;
   exit(1);
 
}

总结，如果ptr代表一个用new申请的内存返回的内存空间地址，即所谓的指针，那么：
    delete ptr -- 代表用来释放内存，且只用来释放ptr指向的内存。
    delete[] rg -- 用来释放rg指向的内存，！！还逐一调用数组中每个对象的 destructor！！
对于像 int/char/long/int* /struct 等等简单数据类型，由于对象没有 destructor，所以用 delete 和 delete [] 是一样的！
但是如果是C++ 对象数组就不同了:仅释放了a指针指向的全部内存空间 但是只调用了a[0]对象的析构函数 
剩下的从a[1]到a[9]这9个用户自行分配的m_cBuffer对应内存空间将不能释放 从而造成内存泄漏

new 和 malloc 内部的实现方式有什么区别？
new 的功能是在堆区新建一个对象，并返回该对象的指针。
    所谓的【新建对象】的意思就是，将调用该类的构造函数，因为如果不构造的话，就不能称之为一个对象。
而 malloc 只是机械的分配一块内存，如果用 mallco 在堆区创建一个对象的话，是不会调用构造函数的。
    严格说来用 malloc 不能算是新建了一个对象，只能说是分配了一块与该类对象匹配的内存而已，然后强行把它解释为【这是一个对象】，按这个逻辑来，也不存在构造函数什么事。
同样的，用 delete 去释放一个堆区的对象，会调用该对象的析构函数。
用 free 去释放一个堆区的对象，不会调用该对象的析构函数。
*/