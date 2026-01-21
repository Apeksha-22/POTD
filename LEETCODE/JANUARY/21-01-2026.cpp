//3315. Construct the Minimum Bitwise Array II



class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res(nums.size(),-1);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0)continue;
            string temp = bitset<32>(nums[i]).to_string();
            for(int j=31; j>=0; j--){
                if(temp[j] == '0'){
                    temp[j+1] = '0';
                    break;
                }
            }res[i] = stoll(temp,NULL,2);
        }
        return res;
    }
};
