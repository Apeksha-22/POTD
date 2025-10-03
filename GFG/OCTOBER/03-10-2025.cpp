class Solution {
  public:
  
    void solve(vector<int>&arr,string &t,int i,int &n,
        vector<string>&ans,unordered_map<int,string>&m){
        
        if(i==n){
            ans.push_back(t);
            return;
        }
        
        for(int j=0;j<m[arr[i]].length();j++){
            t+=m[arr[i]][j];
            solve(arr,t,i+1,n,ans,m);
            t.pop_back();
        }
        if(arr[i]==1 || arr[i]==0)solve(arr,t,i+1,n,ans,m);
        
    }
  
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        unordered_map<int,string>m;
        m[1]="";
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        
        string t="";
        vector<string>ans;
        int n = arr.size();
        
        solve(arr,t,0,n,ans,m);
        
        return ans;
    }
};
