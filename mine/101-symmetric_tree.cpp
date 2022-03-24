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
    bool recursiveBody(TreeNode* L, TreeNode* R){
        if(!L && !R)    return true;
        if(!L || !R)    return false;
        return L->val == R->val && recursiveBody(L->left, R->right) && recursiveBody(L->right, R->left);
    }

    bool isSymmetric(TreeNode* root) {
		//递归解法
        return recursiveBody(root->left, root->right);
    }

	bool isSymmetric(TreeNode* root) {
		//迭代解法preorder vs. reverse_preorder
        TreeNode* p = root->left, *q = root->right;
        stack<TreeNode*> sp, sq;
        bool flag = true;
        while(true){
            for(; p && q; p = p->left, q = q->right){
                if(p->val != q->val)    { flag = false; break; }
                sp.push(p); sq.push(q);
            }
            if(p || q)  flag = false;
            if(!flag || sp.empty() && sq.empty())   break;
            p = sp.top(); sp.pop(); p = p->right;
            q = sq.top(); sq.pop(); q = q->left;
        }
        return flag;
    }
};