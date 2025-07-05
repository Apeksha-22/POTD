//Max Score from Subarray Mins


class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int maxi = 0;
        int i=0, j=1;
        while(j<n && i<j){
            int sum = arr[i]+ arr[j];
            maxi = max(maxi, sum);
            i++, j++;
        }return maxi;
    }
};
