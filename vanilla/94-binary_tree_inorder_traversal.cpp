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
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> s;
        while(true){
            for(; root; root = root->left)  s.push(root);
            if(s.empty())   break;
            root = s.top(); s.pop();
            ans.emplace_back(root->val);
            root = root->right;
        }
        return ans;
    }
};