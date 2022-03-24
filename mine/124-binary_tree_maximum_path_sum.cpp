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
    unordered_map<TreeNode*, int>   maxRPS;

    int calcMaxRootPathSum(TreeNode* root) {
        if(!root)   return 0;
        int val = root->val + max(0, max(calcMaxRootPathSum(root->left), calcMaxRootPathSum(root->right)));
        maxRPS[root] = val;
        return val;
    }

    int calcMaxPathSum(TreeNode* root) {
        int val;
        if(!root->left && !root->right)
            val = root->val;
        else{
            val = root->val + max(maxRPS[root->left], 0) + max(maxRPS[root->right], 0);
            if(root->left)  val = max(val, calcMaxPathSum(root->left));
            if(root->right) val = max(val, calcMaxPathSum(root->right));
        }
        return val;
    }

    int maxPathSum(TreeNode* root) {
        maxRPS[nullptr] = 0;
        calcMaxRootPathSum(root);
        return calcMaxPathSum(root);
    }
};