/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
		//快慢指针，试图套圈
        ListNode *p = head, *q = head;
        while(q && q->next){
            p = p->next;
            q = q->next->next;
            if(p == q)  return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        bool flag = false;
        while(head){
            s.insert(head);
            if(s.find(head->next) != s.end()){
                flag = true; break;
            }
            head = head->next;
        }
        return flag;
    }
};