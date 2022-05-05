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
    TreeNode* invertTree(TreeNode* root) {
		//递归
        if(root){
            TreeNode* tmp = invertTree(root->left);
            root->left = invertTree(root->right);
            root->right = tmp;            
        }
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
		//迭代
        stack<TreeNode*> st;
        TreeNode* p = root, *tmp;
        while(true){
            for(; p; p = p->left)   st.push(p);
            if(st.empty())  break;
            p = st.top(); st.pop();
            tmp = p->left;
            p->left = p->right;
            p->right = tmp;
            p = p->left;
        }
        return root;
    }
};