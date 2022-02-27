class Solution {
public:
    void recursiveBody(vector<string>& res, string prev, int n_toadd, int n_added){
		//n_toadd: 还可以添加的左括号数量
		//n_added: 已添加的，且尚未有右括号匹配的左括号数量
        if(!n_toadd && !n_added)    res.push_back(prev);
        if(n_toadd)                 recursiveBody(res, prev+"(", n_toadd-1, n_added+1);
        if(n_added)                 recursiveBody(res, prev+")", n_toadd, n_added-1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursiveBody(res, "", n, 0);
        return res;
    }
};