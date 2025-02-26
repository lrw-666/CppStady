#include <iostream>
#include <ctime>
 
using namespace std;
 
int main( )
{
    /* 获取当前系统的日期和时间，包括本地时间和协调世界时（UTC) */

   // 基于当前系统的当前日期/时间
   time_t now = time(0);
   
   // 把 now 转换为字符串形式
   char* dt = ctime(&now);
 
   cout << "本地日期和时间：" << dt << endl;
 
   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC 日期和时间："<< dt << endl;
}