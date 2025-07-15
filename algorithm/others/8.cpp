/*若干32位整数求和。

输入:输入数据的第一行为一个整数T，表示有T组测试数据。随后的T行中，每行第第一个数为一个整数N，随后有N个整数。

输出:对每组输入，在单独的行中输出结果，每两组结果之间以单个空行分隔。

示例输入
3
4 1 2 3 4
5 1 2 3 4 5
3 1 2 3
示例输出
10

15

6
*/
#include <iostream>

using namespace std;

int main() {
    int T, N;
    long long sum = 0, num;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> num;
            sum += num;
        }
        cout << sum << endl;
        if (i < T - 1) {
            cout << endl;
        }
        sum = 0;
    }

    return 0;
}