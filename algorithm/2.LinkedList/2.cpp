/*
力扣题号; 707设计链表.
［题目描述］
设计一个链表类,实现六个接口:
· 获取链表的第index个节点的数值。
· 在链表的最前面插入一个节点。
· 在链表的最后面插入一个节点。
· 在链表的第index个节点前面插入一个节点。
· 删除链表的第index个节点。
· 打印当前链表.
注意; index是从0开始的,第0个节点就是头节点
*/
#include <iostream>

using namespace std;

class MyLinkedList {
public:
    // 定义链表节点的结构体
    struct ListedNode {
        int val;
        ListedNode* next;
        ListedNode(int val) : val(val), next(nullptr) {}
    };

    // 初始化链表
    MyLinkedList() {
        // 这里定影的头节点是一个虚拟头节点，而不是真正的链表头节点
        _dummyHead = new ListedNode(0);
        _size = 0;
    }

    // 获取第indexgetNode的数值，如果index是非法数值则直接返回-1
    // 主要index是从0开始的，第0个节点就是头节点
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        ListedNode* cur = _dummyHead->next;
        while(index--) { // 如果写成"--index"则会出现死循环
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表的最前面插入一个节点，插入完成后，新插入的节点为链表新的头节点
    void addAtHead(int val) {
        ListedNode* newNode = new ListedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 在链表的最后面插入一个节点
    void addAtTail(int val) {
        ListedNode* newNode = new ListedNode(val);
        ListedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在链表的第index个节点前面插入一个节点
    // 如果index等于0，则说明新插入的节点为链表的头节点
    // 如果index等于链表的长度，则说明新插入的节点为链表的尾节点
    // 如果index大于链表的长度，则返回空
    void addAtIndex(int index, int val) {
        if (index > _size) {
            return;
        }
        ListedNode* newNode = new ListedNode(val);
        ListedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除链表的第index个节点，如果index大于或等于链表的长度，则直接返回
    // 注意index是从0开始的
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        ListedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        ListedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    // 打印当前链表
    void printLinkedList() {
        ListedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    ListedNode* _dummyHead;
};

int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);   // 1
    myLinkedList.addAtHead(2);   // 2 1
    myLinkedList.addAtHead(3);   // 3 2 1
    myLinkedList.addAtIndex(1, 4); // 3 4 2 1
    myLinkedList.addAtTail(5);    // 3 4 2 1 5
    myLinkedList.deleteAtIndex(1); // 3 2 1 5
    myLinkedList.printLinkedList(); // 3 2 1 5
    cout << myLinkedList.get(2) << endl; // 1
    return 0;
}