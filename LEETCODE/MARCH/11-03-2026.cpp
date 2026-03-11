// 1009. Complement of Base 10 Integer



class Solution {
public:
    int bitwiseComplement(int n){
        if(n==0) return 1;
        int cnt=0;
        int x = n;
        while(n>0){
            n=n/2;
            cnt++;
        }
        bitset<32>b(x);
        for(int i=0; i<cnt; i++){
            b.flip(i);
        }
        return b.to_ulong();
    }
};
