//Longest subarray with Atmost two distinct integers


class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        int f = 0, s = 1;
        int count = 1;
        int ans = 1;

        unordered_map<int, int> freq;
        vector<bool> check(100001, false);

        check[arr[f]] = true;
        freq[arr[f]]++;

        while (s < n) {
            if (!check[arr[s]]) {
                if (count < 2) {
                    check[arr[s]] = true;
                    freq[arr[s]]++;
                    count++;
                    s++;
                } else {
                    while (f < s) {
                        freq[arr[f]]--;
                        if (freq[arr[f]] == 0) {
                            check[arr[f]] = false;
                            count--;
                            f++;
                            break;
                        }
                        f++;
                    }
                }
            } else {
                freq[arr[s]]++;
                s++;
            }

            ans = max(ans, s - f);
        }

        return ans;
    }
};
