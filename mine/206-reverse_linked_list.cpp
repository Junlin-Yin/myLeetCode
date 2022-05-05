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
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p = nullptr, *q = head, *r;
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};

class Solution2 {
public:
    ListNode* recursiveBody(ListNode* head){
        if(!head->next)		return head;
        ListNode* tail = recursiveBody(head->next);
        head->next->next = head;
        return tail;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head)   return nullptr;
        ListNode* tail = recursiveBody(head);
        head->next = nullptr;
        return tail;
    }
};