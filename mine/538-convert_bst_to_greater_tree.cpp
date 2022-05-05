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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while(true){
            for(; p; p = p->right)  st.push(p);
            if(st.empty())  break;
            p = st.top(); st.pop();
            p->val += sum;
            sum = p->val;
            p = p->left;
        }
        return root;
    }
};

class Solution2 {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root){
            root->right = convertBST(root->right);
            root->val += sum;
            sum = root->val;
            root->left = convertBST(root->left);
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* p = root, *q;
        while(p){
            q = p->right;
            if(!q){
                //visit p
                p->val += sum;
                sum = p->val;
                p = p->left;
                continue;
            }
            for(; q->left && q->left != p; q = q->left);
            if(q->left == p){
                q->left = nullptr;
                //visit p
                p->val += sum;
                sum = p->val;
                p = p->left;
            }else{
                q->left = p;
                p = p->right;
            }
        }
        return root;
    }
};