// Max sum in the configuration



class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
       int ans = INT_MIN;
       int n =arr.size();
       int sum = 0;
       int t = 0;
       for(int i = 0;i<n;i++)
       {
           t = t+arr[i];
           sum = sum + i*arr[i];
       }
       ans = max(ans, sum);
       for(int i = n-1;i>=0;i--)
       {
           sum = sum + t;
           sum = sum - arr[i] * (n);
           ans = max(ans,sum);
       }
       return ans;
    }
};
