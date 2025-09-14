// Gas Station




class Solution {

  public:

    int startStation(vector<int> &gas, vector<int> &cost) {

        // Your code here

        int n=gas.size();

        int totalgas=0;

        int totalcost=0;

        int balance=0;

        int start=0;

        for(int i=0;i<n;i++){

            totalgas+=gas[i];

            totalcost+=cost[i];

            balance+=(gas[i]-cost[i]);

            if(balance<0){

                start=i+1;

                balance=0;

            }

        }

    if(totalgas<totalcost){

        return -1;

    }

    return start;

    }

};
