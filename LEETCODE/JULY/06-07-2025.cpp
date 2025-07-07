//1865. Finding Pairs With a Certain Sum

class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int x : nums2)
        freq[x]++;
    }
    
    void add(int idx, int val) {
        freq[nums2[idx]]--;
        nums2[idx] += val;
        freq[nums2[idx]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(int x : nums1){
            int y = tot-x;
            ans += freq[y];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
