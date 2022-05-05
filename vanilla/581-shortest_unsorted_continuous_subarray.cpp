class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minele = INT_MAX, maxele = INT_MIN, n = nums.size(), l = -1, r = -1;
        for(int i = 0; i < n; ++i){
            if(nums[i] < maxele)        r = i;
            else                        maxele = nums[i];

            if(nums[n-1-i] > minele)    l = n - 1 - i;
            else                        minele = nums[n-1-i];
        }
        return r == -1 ? 0 : r - l + 1;
    }
};