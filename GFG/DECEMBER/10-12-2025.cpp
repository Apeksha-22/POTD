//Missing And Repeating



class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
           int n =  arr.size();
           int dup=-1;
           int miss=-1;
           
           for(int i:arr){
                int idx = abs(i)-1;
                if (dup ==-1 && arr[idx]<0){
                     dup = idx+1;
                }
                else{
                        arr[idx] = -1*arr[idx];
                } 
           }        
           
           for(int i=0;i<n;i++){
                if (arr[i]>0){
                    return {dup , i+1};
                }
           }
           
        return {-1,-1};
    }
};
