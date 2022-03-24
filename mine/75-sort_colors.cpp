class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        //基于桶排序
        int i0 = 0, i1 = 0, i2 = 0, i = 0;
        for(const auto &n: nums){
            switch(n){
                case 0: ++i0; break;
                case 1: ++i1; break;
                case 2: ++i2; break;
            }
        }
        while(i < i0)           nums[i++] = 0;
        while(i < i0 + i1)      nums[i++] = 1;
        while(i < i0 + i1 + i2) nums[i++] = 2;
    }
};

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        //基于交换
        int l = 0, r = nums.size() - 1, i = 0;
        while(true){
            for(; l < nums.size() && nums[l] == 0; ++l);
            for(; r > 0 && nums[r] == 2; --r);
            i = max(i, l);
            if(i > r)    break;
            if(nums[i] == 2)        swap(nums[i], nums[r--]);
            else if(nums[i] == 0)   swap(nums[i], nums[l++]);
            else                    ++i;
        }
    }
};