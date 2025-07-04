3304. Find the K-th Character in String Game I


class Solution {
public:
    char kthCharacter(int k) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if ((1 << t) == k) {
                t--;
            }
            k = k - (1 << t);
            ans++;
        }
        return 'a' + ans;
    }
};


// one more solution

class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        int i=0;
        while(s.size() < k){
            int j=0;
            string x = "";
            while(j<s.size()){
                char ch = s[j] + 1;
                x += ch;
                j++;
            }
            s += x;
        }
        return s[k-1];
    }
};
