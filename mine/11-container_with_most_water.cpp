class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_a=0, i=0, j=height.size()-1;
        while(i < j){
            int left = height[i], right = height[j];
            int a = min(left, right) * (j - i);
            if(left < right) for(++i; i < j && height[i] <= left;  ++i);
            else             for(--j; i < j && height[j] <= right; --j);
            max_a = (max_a < a) ? a : max_a;
        }
        return max_a;
    }
};