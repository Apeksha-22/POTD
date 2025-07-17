//3202. Find the Maximum Length of Valid Subsequence II


class Solution {
public:
    int maximumLength(vector<int>& a, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 0;
        for (int x : a) {
            int r = x % k;
            for (int j = 0; j < k; ++j) {
                dp[j][r] = dp[r][j] + 1;
                ans = max(ans, dp[j][r]);
            }
        }
        return ans;
    }
};
