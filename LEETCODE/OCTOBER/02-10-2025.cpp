class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        long long full=0, empty=0, total=0, ex=numExchange;

        full=numBottles;
        while(full>0){
            empty += full;
            total += full;
            full=0;
            if(empty - ex >= 0){
                empty -= ex;
                full++;
                ex++;
            }else
            break;
        }
        return total;
    }
};
