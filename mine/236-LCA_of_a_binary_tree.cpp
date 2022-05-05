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
    TreeNode* LCA;

    bool find(TreeNode* root, TreeNode* p, TreeNode* q, bool& hasp, bool& hasq) {
		//find(T) := 以T为根的子树是否 分别 包含p节点 和 q节点
        if(!root)   return false;
        bool l_hasp = false, l_hasq = false, r_hasp = false, r_hasq = false;
        if(find(root->left, p, q, l_hasp, l_hasq))  return true;
        if(find(root->right, p, q, r_hasp, r_hasq)) return true;
        hasp = l_hasp || r_hasp || root == p;
        hasq = l_hasq || r_hasq || root == q;
        if(hasp && hasq)    LCA = root;
        return hasp && hasq;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool hasp = false, hasq = false;
        find(root, p, q, hasp, hasq);
        return LCA;
    }
};