class Solution1 {
public:
    int searchSorted(vector<int>& nums, int l, int r, int target){
        int k = -1, mid;
        while(l <= r){
            mid = (l + r) >> 1;
            if(target > nums[mid])      l = mid + 1;
            else if(target < nums[mid]) r = mid - 1;
            else{ k = mid; break; }
        }
        return k;
    }

    int search(vector<int>& nums, int target) {
        int sz = nums.size(), l = 0, r = sz-1, mid, k = -1;
        while(l <= r){
            mid = (l + r) >> 1;
            if(nums[l] <= nums[mid]){   //l to mid is sorted
                if(target >= nums[l] && target <= nums[mid]){
                    k = searchSorted(nums, l, mid, target);
                    break;
                }else{
                    l = mid + 1;
                }
            }else{                      //mid to r is sorted
                if(target <= nums[r] && target >= nums[mid]){
                    k = searchSorted(nums, mid, r, target);
                    break;
                }else{
                    r = mid - 1;
                }
            }
        }
        return k;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size(), l = 0, r = sz-1, k = sz - 1;
        if(nums[0] > nums[sz-1]){
            while(l <= r){
                k = (l + r) >> 1;
                if(nums[k] > nums[k+1])     break;
                if(nums[k] < nums[0])       r = k - 1;
                if(nums[k] > nums[sz-1])    l = k + 1;
            }            
        }
        //在找到截断点后，直接判断target在前半段还是后半段，然后简单二分
        if(target >= nums[0])   {l = 0; r = k;}
        else                    {l = k + 1; r = sz - 1;}
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] > target)      r = mid - 1;
            else if(nums[mid] < target) l = mid + 1;
            else return mid;
        }
        return -1;
    }
};