// Count Subarray with k odds



class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        
        int i=0;
        int j=0;
        int n = (int)arr.size();
    
        int count =0;
        int ans1 =0;
        int ans2 =0;
        while(j<n)
        {
            if(arr[j]%2)
            count++;
            
            while(i<=j && count>(k-1))
            {
                if(arr[i]%2)
                count--;
                i++;
                
            }
            ans1+=(j-i+1);
            j++;
        }
        j=0;
        i=0;
        count=0;
        while(j<n)
        {
            if(arr[j]%2)
            count++;
            
            while(i<=j && count>(k))
            {
                if(arr[i]%2)
                count--;
                i++;
            }
            ans2+=(j-i+1);
            j++;
        }
        return ans2-ans1;
    }
};
