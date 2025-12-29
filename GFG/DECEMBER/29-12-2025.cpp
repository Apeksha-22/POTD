// K-th element of two Arrays



class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        vector<int>mergearr;
        int i=0, j=0;
        while(i<a.size() && j<b.size()){
            if(a[i] <= b[j]){
                mergearr.push_back(a[i]);
                i++;
            }else{
                mergearr.push_back(b[j]);
                j++;
            }
        } while(i<a.size()){
            mergearr.push_back(a[i]);
            i++;
        }while(j<b.size()){
            mergearr.push_back(b[j]);
            j++;
        }
        
        return mergearr[k-1];
    }
};
