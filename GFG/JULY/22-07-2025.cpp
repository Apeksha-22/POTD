// Smallest Positive Missing


class Solution {
public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int idx = lower_bound(arr.begin(), arr.end(), 1) - arr.begin();
        int ele = 1;
        while(idx < n){
            if(arr[idx] < ele) ++idx;
            else if(arr[idx] == ele){
                ++idx; 
                ++ele;
            }
            else break;
        }
        return ele;
    }
};
