// 898. Bitwise ORs of Subarrays


class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>prv,cur,res;
        for(int num : arr){
            cur.clear();
            cur.insert(num);
            for(int x : prv){
                cur.insert(x|num);
            }
            prv = cur;
            res.insert(prv.begin(),prv.end());
        }
        return res.size();
    }
};
