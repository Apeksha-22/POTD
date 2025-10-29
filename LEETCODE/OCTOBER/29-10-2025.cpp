// 3370. Smallest Number With All Set Bits



class Solution {
public:
    int smallestNumber(int n) {
        int ans=0;
        int tmp=n;
        while(tmp>0){
            ans++;
            tmp >>= 1;
        }
        int res = 1LL << ans;
        return res-1;
    }
};
