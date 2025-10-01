class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = 0;
        int empty = 0;
        int full = numBottles;

        while (full > 0) {
            totalDrank += full;
            empty += full;
            full = empty / numExchange;
            empty = empty % numExchange;
        }

        return totalDrank;
    }
};
