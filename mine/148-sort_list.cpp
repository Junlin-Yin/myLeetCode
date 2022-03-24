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
    ListNode* merge(ListNode* p, ListNode* q, ListNode* np){
        //...->p->...->q->...->np
        ListNode dummy, *d = &dummy, *l = p, *r = q;
        while(l != q && r != np){
            if(l->val < r->val){
                d->next = l;
                l = l->next;
            }else{
                d->next = r;
                r = r->next;
            }
            d = d->next;
        }
        if(l != q){
			//原来子链表p的后接节点要改成np，才能保证整条链表的通畅
            d->next = l;
            while(d->next != q) d = d->next;
            d->next = np;
        }else{
			//子链表q的后接节点本来就是np，不必如p那样做修改
            d->next = r;
        }
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        ListNode dummy, *p, *l, *r, *q;
        dummy.next = head;
        for(int len = 1; ; len <<= 1){
            p = &dummy;
            while(p){
                r = l = p->next;
                for(int i = 0; i < len && r; ++i, r = r->next);
                if(!r)  break;
                q = r;
                for(int i = 0; i < len && q; ++i, q = q->next);
                p->next = merge(l, r, q);
                while(p->next != q) p = p->next;
            }
            if(p == &dummy) break;
        }
        return dummy.next;
    }
};