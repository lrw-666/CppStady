/*
［题目描述］
删除链表中倒数第n个节点（n从1开始）
［示例］
输入: l→2→3→4→5→6, n=2.
输出: 1→2→3→4→6。
［思路］
本题是双指针法的经典应用
如果要删除倒数第n个节点,则让fast移动n步,然后让fast和slow同时ying,当fast到达链表尾部时,删除slow所指向的节点即可
建议使用虚拟头节点，方便处理删除头节点的逻辑
*/

#include <iostream>

using namespace std;

// 定义链表节点的结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        // 让fast移动n步
        while(n-- && fast != nullptr) {
            fast = fast->next;
        }
        // fast再提前移动一步，因为需要让slow指向删除节点的上一个节点
        fast = fast->next;
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};

int main() {
    // 创建链表头节点，值为1
    ListNode* head = new ListNode(1);
    // 创建第二个节点，值为2，并将其连接到头节点
    head->next = new ListNode(2);
    // 创建第三个节点，值为3，并将其连接到第二个节点
    head->next->next = new ListNode(3);
    // 创建第四个节点，值为4，并将其连接到第三个节点
    head->next->next->next = new ListNode(4);
    // 创建第五个节点，值为5，并将其连接到第四个节点
    head->next->next->next->next = new ListNode(5);
    // 创建Solution类的实例，用于调用移除节点的方法
    Solution solution;
    // 调用removeNthFromEnd方法，移除链表倒数第2个节点，并返回新的头节点
    ListNode* newHead = solution.removeNthFromEnd(head, 2);
    // 遍历新的链表，输出每个节点的值
    while(newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    // 返回0，表示程序成功结束
    return 0;
}