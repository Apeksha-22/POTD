// ASCII Range Sum


class Solution {
public:
    vector<int> asciirange(string& s) {
        unordered_map<char, pair<int, int>> charPos;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (charPos.find(s[i]) == charPos.end()) {
                charPos[s[i]] = {i, i};
            } else {
                charPos[s[i]].second = i;
            }
        }

        vector<int> res;

        for (auto& [ch, pos] : charPos) {
            int start = pos.first;
            int end = pos.second;
            if (start < end) {
                int sum = 0;
                for (int i = start + 1; i < end; i++) {
                    sum += (int)s[i];
                }
                if (sum > 0) res.push_back(sum);
            }
        }

        return res;
    }
};
