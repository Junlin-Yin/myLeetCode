/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p = root, *q;
        while(true){
            for(; p; p = p->left){
                q = p;
                s.push(p);
            }
            if(s.empty())   break;
            p = s.top(); s.pop();
            q->left = p->right;
            p->right = nullptr;
            p = q->left;
        }
        p = root;
        while(p){
            p->right = p->left;
            p->left = nullptr;
            p = p->right;
        }
    }
};