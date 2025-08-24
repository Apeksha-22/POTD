// 1493. Longest Subarray of 1's After Deleting One Element




class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zero=0;

        int f=0,s=0,cnt=0;
        while(s<n){
            if(nums[s] == 0)zero++;
            while(f<s && zero > 1){
                if(nums[f] == 0)zero--;
                f++;
            }
            cnt = max(cnt, s-f);
            s++;            
        }
        return cnt;
    }
};
