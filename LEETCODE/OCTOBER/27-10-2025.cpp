// 2125. Number of Laser Beams in a Bank



class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        int n=bank[0].size();
        vector<int>temp;
        for(auto& s : bank){
            int sum=0;
            for(char c : s)
            sum += c-'0';
            if(sum != 0)
            temp.push_back(sum);
        }
        int res = 0;
        if(temp.size() == 0)return 0;
        for(int i=0; i<temp.size()-1; i++){
            res += temp[i] * temp[i+1];
        }
        return res;
    }
};
