// Subarrays with First Element Minimum



class Solution {
public:
    int countSubarrays(vector<int> &arr) {
        // code here
        stack<pair<int,int>> st;
        int n = arr.size();
        st.push({arr[n-1],n-1});
        vector<int> v;
        v.push_back(-1);
        for(int i = n-2;i>=0;i--){
            int a = arr[i];
            while(!st.empty() && a<=st.top().first){
                st.pop();
            }
            if(!st.empty()){
                v.push_back(st.top().second);
            }
            else{
                v.push_back(-1);
            }
            st.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        int cnt = 0;
        for(int i = 0;i<v.size();i++){
            if(v[i] == -1){
                cnt += (n-i);
            }
            else{
                cnt += (v[i]-i);
            }
        }
        return cnt;
    }
};
