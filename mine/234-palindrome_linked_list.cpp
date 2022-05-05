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
    bool isPalindrome(ListNode* head) {
        //find middle point
        ListNode *s = head, *f = head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        stack<int> st;
        for(ListNode *p = head; p != s; p = p->next)    st.push(p->val);
        if(f)   s = s->next;
        for(ListNode *p = s; p; p = p->next){
            if(p->val == st.top())  st.pop();
        }
        return st.empty();
    }
};

class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        //寻找中点
        ListNode dummy; dummy.next = head;
        ListNode *prevs = &dummy, *s = head, *f = head;
        while(f && f->next){
            prevs = prevs->next;
            s = s->next;
            f = f->next->next;
        }
        //反转后半段链表
        ListNode *p = prevs, *q = s, *r, *tail;
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        //东西对进
        q = head; tail = p;
        bool flag = true;
        while(true){
            if(p->val != q->val){
                flag = false; break;
            }
            if(p == q || p == s && q == prevs)  break;
            p = p->next;
            q = q->next;
        }
        //恢复原链表结构
        p = nullptr, q = tail;
        while(q != prevs){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return flag;
    }
};