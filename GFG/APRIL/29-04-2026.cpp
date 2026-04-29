// Min Swaps to Group 1s



class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int totalOnes = accumulate(arr.begin(), arr.end(), 0);
        
        if(totalOnes == 0) return -1;
        
        int currOnes = 0;
        for(int i = 0; i < totalOnes; i++) {
            currOnes += arr[i];
        }
        
        int maxOnes = currOnes;
        for(int i = totalOnes; i < n; i++) {
            currOnes += arr[i] - arr[i - totalOnes];
            maxOnes = max(maxOnes, currOnes);
        }
        
        return totalOnes - maxOnes;
    }
};
