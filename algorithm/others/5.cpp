/*若干32位整数求和。

输入:输入数据的第一行为一个整数T，表示有T组测试数据，每组为一行。随后T行中，每行第一个数为一个整数N，随后有N个32位整数。

输出:对每组输入，在单独的行中输出结果。

示例输入
3
5 1 2 3 4 5
2 -1 1
1 0
示例输出
15
0
0
*/
#include <iostream>

using namespace std;

int main() {
    int T, N;
    long long num, sum = 0;

    if ( (cin >> T) && (T >= 1) ) {
        while( T-- ) {
            cin >> N;
            for(int i = 0; i < N; i++) {
                cin >> num;
                sum += num;
            }
            cout << sum << endl;
            sum = 0;
        }
    }

    return 0;
}