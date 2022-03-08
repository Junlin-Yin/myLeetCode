class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0, lmax = 0, rmax = 0, l = 0, r = height.size()-1;
        //S[i] = (min(lmax_i, rmax_i) - h_i) * 1, area = sum_i{S[i]}
        while(l <= r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            //h_l < h_r -> lmax_l < rmax_r <= rmax_l -> S[l] = lmax_l - h_l
            if(height[l] < height[r])   area += lmax - height[l++];
            //h_l >= h_r -> lmax_r >= lmax_l >= rmax_r -> S[r] = rmax_r - h_r
            else                        area += rmax - height[r--];
        }
        return area;
    }
};