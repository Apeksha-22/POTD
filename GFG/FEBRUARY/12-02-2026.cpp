// Max min Height



class Solution {
public:
    bool canAchieve(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> diff(n + 1, 0);
        long long ops = 0, currAdd = 0;

        for (int i = 0; i < n; i++) {
            currAdd += diff[i];
            int effectiveHeight = arr[i] + currAdd;

            if (effectiveHeight < target) {
                int add = target - effectiveHeight;
                ops += add;
                if (ops > k) return false;
                currAdd += add;
                if (i + w < n) diff[i + w] -= add;
            }
        }
        return true;
    }

    int maxMinHeight(vector<int>& arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int ans = low;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canAchieve(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
