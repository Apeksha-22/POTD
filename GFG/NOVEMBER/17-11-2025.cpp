// Max Sum Increasing Subsequence



class Solution {
  public:
    int helper(int i, int prev, vector<int>&arr, vector<vector<int>>&dp){
        if(i>=arr.size())return 0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        int not_take = 0, take = 0;
        if(prev < arr[i]){
            take = arr[i] + helper(i+1, arr[i], arr, dp);
        }
        not_take = helper(i+1, prev, arr, dp);
        return dp[i][prev] = fmax(take, not_take);
    }
    int maxSumIS(vector<int>& arr) {
        // code here
        int maxi = *max_element(arr.begin(), arr.end());
        vector<vector<int>>dp(arr.size(), vector<int>(maxi+1, -1));
        int prev = 0;
        return helper(0, prev, arr, dp);
    }
};
