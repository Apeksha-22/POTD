// 3507. Minimum Pair Removal to Sort Array I



class Solution {
public:
    int cnt = 0;
    bool sor(vector<int>&nums){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
    void minop(vector<int>&nums){
        if(sor(nums)) return;
        vector<int>temp(nums.size()-1);
        int idx=-1;
        int sum=INT_MAX;
        for(int i=0;i<nums.size()-1; i++){
            if(nums[i] + nums[i+1] < sum){
                sum = nums[i] + nums[i+1];
                idx = i;
            }
        }
        for(int i=0; i<idx; i++)
        temp[i] = nums[i];
        temp[idx] = sum;
        for(int i=idx+1; i<nums.size()-1; i++)
        temp[i] = nums[i+1];
        cnt+=1;
        minop(temp);
    }
    int minimumPairRemoval(vector<int>& nums) {
        
        minop(nums);
        return cnt;
    }
};
