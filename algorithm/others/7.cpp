/*计算两个32位整数A和B的和！

输入:输入数据有多组，每组为一行，包括两个32位整数。

输出:对每组输入，在单独的行中输出结果，每两组结果之间以单个空行分隔。

示例输入
1 5
10 20
示例输出
6

30
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    long long a, b;
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);
        ss >> a >> b;
        cout << a + b << endl;
        cout << endl;
    }

    return 0;
}