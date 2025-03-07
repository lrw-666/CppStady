#include <iostream>
using namespace std;

struct node{
    int num;
    char cha;
}st;

// 验证内存对齐：输出结果与单存计算字节数存在误差(内存中块的大小)
int main()
{
    int a[100];
    char b[100];
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(st) << endl;
}