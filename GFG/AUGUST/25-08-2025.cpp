// Maximize median after doing k addition operation




class Solution {
public:
    bool ok(int n, vector<int>& a, long long m, long long k) {
        long long need = 0;
        int h = n / 2;
        if (n % 2) {
            need += max(0LL, m - (long long)a[h]);
        } else {
            need += max(0LL, 2 * m - ((long long)a[h] + a[h - 1]));
        }
        for (int i = h + 1; i < n; i++) {
            need += max(0LL, m - (long long)a[i]);
            if (need > k) return false;
        }
        return need <= k;
    }

    int maximizeMedian(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        long long l = a[0], r = a[n - 1] + k, ans = l;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            if (ok(n, a, m, k)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return (int)ans;
    }
};
