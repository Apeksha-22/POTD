// Substrings with K Distinct



class Solution {
  public:
long long findnoOfStrings(string &s, int k){
        int n = s.length();
        int l = 0; int r = 0; int unique = 0;
        long long cnt = 0;
        vector<int>freq(26, 0);
        while(r<n){
            if (freq[s[r] - 'a'] == 0) unique++;
            freq[s[r] - 'a']++;
            while(unique > k){
                freq[s[l]-'a']--;
                if(freq[s[l]-'a']==0) unique--;
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    
    int countSubstr(string& s, int k) {
        // code here.
        if(k == 0) return 0;
        long long cnt1 = findnoOfStrings(s, k);
        long long cnt2 = findnoOfStrings(s, k-1);
        return (int)(cnt1-cnt2);
    }
};
