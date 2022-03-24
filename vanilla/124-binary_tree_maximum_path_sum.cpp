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
    int globalMaxPS = INT_MIN;

    int calcMaxRootPathSum(TreeNode* T) {
        if(!T)   return 0;
        //*MaxRPS: 以*为上端点的最大路径和
        //*MaxPS:  以*为根，且经过*的最大路径和
        int lMaxRPS = calcMaxRootPathSum(T->left);
        int rMaxRPS = calcMaxRootPathSum(T->right);
        int tMaxRPS = T->val + max(0, max(lMaxRPS, rMaxRPS));
        int tMaxPS  = T->val + max(0, lMaxRPS) + max(0, rMaxRPS);
        globalMaxPS = max(globalMaxPS, tMaxPS);
        return tMaxRPS;
    }

    int maxPathSum(TreeNode* root) {
        calcMaxRootPathSum(root);
        return globalMaxPS;
    }
};