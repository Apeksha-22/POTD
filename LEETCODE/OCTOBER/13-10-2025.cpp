//2273. Find Resultant Array After Removing Anagrams




class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>res;
        string last = words[0];
        sort(last.begin(),last.end());
        res.push_back(words[0]);
        for(int i=1; i<words.size(); i++){
            string curr = words[i];
            sort(curr.begin(),curr.end());
            if(last != curr)
            res.push_back(words[i]);

            last = curr;
        }
        return res;
    }
};
