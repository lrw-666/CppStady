/*
1、栈(先进后出)使用底层容器完成其所有的工作，对外提供统一的接口，底层容器可插拔(vector,deque,list...)
2、栈不提供走访功能，也不提供迭代器(iterator)，因此不归类为容器，而被归类为container adapter(容器适配器)
3、常用的SGI STL,默认以deque(双向队列)为栈底层结构，可指定其他底层结构如下：
std::stack<int, std::vector<int>> s; //使用vector作为栈底层结构
4、队列(先进先出)同样不允许遍历，不提供迭代器，可指定底层容器,也归类为container adapter
std::queue<int, std::list<int>> q; //使用list作为队列底层结构
*/
/*
力扣题号: 232用栈实现队列。
[题目描述]
使用两个栈实现队列的功能:
· pop():弹出队头元素.
· peek():获取队头元素.
· push():从队尾添加元素.
· empty():队列是否为空.
[思路]：一个输出栈、一个输入栈
pop()和peek()两个函数功能类似，可复用
*/
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {
        
    }
    void push(int x) {
        stIn.push(x);
    }
    int pop() {
        // 只有当stOut为空时，才从stIn中导入全部数据
        if (stOut.empty()) {
            // 从stIn中导入数据直到stIn为空
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }
    // 获取队列头部元素
    int peek() {
        int res = this->pop(); // 复用pop函数
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl; // 1
    cout << q.peek() << endl; // 2
    cout << q.pop() << endl; // 2
    cout << q.pop() << endl; // 3
    cout << q.empty() << endl; // 1
    return 0;
}