/*计算两个32位整数A和B的和！

输入:输入数据的第一行为一个整数T，表示有T组数据。随后的T行中，每行有两个整数A和B。

输出
对每组输入，在单独的行中输出结果。

示例输入
2
1 2
-1 1
示例输出
3
0
*/
#include <iostream>
using namespace std;

int main() {
    int T, i;
    long long a, b;
    cin >> T;

    for (i = 0; i < T; i++) {
         cin >> a >> b;
         cout << a + b << endl;
    }
    return 0;
}