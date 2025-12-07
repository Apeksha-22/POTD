//1523. Count Odd Numbers in an Interval Range



class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=0;
        for(int i=low; i<=high; i++)
        if(i%2 != 0)cnt++;
        return cnt;
    }
};


//2nd Method

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1)/2 - low/2;
    }
};
