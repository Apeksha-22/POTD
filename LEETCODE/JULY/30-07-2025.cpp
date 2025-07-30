// 2419. Longest Subarray With Maximum Bitwise AND


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val=0, res=0, curr=0;

        for(int x : nums){
            if(max_val < x){
               max_val = x;
                res=curr=0;
            }
            if(max_val == x){
                curr++;
            }else{
                curr=0;
            }
            res = max(res,curr);
        }
        return res;
    }
};
