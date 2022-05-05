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

    //每个不同的前缀和对应了几个祖先节点
    unordered_map<long long, int> prefix;

    int dfs(TreeNode* root, long long curr, int targetSum) {
        int ret = 0;
        if(root){
            curr += root->val;
            if(prefix.count(curr - targetSum))  ret += prefix[curr - targetSum];

            ++prefix[curr];
            ret += dfs(root->left, curr, targetSum);
            ret += dfs(root->right, curr, targetSum);
            --prefix[curr];      
        }
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;   //这一句保证根节点可以成为起点
        return dfs(root, 0, targetSum);
    }
};