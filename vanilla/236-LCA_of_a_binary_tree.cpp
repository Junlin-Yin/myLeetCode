/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* LCA = NULL;

    bool find(TreeNode* root, TreeNode* p, TreeNode* q) {
        //find(T) := 以T为根的子树是否包含p节点 或 q节点
        //比起mine中的find(T)，这里避免了同时返回两个变量的尴尬
        if(!root)   return false;
        bool fl = find(root->left, p, q);
        bool fr = find(root->right, p, q);
        //注意LCA的判定条件
        if((fl && fr) || (root == p || root == q) && (fl || fr))
            LCA = root;
        return fl || fr || (root == p) || (root == q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find(root, p, q);
        return LCA;
    }
};