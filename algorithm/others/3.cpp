/*计算两个32位整数A和B的和！

输入:输入数据有多组，每组为一行，包括两个32位整数。若两个整数均为0，表示输入结束。

输出:对每组输入，在单独的行中输出结果。

示例输入
1 2
-1 1
0 0
示例输出
3
0
*/
#include <iostream>

using namespace std;

int main() {
    long long a, b;

    while(1){
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        cout << a + b << endl;  
    }
    return 0;
}