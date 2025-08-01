// Balancing Consonants and Vowels Ratio


class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // code here
        int n=arr.size();
        int ans=0,cnt=0;
        unordered_map<int,int>freq;
        freq[0]=1;
        for(int i=0; i<n; i++){
            for(char ch : arr[i]){
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                    cnt++;
                }else cnt--;
            }
            ans += freq[cnt];
            freq[cnt]++;
        }
        return ans;
    }
};
