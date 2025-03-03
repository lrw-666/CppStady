#include <iostream>
#include <csignal>
#include <unistd.h>
 
using namespace std;
 
/*
raise() 生成信号，该函数带有一个整数信号编号作为参数，语法如下：int raise (signal sig);
sig 是要发送的信号的编号，这些信号包括：SIGINT、SIGABRT、SIGFPE、SIGILL、SIGSEGV、SIGTERM、SIGHUP

Sleep 函数
功能：执行挂起一段时间，也就是等待一段时间在继续执行
用法：Sleep(时间)
注意：
 （1）Sleep 是区分大小写的，有的编译器是大写，有的是小写。
 （2）Sleep 括号里的时间，在 Windows 下是以毫秒为单位，而 Linux 是以秒为单位。
Linux 用 #include <unistd.h> 和 sleep()，Windows 用 #include <windows.h> 和 Sleep()。
*/

void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";
 
    // 清理并关闭
    // 终止程序 
 
   exit(signum);  
 
}
 
int main ()
{
    int i = 0;
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);  
 
    while(++i){
       cout << "Going to sleep...." << endl;
       if( i == 3 ){
          raise(SIGINT);
       }
       sleep(1);
    }
 
    return 0;
}