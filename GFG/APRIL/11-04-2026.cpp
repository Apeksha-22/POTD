// Count increasing Subarrays



class Solution {
public:
    int countIncreasing(vector<int>& arr) {
        int tot = 0, cur = 0;

        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] < arr[i+1]){
                cur++;
            } else {
                cur = 0;
            }
            tot += cur;
        }
        return tot;
    }
};
