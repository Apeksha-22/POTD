// Smallest window containing 0, 1 and 2



class Solution {
public:
    int smallestSubstring(string s) {
        int count[10] = {0};
        int mini = INT_MAX;
        int j = 0;
        int cnt = 0;
        for(int i = 0;i<s.length();i++){
            count[s[i]-'0']++;
            if(count[s[i]-'0'] == 1){
                cnt++;
            }
            if(cnt == 3){
                mini = min(mini,i-j+1);
                while(1){
                   count[s[j]-'0']--;
                   if(count[s[j]-'0'] == 0){
                       mini = min(mini,i-j+1);
                       j++;
                       cnt--;
                       break;
                   }
                   j++;
                }
            }
        }
        if(mini == INT_MAX){
            return -1;
        }
        return mini;
    }
};
