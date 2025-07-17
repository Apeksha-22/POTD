//3136. Valid Word


class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int n=word.size();
        int i=0,cnt=0,cnt1=0;
        while(i<n){
            if(word[i] == '0' || word[i] == '1' || word[i] == '2' || word[i] == '3' || word[i] == '4' || word[i] == '5' || word[i] == '6' || word[i] == '7' || word[i] == '8' || word[i] == '9'){
                i++;
            }else if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U'){
                cnt++;
                i++;
            }
            else if((word[i] == '@' || word[i] == '#' || word[i] == '$'))
            return false;
            else{
                cnt1++;
              i++;   
            }
        }
        return cnt!=0 && cnt1!= 0;
    }
};
