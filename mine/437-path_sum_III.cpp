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

    int ans = 0;

    int pathRootSum(TreeNode* root, long long targetSum) {
        int ret = 0;
        if(root){
            if(root->val == targetSum)  ++ret;
            ret += pathRootSum(root->left, targetSum - root->val);
            ret += pathRootSum(root->right, targetSum - root->val);
        }
        return ret;
    }

    void dfs(TreeNode* root, long long targetSum) {
        if(root){
            ans += pathRootSum(root, targetSum);
            dfs(root->left, targetSum);
            dfs(root->right, targetSum);
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};