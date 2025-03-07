/*
力拍题号: 206反转链表.
［题目描述］
反转-个单链表。要求是不能申请额外的内存空间。
［示例］
输入: 1→2→3→4→5→6→NULL。
输出: 6→5→4→3→2→1→NULL
［思路］
如果定义—个新的链表实现链表元素的反转,则是对内存空间的浪费。其实只需要改变链表的
next指针的指向，直接将链表反转即可,而不用重新定义一个新的链表
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
    // 双指针法:初始化cu1＝head、pre＝NULL
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一节点
        ListNode* cur = head;
        ListNode* pre = nullptr; // 保存cur的上一节点
        while(cur) {
            // 保存cur的下一节点，因为接下来要改变cur->nest的指向
            temp = cur->next;
            cur->next = pre; // 反转操作
            // 更新prev和cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    // 递归法: 逻辑一致
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if(cur == nullptr) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码对比，如下递归写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur, temp);
    }
    ListNode* reverseList2(ListNode* head) {
        // 和双指针法初始化一样逻辑
        // ListNode* cur = head;
        // ListNode* prev = nullptr;
        return reverse(nullptr, head);
    }
};

int main() {
    // 创建一个 Solution 类的实例
    Solution s;
    // 初始化链表头节点，值为1
    ListNode* head = new ListNode(1);
    // 添加第二个节点，值为2
    head->next = new ListNode(2);
    // 添加第三个节点，值为3
    head->next->next = new ListNode(3);
    // 添加第四个节点，值为4
    head->next->next->next = new ListNode(4);
    // 添加第五个节点，值为5
    head->next->next->next->next = new ListNode(5);
    // 调用 Solution 类的 reverseList 方法反转链表，并获取新的头节点
    ListNode* newHead = s.reverseList2(head);
    // 遍历反转后的链表，输出每个节点的值
    while(newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    // 返回主函数
    return 0;
}