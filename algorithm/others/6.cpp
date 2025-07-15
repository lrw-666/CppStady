/*若干32位整数求和。

输入:输入数据有多组，每组为一行，包括若干个32位整数。若行首的数值为0，表示输入结束。

输出:对每组输入，在单独的行中输出结果。

示例输入
1 2 3 4 5
-1 1
0
示例输出
15
0
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    int num;
    long long sum = 0;
    
    // 从输入流中读取一行，并存入字符串变量line中。
    while (getline(cin, line)) {
        // 如果输入流结束，则退出循环。
        if (line[0] == '0') {
            break;
        }

        // stringstream对象用于从字符串中读取数据，默认以空格分隔。
        stringstream ss(line);
        while (ss >> num) {
            sum += num;
        }
        cout << sum << endl;
        sum = 0;
    }

    return 0;
}