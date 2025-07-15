/*大学的生活花费太高了，一个学期下来，小果觉得自己的开销远超预期。有鉴于此，小果打算规划一下自己的开销，看看各个方面的总体收支情况，开展自己的财务规划。
小果打算从现在起试着请你帮她记账，经过尝试后，她希望你把最近几笔的收支情况纳入财务计划中。
小果对你帮忙财务记账非常开心，但在一次偶然翻看账本过程中，她发现你的记录中存在错误，不是数值；此外，她记得所有的消费和收入都应该在[−10000,10000]之间，否则也是错误的记录。
她希望你把错误的部分单独计数，并分别核算正确收支的情况。

输入格式
输入有若干行，为你帮助小果记录的财务收支，已知收支不超过1000笔。
每行为一个笔收支记录，可能是正确或错误的记录，长度不超过20个英文字母或数字。令正确收支记录为a(−10000≤a≤10000)，为一个整数，负数表示消费，正数表示收入。
错误记录可能为非整数值或超出范围的整数值。

输出格式:输出4行。第一行为正常收支记录的余额，第二行为错误记录的数量，第三行为消费的总额（请注意消费以负数表示），第四行为收入的总额。

输入示例1
100
-50
200
abc
12345
输出示例1
250
2
-50
300
输入示例2
-200
300
xyz
0
输出示例2
100
1
-200
300
输入示例3
0
10000
-10000
invalid
输出示例3
0
1
-10000
10000
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int num;
    int balance = 0, error_count = 0, total_consumption = 0, total_income = 0;
    string line;
    
    while (getline(cin, line)) {
        stringstream ss(line);
        if ( (ss >> num) && (num >= -10000 && num <= 10000) ) {
            if (num < 0) {
                total_consumption += num;
            } else {
                total_income += num;
            }
            balance += num;
        } else {
            error_count++;
        }
    }
    cout << balance << endl;
    cout << error_count << endl;
    cout << total_consumption << endl;
    cout << total_income << endl;
    return 0;
}