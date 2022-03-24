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
    bool recursiveBody(TreeNode* root, long long min, long long max) {
        if(!root)   return true;
        bool flag = root->val > min && root->val < max;
        if(root->left)
            flag = flag && root->val > root->left->val && recursiveBody(root->left, min, root->val);
        if(root->right)
            flag = flag && root->val < root->right->val && recursiveBody(root->right, root->val, max);
        return flag;
    }

    bool isValidBST(TreeNode* root) {
        return recursiveBody(root, LONG_MIN, LONG_MAX);
    }
};