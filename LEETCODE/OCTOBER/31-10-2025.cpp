//3289. The Two Sneaky Numbers of Digitville




class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>res;

        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1])
            res.push_back(nums[i]);
            if(res.size() == 2) break;
        }
        return res;
    }
};
