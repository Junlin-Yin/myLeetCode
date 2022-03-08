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
    ListNode* merge2Lists(ListNode* a, ListNode* b){
        ListNode dummy, *p = &dummy;
        while(a && b){
            if(a->val < b->val){
                p->next = a;
                p = a;
                a = a->next;
            }else{
                p->next = b;
                p = b;
                b = b->next;
            }
        }
        p->next = a ? a : b;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size(), g;
        while(k > 1){
            for(g = 0; g < ((k + 1) >> 1); ++g){
                int last_i = (g << 1) + 1;
                lists[g] = merge2Lists(lists[g << 1], last_i == k ? nullptr : lists[last_i]);
            }
            k = g;
        }
        return k ? lists[0] : nullptr;
    }
};