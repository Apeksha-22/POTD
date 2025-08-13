// 326. Power of Three



class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        if(n%3 != 0 || n<1)return false;
        return isPowerOfThree(n/3);
    }
};



//without loop/recursion

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1)return false;
        return 1162261467 % n==0;
    }
};
