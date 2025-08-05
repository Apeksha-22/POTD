// 904. Fruit Into Baskets



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>freq;
        vector<bool>chck(n);
        int f=0,s=0,cnt=0,ans=INT_MIN;
        while(f<=s && s<n){
            if(freq[fruits[s]]==0 && cnt < 3){
                cnt++;
            }
            freq[fruits[s]]++;
            s++;

            while(f<s && cnt > 2){
                freq[fruits[f]]--;
                if(freq[fruits[f]]==0) cnt--;

                f++;
            }
            ans = max(ans,s-f);
        }
        return ans;
    }
};
