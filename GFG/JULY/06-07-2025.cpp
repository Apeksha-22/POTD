//Maximum Sum Combination

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        priority_queue<tuple<int, int, int>> pq;
        set<pair<int, int>> vis;
        vector<int> res;

        pq.push(make_tuple(a[0] + b[0], 0, 0));
        vis.insert({0, 0});

        while (k-- && !pq.empty()) {
            int sum, i, j;
            tie(sum, i, j) = pq.top(); pq.pop();
            res.push_back(sum);

            if (i + 1 < n && vis.count({i + 1, j}) == 0) {
                pq.push(make_tuple(a[i + 1] + b[j], i + 1, j));
                vis.insert({i + 1, j});
            }

            if (j + 1 < n && vis.count({i, j + 1}) == 0) {
                pq.push(make_tuple(a[i] + b[j + 1], i, j + 1));
                vis.insert({i, j + 1});
            }
        }

        return res;
    }
};
