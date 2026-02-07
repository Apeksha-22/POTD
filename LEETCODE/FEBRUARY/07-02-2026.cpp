// 1653. Minimum Deletions to Make String Balanced



class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0, count = 0;
        for (char c : s){
            if (c == 'b')
                count++;
            else if (count){
                res++;
                count--;
            }
        }
        return res;
    }
};
