// Buy Stock with Transaction Fee



class Solution {
  public:
    
    int solve(int i, bool buy, vector<int>& arr, int& k, vector<vector<int>>& dp) {
        
        if (i >= arr.size()) {
            return 0;
        }
        
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        int profit = solve(i+1, buy, arr, k, dp);
        
        if (buy) {
            int ans = -arr[i] - k + solve(i+1, false, arr, k, dp);
            profit = max(profit, ans);
        } else {
            int ans = arr[i] + solve(i+1, true, arr, k, dp);
            profit = max(profit, ans);
        }
        
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, true, arr, k, dp);
    }
};
