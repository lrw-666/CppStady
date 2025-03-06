/*
力扣题号: 203移除链表元素.
［题目描述］
在链表中删除指定的元素.
［示例］
输入: [1→4→2→4], va1=4.
输出: [1→2].
*/
#include <iostream>

using namespace std;

struct ListNode {
    int val; // 节点上存储的元素
    ListNode *next; // 指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {} // 节点的构造函数
};

class Solution {
public:
    // 无虚拟头节点做法
    ListNode* removeElements(ListNode* head, int val) {
        // 删除头节点
        while (head != NULL && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头节点
        ListNode* cur = head;
        while (cur != NULL && cur->next!= NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
    return head;
    }

    // 虚拟头节点做法
    ListNode* removeElements2(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头节点
        dummyHead->next = head; // 将虚拟头节点指向head，方便后面执行删除操作
        ListNode* cur = dummyHead; // 指向虚拟头节点
        while (cur->next != NULL) {
            if (cur->next ->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next; // 真正的头节点
        delete dummyHead; // C++需要手动清理内存
        return head;
    }
};

int main() {
    // 创建链表的头节点，值为1
    ListNode* head = new ListNode(1);
    // 设置头节点的下一个节点，值为4
    head->next = new ListNode(4);
    // 设置下一个节点的下一个节点，值为2
    head->next->next = new ListNode(2);
    // 设置下一个节点的下一个节点的下一个节点，值为4
    head->next->next->next = new ListNode(4);
    // 创建Solution类的实例
    Solution solution;
    // 调用removeElements2方法移除链表中值为4的节点，并获取新的头节点
    ListNode* newHead = solution.removeElements2(head, 4);
    // 遍历新的链表，输出每个节点的值
    while (newHead!= NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    // 返回0，表示程序成功结束
    return 0;
}