// Find H-Index



class Solution {
public:
    int hIndex(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int h = 0;
        for (int i = 0; i < n; i++) {
            int cnt = n - i;
            h = max(h, min(a[i], cnt));
        }
        return h;
    }
};
