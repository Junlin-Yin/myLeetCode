class Solution1 {
public:
    unordered_map<int, bool> mem;

    bool dfs(string& s, vector<string>& wordDict, int i0) {
        if(i0 == s.size())              return true;
        if(mem.find(i0) != mem.end())   return mem[i0];
        bool flag = false;
        for(const string& w: wordDict) {
            int len = w.size();
            if(s.size() - i0 >= len && s.substr(i0, len) == w && dfs(s, wordDict, i0 + len)){
                flag = true; break;            
            }
        }
        return mem[i0] = flag;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict, 0);
    }
};

class Solution2 {
public:
    unordered_map<int, bool> mem;
    //字典树结构
    struct Trie{
        Trie* next[26];
        bool  isEnd;
        Trie(){
            for(int i = 0; i < 26; ++i) this->next[i] = nullptr;
            isEnd = false;
        }
    };
    Trie* root;

    bool dfs(string& s, int i0) {
        if(i0 == s.size())              return true;
        if(mem.find(i0) != mem.end())   return mem[i0];
        bool flag = false;
        Trie *p = root;
        for(int i = i0; i < s.size() && p->next[s[i] - 'a']; ++i){
            p = p->next[s[i] - 'a'];
            if(p->isEnd && dfs(s, i+1)){
                flag = true; break;
            }
        }
        return mem[i0] = flag;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        root = new Trie();
        for(const auto& w: wordDict){
            Trie *p = root;
            for(const auto& c: w){
                if(!p->next[c - 'a'])   p->next[c - 'a'] = new Trie();
                p = p->next[c - 'a'];
            }
            p->isEnd = true;
        }
        return dfs(s, 0);
    }
};