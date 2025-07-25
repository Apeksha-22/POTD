// 3487. Maximum Unique Subarray Sum After Deletion


class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int sum=0;
        int maxSum=0;
        if(nums[n-1]<0 || n==1) return nums[n-1];

        int i=n-1;
        int j=i-1;

        while(j>=0 && i>=0){
            if(nums[i] >= 0 && nums[i] != nums[j]){
                sum += nums[i];
                maxSum = max(maxSum, sum);
            }
            i--,j--;
        }
        if(i==0 && nums[i]>=0) maxSum += nums[i];
        return maxSum;
    }
};

TC --> O(n log n)  and SC --> O(1) if we use set then TC --> O(n) and SC --> O(n);
