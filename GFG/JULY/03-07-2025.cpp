//Longest Substring with K Uniques


class Solution {
  public:
    int longestKSubstr(string &x, int k) {
        // code here
        int n = x.size(), f=0, s=0;
        int ans = -1;
        vector<bool>check(26,0);
        int total=0;
        for(char ch : x){
            if(!check[ch - 'a'])
            total++;
        }
        
        if(total < k) return -1;
        unordered_map<char,int>freq;
        int cnt=0;
        while(s<n){
            freq[x[s]]++;
            if(freq[x[s]] == 1)cnt++;
            s++;
            
            while(cnt > k){
                freq[x[f]]--;
                if(freq[x[f]] == 0)cnt--;
                f++;
            
            }
            if (cnt == k)
            ans = max(ans, s - f);
        }
        return ans;
    }
};
