// Palindrome Binary



class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        vector<int> bits;
        bits.reserve(32);
        while(n > 0) {
            (n&1) ? bits.push_back(1) : bits.push_back(0);
            n >>= 1;
        }
        
        int l = 0;
        int r = bits.size() - 1;
        while(l <= r) {
            if(bits[l] != bits[r]) {
                return false;
            }
            
            l++;
            r--;
        }
        
        return true;
    }
};
