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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> v;
        if(!root)   return v;
        q.push({root, 0});
        int level = -1;
        while(!q.empty()){
            TreeNode* p = q.front().first;
            int curr_level = q.front().second;
            q.pop();
            if(!p)  continue;
            if(level != curr_level){
                ++level;
                v.push_back(vector<int>());
            }
            v[level].push_back(p->val);
            q.push({p->left,  level + 1});
            q.push({p->right, level + 1});
        }
        return v;
    }
};