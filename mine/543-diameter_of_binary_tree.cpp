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

    int diameter = 0;

    int longestRootPath(TreeNode* T) {
        if(!T)  return -1;
        int l_LRP = longestRootPath(T->left);
        int r_LRP = longestRootPath(T->right);
        diameter = max(diameter, 2 + l_LRP + r_LRP);
        return 1 + max(l_LRP, r_LRP);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        longestRootPath(root);
        return diameter;
    }
};