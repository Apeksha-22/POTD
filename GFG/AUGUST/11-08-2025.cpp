// Maximum Non-Overlapping Odd Palindrome Sum



class Solution {
public:
    int maxSum(string &s) {
        int n = (int)s.size();
        if (n <= 1) return 0;
        vector<int> d(n);
        int L = 0, R = -1;
        for (int i = 0; i < n; ++i) {
            int k = 1;
            if (i <= R) k = min(d[L + R - i], R - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
            d[i] = k;
            if (i + k - 1 > R) {
                L = i - k + 1;
                R = i + k - 1;
            }
        }
        vector<int> r_end(n), start(n);
        for (int i = 0; i < n; ++i) {
            r_end[i] = i + d[i] - 1;
            start[i] = i - d[i] + 1;
        }
        vector<int> bestEnd(n, 0);
        priority_queue<pair<int,int>> pq;
        for (int e = 0; e < n; ++e) {
            int i = e;
            pq.push({1 - 2*i, r_end[i]});
            while (!pq.empty() && pq.top().second < e) pq.pop();
            if (!pq.empty()) bestEnd[e] = 2*e + pq.top().first;
            else bestEnd[e] = 0;
        }
        vector<int> bestStart(n, 0);
        priority_queue<pair<int,int>> pq2;
        for (int s = n - 1; s >= 0; --s) {
            int i = s;
            pq2.push({1 + 2*i, start[i]});
            while (!pq2.empty() && pq2.top().second > s) pq2.pop();
            if (!pq2.empty()) bestStart[s] = -2*s + pq2.top().first;
            else bestStart[s] = 0;
        }
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = bestEnd[0];
        for (int i = 1; i < n; ++i) leftMax[i] = max(leftMax[i-1], bestEnd[i]);
        rightMax[n-1] = bestStart[n-1];
        for (int i = n-2; i >= 0; --i) rightMax[i] = max(rightMax[i+1], bestStart[i]);

        int ans = 0;
        for (int i = 0; i + 1 < n; ++i) ans = max(ans, leftMax[i] + rightMax[i+1]);
        return ans;
    }
};
