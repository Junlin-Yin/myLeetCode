/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //只需跟踪prev就能简单通过prev->next索引到待删节点
        //增加哨兵节点可以避免计算链表总长度，可降低空间复杂度，但时间复杂度不变
        ListNode *prev = dummy, *sent = head;
        for(int i=0; i<n; ++i)  sent = sent->next;
        while(sent){
            sent = sent->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        delete prev->next;
        return dummy->next;
    }
};