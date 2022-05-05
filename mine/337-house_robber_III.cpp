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
    void f(TreeNode* T, int& f0, int& f1){
        //f(T) := 以T为根的子树能抢劫的最大值，分两种状态返回，0为不抢根节点，1为要抢根节点
        if(!T){
            f0 = f1 = 0;
        }else{
            int f0_l, f1_l, f0_r, f1_r;
            f(T->left, f0_l, f1_l);
            f(T->right, f0_r, f1_r);
            f0 = max(f0_l, f1_l) + max(f0_r, f1_r);
            f1 = T->val + f0_l + f0_r;
        }
    }

    int rob(TreeNode* root) {
        int f0, f1;
        f(root, f0, f1);
        return max(f0, f1);
    }
};