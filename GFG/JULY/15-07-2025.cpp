//Divisible by 13


class Solution {
  public:
    bool divby13(string & str) {
        // code here
        string  s = str;
        reverse(s.begin(),s.end());
        
        while(!s.empty()){
            int x = s.back() - '0';
            s.pop_back();
            while(x < 13 && !s.empty()){
                x = x*10 + (s.back() - '0');
                s.pop_back();
            }
            if(x < 13) return false;
            int rem = x%13;
            while(rem != 0){
                // char ch;
                char ch = (rem % 10) + '0';
                s += ch;
                rem /= 10;
            }
        }
        return true;
    }
};
