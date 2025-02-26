#include <iostream>
#include <cmath>
using namespace std;
 
int main ()
{
   // 数字定义
   short  s = 10;
   int    i = -1000;
   long   l = 100000;
   float  f = 230.47;
   double d = 200.374;
 
   // 数学运算
   cout << "sin(d) :" << sin(d) << endl;
   cout << "abs(i)  :" << abs(i) << endl;
   cout << "floor(d) :" << floor(d) << endl;
   cout << "sqrt(f) :" << sqrt(f) << endl;
   cout << "pow( d, 2) :" << pow(d, 2) << endl;
   // std::cout << "pi: " << std::numbers::pi << std::endl;
   // std::cout << "e: " << std::numbers::e << std::endl;
   // std::cout << "phi: " << std::numbers::phi << std::endl; //C++20中数学常数（如 π、e、黄金比例等）
 
   return 0;
}