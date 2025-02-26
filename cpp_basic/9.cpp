#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

/* C++数据结构 */

int main() {
    /* 数组 */
    int arr[5] = {1, 2, 3, 4, 5};
    cout << arr[0]; // 输出第一个元素

    /* 结构体 */
    // struct Person {
    //     string name;
    //     int age;
    // };
    // Person p = {"Alice", 25};
    // cout << p.name << endl; // 输出 Alice

    /* 类 */
    class Person {
        private:
            string name;
            int age;
        public:
            Person(string n, int a) : name(n), age(a) {}
            void printInfo() {
                cout << "Name: " << name << ", Age: " << age << endl;
            }
    };
    Person p("Bob", 30);
    p.printInfo(); // 输出: Name: Bob, Age: 30

    /* 链表 */
    struct Node {
        int data;
        Node* next;
    };
    Node* head = nullptr;
    Node* newNode = new Node{10, nullptr};
    head = newNode; // 插入新节点

    /* 栈 */
    stack<int> s;
    s.push(1);
    s.push(2);
    cout << s.top(); // 输出 2
    s.pop();

    /* 队列 */
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.front(); // 输出 1
    q.pop();

    /* 双端队列 */
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    cout << dq.front(); // 输出 2
    dq.pop_front();

    /* 哈希表 */
    unordered_map<string, int> hashTable;
    hashTable["apple"] = 10;
    cout << hashTable["apple"]; // 输出 10

    /* 映射Map */
    map<string, int> myMap;
    myMap["apple"] = 10;
    cout << myMap["apple"]; // 输出10

    /* 集合Set */
    set<int> a;
    a.insert(1);
    a.insert(2);
    cout << *a.begin(); // 输出 1
    return 0;
}