//3461. Check If Digits Are Equal in String After Operations I




class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int>dig;
        for(char ch : s)
        dig.push_back(ch - '0');

        while(dig.size() > 2){
            for(int i=0; i<dig.size()-1; i++)
            dig[i] = (dig[i] + dig[i+1])%10;

            dig.pop_back();
        }

        if(dig[0] == dig[1])return true;
        else return false;
    }
};




// one more approach


class Solution {
public:
    string func(string& s){
        string temp = "";
        for(int i=0; i<s.size()-1; i++)
        temp += (s[i] -'0' + s[i+1]-'0')%10;
        return temp;
    }
    bool hasSameDigits(string s) {
        string temp;
        while(true){
        temp=func(s);
        if(temp.size() == 2)
        break;
        s = temp;
        }
        if(temp[0] == temp[1])
        return true;
        else return false;
    }
};
