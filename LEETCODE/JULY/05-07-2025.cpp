//1394. Find Lucky Integer in an Array


class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freq;

        for(int x : arr)
        freq[x]++;

        int res=-1;

        for(auto& [val, count] : freq){
            if(val == count){
                res = max(res, val);
            }else continue;
        }
        return res;
    }
};
