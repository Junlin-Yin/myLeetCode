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
class Solution1 {
public:
    TreeNode* last = nullptr;
    void flatten(TreeNode* root) {
        //last是preorder的逆顺序，从下到上
        if(!root)   return;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = nullptr;
        last = root;
    }
};

class Solution2 {
public:
    void flatten(TreeNode* root) {
        TreeNode* p = root, *q, *r;
        while(p){
            if(p->left){
                r = q = p->left;
                while(q->right) q = q->right;
                q->right = p->right;
                p->right = r;
                p->left = nullptr;
            }
            p = p->right;
        }
    }
};