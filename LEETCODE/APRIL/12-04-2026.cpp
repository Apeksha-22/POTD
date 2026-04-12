// 1320. Minimum Distance to Type a Word Using Two Fingers



class Solution {
public:
    int d(int a, int b) {
        if (a == -1 || b == -1)
            return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string w) {
        int n = w.size();
        vector<vector<int>> dp(n, vector<int>(27, 1e9));

        dp[0][26] = 0;

        for (int i = 0; i < n - 1; i++) {
            int cur = w[i] - 'A';
            int nxt = w[i + 1] - 'A';

            for (int j = 0; j <= 26; j++) {
                if (dp[i][j] == 1e9)
                    continue;

                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + d(cur, nxt));

                dp[i + 1][cur] =
                    min(dp[i + 1][cur], dp[i][j] + d(j == 26 ? -1 : j, nxt));
            }
        }

        int ans = 1e9;
        for (int j = 0; j <= 26; j++)
            ans = min(ans, dp[n - 1][j]);

        return ans;
    }
};
