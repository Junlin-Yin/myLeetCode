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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1, *p2=l2, *p;
        ListNode* l3=nullptr, *prev=nullptr, *next=nullptr;
        int c = 0;
        while(p1!=nullptr && p2!=nullptr){
            int val = p1->val + p2->val + c;
            c = val / 10;
            val %= 10;
            next = new ListNode(val);
            if(!l3){
                l3 = prev = next;
            }else{
                prev->next = next;
            }
            p1 = p1->next;
            p2 = p2->next;
            prev = next;
        }
        p = (p1 == nullptr) ? p2 : p1;
        while(p!=nullptr){
            int val = p->val + c;
            c = val / 10;
            val %= 10;
            next = new ListNode(val);
            p = p->next;
            prev->next = next;
            prev = next;         
        }
        if(c > 0){
            next = new ListNode(c);
            prev->next = next;
        }
        return l3;
    }
};