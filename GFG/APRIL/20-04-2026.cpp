// Count Derangements



class Solution {
  public:
    int f(int i, int bit, int n,vector<vector<int>>& dp){
        if(i==n)return 1;
        if(dp[i][bit]!=-1)return dp[i][bit];
        int ans=0;
        for(int x=1;x<=n;x++){
            if(x==i+1)continue;
            if((bit&(1<<x))==0){
                ans+=f(i+1,bit|(1<<x),n,dp);
            }
        }
        return dp[i][bit]=ans;
    }
    int derangeCount(int n) {
        // code here
        int bit=0;
        vector<vector<int>> dp(n,vector<int>(1<<13,-1));
        return f(0,bit,n,dp);
    }
};
