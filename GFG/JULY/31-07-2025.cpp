// Powerful Integer


#include <iterator>
class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& iv, int k) {
        map<int, int> m;
        for (auto& v : iv) {
            m[v[0]] += 1;
            m[v[1] + 1] -= 1;
        }

        int cnt = 0, ans = -1;
        for (auto it = m.begin(); it != m.end(); ++it) {
            cnt += it->second;
            auto nxt = next(it);
            if (nxt != m.end() && cnt >= k) {
                ans = max(ans, nxt->first - 1);
            }
        }

        return ans;
    }
};
