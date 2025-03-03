#include <iostream>
#include <thread>

void printMessage(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "Hello from thread (function pointer)!\n";
    }
}
// 使用函数对象:通过类中的 operator() 方法定义函数对象来创建线程：
class PrintTask {
public:
    void operator()(int count) const {
        for (int i = 0; i < count; ++i) {
            std::cout << "Hello from thread (function object)!\n";
        }
    }
};

int main() {
    // std::thread t1(printMessage, 5); // 创建线程，传递函数指针和参数
    // t1.join(); // 等待线程完成

    // std::thread t2(PrintTask(), 5); // 创建线程，传递函数对象和参数
    // t2.join(); // 等待线程完成
     return 0;
}

/*
一般情况下，两种类型的多任务处理：基于进程和基于线程。
    基于进程的多任务处理是程序的并发执行。
    基于线程的多任务处理是同一程序的片段的并发执行。

如果需要传递引用参数，需要使用 std::ref() 函数。

C++11 及以后的标准提供了多线程支持，核心组件包括：
std::thread：用于创建和管理线程。
std::mutex：用于线程之间的互斥，防止多个线程同时访问共享资源。
std::lock_guard 和 std::unique_lock：用于管理锁的获取和释放。
std::condition_variable：用于线程间的条件变量，协调线程间的等待和通知。
std::future 和 std::promise：用于实现线程间的值传递和任务同步。
*/