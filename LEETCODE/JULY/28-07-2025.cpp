// 2044. Count Number of Maximum Bitwise-OR Subsets



class Solution {
public:
int count=0,tar=0;
    void tracking(vector<int>& nums, int idx, int n, int orr){
        if(idx == n){
            if(orr == tar) count++;
            return;
        }
        tracking(nums, idx+1, n, orr);
        orr |= nums[idx];
        tracking(nums, idx+1, n, orr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        for(int x:nums){
            tar |= x;
        }
        tracking(nums,0,n,0);
        return count;
    }
};
