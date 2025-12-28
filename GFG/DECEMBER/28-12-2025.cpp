//Minimum time to fulfil all orders



class Solution {
public:
    bool check(long long time, int req, vector<int>& ranks) {
        long long count = 0;

        for (int r : ranks) {
            long long val = (sqrt(1 + 8LL * time / r) - 1) / 2;
            if (val > 0) count += val;
            if (count >= req) return true;
        }
        return false;
    }
    int minTime(vector<int>& ranks, int n) {
        long long l = 0, h = 1e18;
        long long ans = -1;

        while (l <= h) {
            long long md = l + (h - l) / 2;
            if (check(md, n, ranks)) {
                ans = md;
                h = md - 1;
            } else {
                l = md + 1;
            }
        }
        return ans;
    }
};
