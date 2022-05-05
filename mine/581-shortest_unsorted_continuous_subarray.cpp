class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i, j, n = nums.size();
        for(i = 1; i < n && nums[i] >= nums[i - 1]; ++i);
        if(i == n)  return 0;
        for(j = n - 2; j >= 0 && nums[j] <= nums[j + 1]; --j);
        int l = min(i, j), r = max(i, j);
        int minele = *min_element(nums.begin() + l, nums.begin() + r + 1);
        int maxele = *max_element(nums.begin() + l, nums.begin() + r + 1);
        bool f1 = true, f2 = true;
        while(f1 || f2){
            if(l > 0 && nums[l - 1] > minele){
                f1 = true;
                maxele = max(maxele, nums[--l]);
            }else   f1 = false;
            if(r < n - 1 && nums[r + 1] < maxele){
                f2 = true;
                minele = min(minele, nums[++r]);
            }else   f2 = false;
        }
        return r - l + 1;
    }
};