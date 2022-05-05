/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    int depth(TreeNode* root) {
        if(!root)   return -1;
        return max(depth(root->left), depth(root->right)) + 1; 
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if(!root)   return s;
        queue<pair<TreeNode*, int>> q;
        q.push({root, depth(root)});
        while(!q.empty()){
            TreeNode* p = q.front().first; 
            int d = q.front().second;
            q.pop();
            s += p ? to_string(p->val) : "null";
            s += ",";
            if(p && d){
                q.push({p->left, d - 1});
                q.push({p->right, d - 1});
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        if(data == "")  return root;
        queue<TreeNode*> q;
        int s1 = 0, s2 = data.find_first_of(",", s1);
        int val = stoi(data.substr(s1, s2 - s1));
        s1 = s2 + 1;
        root = new TreeNode(val);
        q.push(root);
        while(!q.empty()){
            TreeNode *p = q.front(); q.pop();
            s2 = data.find_first_of(",", s1);
            if(s2 == string::npos)  break;
            string sval_left = data.substr(s1, s2 - s1);
            if(sval_left != "null"){
                p->left = new TreeNode(stoi(sval_left));
                q.push(p->left);
            }
            s1 = s2 + 1;
            s2 = data.find_first_of(",", s1);
            if(s2 == string::npos)  break;
            string sval_right = data.substr(s1, s2 - s1);
            if(sval_right != "null"){
                p->right = new TreeNode(stoi(sval_right));
                q.push(p->right);
            }
            s1 = s2 + 1;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));