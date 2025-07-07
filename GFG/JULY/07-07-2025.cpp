//Next Greater Element in Circular Array



class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>res(n,-1);
        stack<int>st;
        
        int i=0;
        while(i < 2*n){
            while(!st.empty() && arr[st.top()] < arr[i%n]){
                res[st.top()] = arr[i%n];
                st.pop();
            }
            st.push(i%n) , i++;
        }
        
        return res;
    }
};
