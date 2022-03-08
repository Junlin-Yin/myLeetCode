class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0, lidx, hidx;
        stack<int> s;
        s.push(0);
        for(int i=1; i<height.size(); ++i){
            int h0 = height[i];
            while(lidx = s.top(), height[lidx] <= h0){
                s.pop();
                if(s.empty()) break;
                hidx = s.top();
                int w = i - hidx - 1;
                int h = min(height[hidx], h0) - height[lidx];
                area += w * h;
            }
            s.push(i);
        }
        return area;
    }
};