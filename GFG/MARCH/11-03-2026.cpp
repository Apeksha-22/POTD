// Sum of subarray minimums



class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int ans=0;
        vector<int> nse(arr.size(),arr.size()), pse(arr.size(),-1);
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<arr.size();i++){
            ans+=arr[i]*(nse[i]-i)*(i-pse[i]);
        }
        return ans;
    }
};
