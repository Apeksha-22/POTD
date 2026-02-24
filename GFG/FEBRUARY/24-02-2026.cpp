// Longest Span in two Binary Arrays



class Solution {
  public:
    int equalSumSpan(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        unordered_map<int, int> mp;
        int max_len = 0, prefix_sum = 0;
    
        for (int i = 0; i < n; i++) {
            int diff = a1[i] - a2[i];
            prefix_sum += diff;
    
            if (prefix_sum == 0) {
                max_len = i + 1;
            }
            if (mp.find(prefix_sum) != mp.end()) {
                max_len = max(max_len, i - mp[prefix_sum]);
            } else {
                mp[prefix_sum] = i;
            }
        }
        return max_len;
    }
};
