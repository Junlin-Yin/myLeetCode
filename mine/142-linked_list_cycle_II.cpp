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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head){
            s.insert(head);
            if(s.find(head->next) != s.end()){
                return head->next;
            }
            head = head->next;
        }
        return head;
    }
};