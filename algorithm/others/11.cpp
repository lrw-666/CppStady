/*大学的生活花费太高了，一个学期下来，小果觉得自己的开销远超预期。有鉴于此，小果打算规划一下自己的开销，看看各个方面的总体收支情况，开展自己的财务规划。
小果打算从现在起试着请你帮她记账，经过尝试后，她希望你把最近几笔的收支情况纳入财务计划中。
输入格式
输入仅一行，为小果最近的财务收支。包括若干个整数，记每笔收支为a(−10000≤a≤10000)，负数表示消费，正数表示收入。收支不超过1000笔。

输出格式
输出最近所有交易的结余。

输入示例1
100 -50 200
输出示例1
250
输入示例2
-200 300
输出示例2
100
输入示例3
0
输出示例3
0
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int num, balance = 0;
    string input;

    while (getline(cin, input)) {
        stringstream ss(input);
        while (ss >> num) {
            balance += num;
        }
        cout << balance << endl;
        balance = 0;
    }

    return 0;
}