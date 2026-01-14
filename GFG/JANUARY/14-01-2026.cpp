// Police and Thieves



class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        vector<int>P;
        vector<int>T;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 'P'){
                P.push_back(i);
            }else
            T.push_back(i);
        }
        
        int i=0,j=0,count=0;
        
        while(i<P.size() && j<T.size()){
            if(abs(P[i] - T[j]) <=k){
                count++;
                i++;
                j++;
            }else if(P[i] < T[j]){
                i++;
            }else
            j++;
        }
        return count;
    }
};
