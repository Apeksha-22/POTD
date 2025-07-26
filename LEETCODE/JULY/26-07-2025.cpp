// 3480. Maximize Subarrays After Removing One Conflicting Pair


class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& a) {
        vector<vector<int>> g(n + 1);
        for (auto& p : a) {
            g[max(p[0], p[1])].push_back(min(p[0], p[1]));
        }

        long long res = 0;
        vector<long long> top = {0, 0};
        vector<long long> b(n + 1, 0);

        for (int r = 1; r <= n; ++r) {
            for (int l : g[r]) {
                if (l > top[0]) top = {l, top[0]};
                else if (l > top[1]) top = {top[0], l};
            }

            res += r - top[0];
            if (top[0] > 0) b[top[0]] += top[0] - top[1];
        }

        long long mx = 0;
        for (long long x : b) mx = max(mx, x);

        return res + mx;
    }
};
