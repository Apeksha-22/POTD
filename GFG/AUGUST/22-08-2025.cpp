// Median in a row-wise sorted Matrix



class Solution {
  public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mn = min(mn, mat[i][0]);
            mx = max(mx, mat[i][m - 1]);
        }

        int req = (n * m + 1) / 2;
        while (mn < mx) {
            int mid = mn + (mx - mn) / 2;

            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (cnt < req) mn = mid + 1;
            else mx = mid;
        }
        return mn;
    }
};
