/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode dummy; dummy.next = headB;
        ListNode *p = &dummy, *q = &dummy, *r, *tailA;
        for(tailA = headA; tailA->next; tailA = tailA->next);
        tailA->next = headA;
        bool cycle = false;
        while(q && q->next){
            p = p->next;
            q = q->next->next;
            if(p == q){
                cycle = true;    break;
            }
        }
        if(cycle)  for(r = &dummy; r != p; r = r->next, p = p->next);
        else       r = nullptr;
        tailA->next = nullptr;
        return r;
    }
};