// 3655. XOR After Range Multiplication Queries II



class Solution {
public:
    const int mod = 1e9 + 7;

    long long pwr(long long bas, long long exp) {
        long long res = 1;

        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * bas) % mod;
            }
            bas = (bas * bas) % mod;
            exp /= 2;
        }
        return res;
    }

    long long inv(long long val) {
        return pwr(val, mod - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int len = nums.size();
        int lim = sqrt(len);
        unordered_map<int, vector<vector<int>>> mpq;

        for (auto qry : queries) {
            int lft = qry[0];
            int rgt = qry[1];
            int stp = qry[2];
            int val = qry[3];

            if (stp >= lim) {
                for (int idx = lft; idx <= rgt; idx += stp) {
                    nums[idx] = (1LL * nums[idx] * val) % mod;
                }
            } else {
                mpq[stp].push_back(qry);
            }
        }

        for (auto itm : mpq) {
            int stp = itm.first;
            auto grp = itm.second;

            vector<long long> eff(len, 1);

            for (auto qry : grp) {
                int lft = qry[0];
                int rgt = qry[1];
                int val = qry[3];

                eff[lft] = (eff[lft] * val) % mod;

                int cnt = (rgt - lft) / stp;
                int end = lft + (cnt + 1) * stp;

                if (end < len) {
                    eff[end] = (eff[end] * inv(val)) % mod;
                }
            }

            for (int idx = 0; idx < len; idx++) {
                if (idx >= stp) {
                    eff[idx] = (eff[idx] * eff[idx - stp]) % mod;
                }
                nums[idx] = (1LL * nums[idx] * eff[idx]) % mod;
            }
        }
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};
