/*
力扣题号: 225。用队列实现栈.
[题目描述]
使用队列(单向队列)实现栈
使用队列实现栈的下列操作:
· Pop():弹出栈顶元素.
· push(x):将x入栈.
· top():获取栈顶元素.
· empty():返回栈是否为空
[思路]:
两个队列实现：
模拟出栈的时候queue2的作用就呈备份把queue1中除队列中的最后一个元素外的所有元素都备份到queue2中,
即把元素1备份到queue2中。然后弹出最后的元素,再把元素1从queue2导回queue1

一个队列实现：
在模拟栈弹出元素的时候将队列头部的元素(除了最后一个元素)重新添加到队列尾部，此时再弹出元素的顺序就是栈的顺序
*/
#include <queue>
#include <iostream>

using namespace std;

// 两个队列实现
class MyStack {
public:
    queue<int> que1;
    queue<int> que2; // 辅助队列
    MyStack () {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int size = que1.size();
        size--;
        while (size--) { // 将queue1导入queue2,但要留下最后一个元素
            que2.push(que1.front());
            que1.pop();
        }
        
        int result = que1.front(); // 留下的最后一个元素就是要返回的值
        que1.pop();
        que1 = que2; // 再将queue2赋值给queue1
        while (!que2.empty()) { // 清空queue2
            que2.pop();
        }
        return result;
    }

    int top() {
        return que1.back();
    }

    bool empty() {
        return que1.empty();
    }
};

class MyStack2 {
public:
    queue<int> que;
    MyStack2 () {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;
        while (size--) { // 将队列头部的元素(除了最后一个元素)重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        
        int result = que.front(); // 此时弹出的元素的顺序就是栈的顺序
        que.pop();
        return result;
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }
};

int main() {
    MyStack2 s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.pop() << endl; // 5    
    cout << s.pop() << endl; // 4
    cout << s.pop() << endl; // 3
    cout << s.pop() << endl; // 2
    cout << s.pop() << endl; // 1
    return 0;
}