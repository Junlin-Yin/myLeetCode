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
        ListNode* dummy = new ListNode(0, head);
        map<int, ListNode*> m;
        int idx = 0;
        for(ListNode* p = dummy; p; p = p->next)
            m[idx++] = p;
        ListNode* prev = m[idx-n-1], *curr = m[idx-n];
        prev->next = curr->next;
        delete curr;
        return dummy->next; 
    }
};