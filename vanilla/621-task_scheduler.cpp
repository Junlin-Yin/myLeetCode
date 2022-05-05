class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int t = tasks.size();
        vector<int> freq(26, 0);
        for(const char& c: tasks)   ++freq[c - 'A'];
        int maxexe = *max_element(freq.begin(), freq.end());
        int maxcnt = 0;
        for(const int& f: freq)     maxcnt += (int)(f == maxexe);
        return max(t, (n + 1) * (maxexe - 1) + maxcnt);
    }
};