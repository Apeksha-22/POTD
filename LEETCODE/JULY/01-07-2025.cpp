//3330. Find the Original Typed String I


class Solution {
public:
    int possibleStringCount(string word) {
        int count=1;
        string s = word;
        int n=word.size();
        for(int i=n-1; i>0; i--){
            if(s[i] == s[i-1]){
                s.pop_back();
                count++;
            }
        }
        return count;
    }
};
