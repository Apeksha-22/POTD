// 2411. Smallest Subarrays With Maximum Bitwise OR


class Solution {
public:
    vector<int>smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        unordered_map<int, int> orToIndex;

        for (int i = n - 1; i >= 0; i--) {
            unordered_map<int, int> newOrMap;
            newOrMap[nums[i]] = i;

            for (auto [prevOr, j] : orToIndex) {
                int newOr = nums[i] | prevOr;
                if (newOrMap.count(newOr))
                    newOrMap[newOr] = min(newOrMap[newOr], j);
                else
                    newOrMap[newOr] = j;
            }

            orToIndex = newOrMap;

            int maxOR = 0, minLen = n;
            for (auto [orr, j] : orToIndex) {
                if (orr > maxOR) {
                    maxOR = orr;
                    minLen = j - i + 1;
                } else if (orr == maxOR) {
                    minLen = min(minLen, j - i + 1);
                }
            }

            res[i] = minLen;
        }

        return res;
    }
};
