//231. Power of Two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=0; i<32; i++){
            long long x=pow(2,i);
            if(x==n)
                return true;
        }    
        return false;
    }
};



//Another Solution 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
