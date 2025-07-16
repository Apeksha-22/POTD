//3201. Find the Maximum Length of Valid Subsequence I

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0, n = nums.size();

        int odd = 0, even = 0, alter = 1, prev = nums[0];
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1) odd++;
            else even++;

            if(i >= 1 && nums[i] % 2 != prev % 2){
                alter++;
                prev = nums[i];
            }
        }
        return max({odd, even, alter});
    }
};
