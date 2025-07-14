//Maximum sum of elements not part of LIS


class Solution {
  public:

 int nonLisMaxSum(vector<int>& arr) {
        // code here
        int dp[1001];
        int ans = INT_MIN;
         int n=arr.size();
        for(int i=0;i<n;i++){
            dp[i]=1;
        }
       int  par[1001];
        memset(par,-1,sizeof(par));
        int tot=arr[0];
       
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    if(dp[j]+1>=dp[i]){
                        dp[i]=dp[j]+1;
                        par[i]=j;
                    }
                }
            }
            tot+=arr[i];
        }
        int maxi=*max_element(dp,dp+n);

        for(int i=arr.size()-1;i>=0;i--){
            if(dp[i]==maxi){
                int sm=arr[i];
                int ind=par[i];
                while(ind!=-1){
                    sm+=arr[ind];
                    ind=par[ind];
                }
                ans=max(ans,tot-sm);
                
            }
        }
        return ans;
        
    }
};
