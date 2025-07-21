// 1957. Delete Characters to Make Fancy String


class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        int cnt=1;
        string x;
        x.push_back(s[0]);
        for(int i=1; i<n; i++){
            if(x.back() == s[i]){
                cnt++;
                if(cnt<3){
                    x.push_back(s[i]);
                }
                
            }else{
                x.push_back(s[i]);
                cnt=1;
            }
        }
        return x;
    }
};
