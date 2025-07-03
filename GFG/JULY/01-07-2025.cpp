//Substrings of length k with k-1 distinct elements


class Solution {
  public:
int substrCount(string &s, int k) {
        int n = s.length();
        vector <int> freq(26, 0);
        
        int cnt = 0;
        for(int i = 0; i < k; i++){
            if(freq[s[i] - 'a'] == 0) cnt++;
            freq[s[i] - 'a']++;
        }
        
        int ans = (cnt == k-1);
        for(int i = k; i < n; i++){
            if(freq[s[i-k] - 'a'] == 1) cnt--;
            freq[s[i-k] - 'a']--;
            if(freq[s[i] - 'a'] == 0) cnt++;
            freq[s[i] - 'a']++;
            
            ans += (cnt == k-1);
        }
        
        return ans;
    }
};
