// 2785. Sort Vowels in a String




class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<char>tem;
        for(int i=0;i<n;i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || 
            s[i] ==  'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || 
            s[i] == 'o' || s[i] == 'u'){
                tem.push_back(s[i]);
            }else{
                continue;
            }
        }
        sort(tem.begin(), tem.end());
        int x=0;
        for(int i=0; i<n; i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || 
            s[i] ==  'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || 
            s[i] == 'o' || s[i] == 'u'){
                s[i] = tem[x];
                x++;
            }else{
                continue;
            }
        }
        return s;
    }
};
