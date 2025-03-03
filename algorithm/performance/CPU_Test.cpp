#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

// O(n)
void function1(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        k++;
    }
}
// O(n^2)
void function2(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            k++;
        }
    }
}
// O(nlogn)
void function3(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j < n; j = j * 2) {
            k++;
        }
    }
}

int main() {
    long long n; // 数据规模:100000000
    while(1){
        cout << "输入n:";
        cin >> n;
        // 记录程序开始时间，以毫秒为单位
        milliseconds start_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

        // function1(n); // 调用函数1，参数为n
        // function2(n); // 调用函数2，参数为n
        function3(n); // 调用实际执行的函数3，参数为n

        // 记录程序结束时间，以毫秒为单位
        milliseconds end_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

        // 计算并输出程序的执行时间（从开始到结束），以毫秒为单位
        cout << "耗时：" << (end_time.count() - start_time.count()) << "ms" << endl;
    }
}