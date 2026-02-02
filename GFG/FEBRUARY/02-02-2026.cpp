// Max Circular Subarray Sum



class Solution {
  public:
    int maxKadane(vector<int>&arr){
        int curr=arr[0];
        int maxSum = arr[0];
        for(int i=1; i<arr.size(); i++){
            curr = max(arr[i], curr+arr[i]);
            maxSum = max(curr, maxSum);
        }
        return maxSum;
    }
    int minKadane(vector<int>&arr){
        int curr=arr[0];
        int minSum = arr[0];
        for(int i=1; i<arr.size(); i++){
            curr = min(arr[i], curr+arr[i]);
            minSum = min(curr,minSum);
        }
        return minSum;
    }
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int total=accumulate(arr.begin(),arr.end(),0);
        int maxK = maxKadane(arr);
        int minK = minKadane(arr);
        if(maxK < 0) return maxK;

        return max(maxK, total-minK);
        
    }
};
