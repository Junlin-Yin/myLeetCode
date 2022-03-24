class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<int> areas(heights);
        int left, right, lmost = 0, rmost = heights.size() - 1, maxa = 0;
        for(int i = lmost; i <= rmost; ++i){
            while(!s.empty() && heights[s.top()] >= heights[i])   s.pop();
            left = s.empty() ? lmost : s.top() + 1;
            areas[i] += (i - left) * heights[i];
            s.push(i);
        }
        s = stack<int>();
        for(int i = rmost; i >= lmost; --i){
            while(!s.empty() && heights[s.top()] >= heights[i])   s.pop();
            right = s.empty() ? rmost: s.top() - 1;
            areas[i] += (right - i) * heights[i];
            s.push(i);
            maxa = max(maxa, areas[i]);
        }
        return maxa;
    }
};