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
    unordered_map<int, int> hash;   //元素具有唯一性，可用哈希加速

    TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder, int pleft, int ileft, int len){
        if(len == 0)  return nullptr;
        int val = preorder[pleft], i = hash[val] - ileft;
        return new TreeNode(val, buildNode(preorder, inorder, pleft+1, ileft, i), buildNode(preorder, inorder, pleft+1+i, ileft+i+1, len-i-1));        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i) hash[inorder[i]] = i;
        return buildNode(preorder, inorder, 0, 0, preorder.size());
    }
};