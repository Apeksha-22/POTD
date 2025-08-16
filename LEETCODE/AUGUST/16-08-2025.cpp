// 1323. Maximum 69 Number



//1st Solution


class Solution {
public:
    int maximum69Number (int num) {
        vector<int>arr;
        while(num>0){
            arr.push_back(num%10);
            num/=10;
        }
        reverse(arr.begin(),arr.end());

        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 6){
                arr[i] = 9;
                break;
            }
        }

        int p=0;
        for(int x : arr){
            p = p*10 + x;
        }
        return p;
    }
};


//2nd Solution



class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);

        for(int i=0; i<s.size(); i++){
            if(s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};



//3rd Solution



class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int pos= -1;
        int i=1;
        while(temp>0){
            int d = temp % 10;
            if(d == 6) pos = i;
            temp /= 10;
            i *= 10;
        }
        if(pos != -1) num += 3 * pos;
        return num;
    }
};
