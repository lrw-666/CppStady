/*
力扣题号: l42环形链表II.
［题目描述］
判断一个链表是否有环，如果有环，则找到入环的第一个节点,如果无环，则返回NULL

1、判断链表是否有环：可使用快慢指针法，分别定义fast和slow指针，
fast指针每次移动两步，slow指针每次移动一步，若相遇则有环

2、寻找环的入口：假设从头节点到环的入口节点的节点数为x，环的入口节点到fast指针与slow指针相遇节点的节点数为y,
从相遇节点再到环的入口节点的节点数为z。
当fast指针与slow诣针相遇时,slow指针移动的节点数为x+y, fast指针移动的节点数为x+y+n(y+z),
n的含义为fast指针在环内移动了n圈才遇到slow指针,y＋z为一圈内节点的个数
fast指针移动的节点数＝slow指针移动的节点数×2,即(x+y)×2＝x＋y＋n(y＋z)
两边消去一个(x+y),得到x+y=n(y+z); x表示头节点到环的入口节点的距离
即：x=(n-1)(y+z)+z,而(y+z)代表一圈内节点的个数
这就意味着，一个指针从头节点出发，另一个指针才能够相遇节点出发，让两个指针每次移动一个节点，则两个指针相遇的节点即环的入口节点

3.做法：再相遇节点处定义一个指针index1,在头节点处定一个指针index2，
让二者同时移动，每次移动一个节点，那么它们相遇处即为环的入口节点。
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
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next!= nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            // 快慢指针相遇，此时从head和相遇点同时查找直至相遇
            if (fast == slow) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return nullptr; // 无环
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next = head->next; // 形成环
    ListNode* res = s.detectCycle(head);
    if (res == nullptr) {
        cout << "无环" << endl;
    } else {
        cout << "环的入口节点值为" << res->val << endl;
    }
    return 0;
}