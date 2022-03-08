class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
		//双指针：若当前子串和为负，则比较该子串和与该处元素，确定是否更新子串起始位置
		//若当前字串和为正，则直接与该处元素相加，子串终止位置右移，随即更新子串和
        int maxS = -1e6, S = 0;
        for(auto i: nums){
            if(S < 0)   S = max(S, i);
            else        S += i;
            maxS = max(maxS, S);
        }
        return maxS;
    }
};

class Solution2 {
public:
    struct Node{
        int nS, lS, rS, mS;
    };

    Node recursiveBody(vector<int>& nums, int l, int r){
        if(l == r){
            int ele = nums[l];
            return {ele, ele, ele, ele};
        }else{
            int m = (l + r) >> 1, nS, lS, rS, mS;
            Node lnode = recursiveBody(nums, l, m);
            Node rnode = recursiveBody(nums, m + 1, r);
            nS = lnode.nS + rnode.nS;
            lS = max(lnode.lS, lnode.nS + rnode.lS);
            rS = max(rnode.rS, rnode.nS + lnode.rS);
            mS = max(lnode.rS + rnode.lS, max(lnode.mS, rnode.mS));
            return {nS, lS, rS, mS};
        }
    }

    int maxSubArray(vector<int>& nums) {
		//分治之线段树
        Node ans = recursiveBody(nums, 0, nums.size()-1);
        return ans.mS;
    }
};