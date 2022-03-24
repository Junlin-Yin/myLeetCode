class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        //加入首尾两哨兵，初始化单调栈
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0);
        int result = 0;
        for (int i = 1; i < heights.size(); i++) {
            while (heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int w = i - st.top() - 1;
                int h = heights[mid];
                result = max(result, w * h);    //计算出栈处柱子的右展宽度（单调栈保证了其左展宽度为0）
            }
            st.push(i);
        }
        return result;
    }
};