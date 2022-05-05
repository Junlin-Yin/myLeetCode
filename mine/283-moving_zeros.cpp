class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            if(!nums[i])    ++zeros;
            else if(zeros)  nums[i - zeros] = nums[i];
        }
        for(int i = n - zeros; i < n; ++i)  nums[i] = 0;
    }
};