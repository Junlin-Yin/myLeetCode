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
    ListNode* cutList(ListNode* p, int N) {
        for(int i = 1; i < N && p; ++i) p = p->next;
        //now p is the N-th node
        if(!p)  return nullptr;
        ListNode* q = p->next;
        //q is the N+1-th node
        p->next = nullptr;
        return q;
    }

    ListNode* mergeList(ListNode* h1, ListNode* h2) {
        ListNode dummy, *d = &dummy;
        while(h1 && h2){
            if(h1->val > h2->val){
                d->next = h2;
                h2 = h2->next;
            }else{
                d->next = h1;
                h1 = h1->next;
            }
            d = d->next;
        }
        d->next = h1 ? h1 : h2;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        int len;
        ListNode dummy, *prev, *curr, *h1, *h2;
        bool done = false;
        dummy.next = head;
        if(!head)   return nullptr;
        for(len = 1; ; len <<= 1){
            prev = &dummy;  curr = prev->next;
            while(curr){
                h1 = curr;
                h2 = cutList(curr, len);
                done = (h1 == dummy.next && !h2);
                curr = h2;
                curr = cutList(curr, len);
                prev->next = mergeList(h1, h2);
                while(prev->next)   prev = prev->next;
            }
            if(done)    break;
        }
        return dummy.next;
    }
};