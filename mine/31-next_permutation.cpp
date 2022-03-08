class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size(), p, q, temp;
        for(p = size - 2; p >= 0 && nums[p] >= nums[p+1]; --p);
        if(p >= 0){
            temp = nums[p];
            for(q = size - 1; nums[q] <= temp; --q);
            swap(nums[p], nums[q]);	//注意可用#include <algorithm>中的API
        }
        reverse(nums.begin()+p+1, nums.end());	//注意可用#include <algorithm>中的API
    }
};