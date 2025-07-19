//1233. Remove Sub-Folders from the Filesystem


class Solution {
public:
    bool check(string& a, string& b){
        int i=1,j=1;

        while(i<a.size()){
            if(a[i] != b[j])
            return false;

            i++, j++;
        }
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>res;
        res.push_back(folder[0]);

        for(int i=1; i<folder.size(); i++){
            string prev = res.back();
            string curr = folder[i];
            if(curr.size() > prev.size() && curr.substr(0,prev.size()) == prev && curr[prev.size()] == '/'){
                continue;
            }

            res.push_back(folder[i]);
        }
        return res;
    }
};
