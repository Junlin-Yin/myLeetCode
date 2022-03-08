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
    struct HeapNode{
        ListNode *curr;
        bool operator<(const HeapNode& other) const {return this->curr->val > other.curr->val;};
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<HeapNode> heap;  //学会使用C++ STL内置的优先队列
        ListNode dummy, *p = &dummy;
        for(auto node: lists){
            if(node)    heap.push({node});
        }
        while(!heap.empty()){
            p->next = heap.top().curr; heap.pop();
            p = p->next;
            if(p->next) heap.push({p->next});
        }
        return dummy.next;
    }
};