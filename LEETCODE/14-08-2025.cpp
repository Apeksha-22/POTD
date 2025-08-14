// 2264. Largest 3-Same-Digit Number in String


class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        vector<string>store =
        {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

        for(int i=0; i<num.size(); i++){
            string s = num.substr(i,3);
            auto it = find(store.begin(),store.end(),s);
            if(it != store.end()){
                ans = max(s,ans);
            }
        }
        return ans;
    }
};



// one more method

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i=0; i<num.size(); i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                string s = num.substr(i,3);
                ans = max(s,ans);
            }
        }
        return ans;
    }
};
