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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head, *r = head;
        while(q && q->next){
            p = p->next;
            q = q->next->next;
            if(p == q){
                for(; p != r; p = p->next, r = r->next);
                return r;
            }
        }
        return nullptr;
    }
};