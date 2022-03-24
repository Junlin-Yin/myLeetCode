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
    TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder, int pleft, int ileft, int len){
        if(len == 0)  return nullptr;
        int val = preorder[pleft], i;
		for(i = 0; i < len && inorder[ileft + i] != val; ++i);
        return new TreeNode(val, buildNode(preorder, inorder, pleft+1, ileft, i), buildNode(preorder, inorder, pleft+1+i, ileft+i+1, len-i-1));        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //递归
        return buildNode(preorder, inorder, 0, 0, preorder.size());
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //迭代，preorder是进栈顺序，inorder是出栈顺序
        stack<TreeNode*> s;
        int p = 0, q = 0, N = preorder.size();
        TreeNode* root = new TreeNode(preorder[p++]), *t;
        s.push(root);
        while(!s.empty()){
            while(!s.empty() && q < N && inorder[q] != s.top()->val){
                s.top()->left = new TreeNode(preorder[p++]);
                s.push(s.top()->left);
            }
            while(!s.empty() && q < N && inorder[q] == s.top()->val){
                t = s.top(); s.pop();
                ++q;
            }
            if(p < N){
                t->right = new TreeNode(preorder[p++]);
                s.push(t->right);
            }
        }
        return root;
    }
};