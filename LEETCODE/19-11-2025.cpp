// 2154. Keep Multiplying Found Values by Two


class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            if (original == num) {
                original *= 2;
            }
        }
        return original;
    }
};
