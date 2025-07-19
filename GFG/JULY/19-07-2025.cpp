//Count Unique Vowel Strings


class Solution {
  public:
    int fact(int n){
        if(n <= 1) return 1;
        return n * fact(n-1);
    }
    int vowelCount(string& s) {
        // code here
        int j=0,a=0,e=0,i=0,o=0,u=0,cnt=0,prod=1;
        while(j<s.size()){
            if(s[j] == 'a')
            a++;
            else if(s[j] == 'e')
            e++;
            else if(s[j] == 'i')
            i++;
            else if(s[j] == 'o')
            o++;
            else if(s[j] == 'u')
            u++;
            
            
            j++;
        }
        
        if(a!=0)cnt++;
        if(e!=0)cnt++;
        if(i!=0)cnt++;
        if(o!=0)cnt++;
        if(u!=0)cnt++;
        
        if(cnt == 0) return 0;
        
        if(a) prod *= a;
        if(e) prod *= e;
        if(i) prod *= i;
        if(o) prod *= o;
        if(u) prod *= u;

        return prod * fact(cnt);
    }
};
