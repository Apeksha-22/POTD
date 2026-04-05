// Gray Code



class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
          int bits = n;
    vector<string> sequence = {"0","1"};
    
    
    for(int j = 1; j < bits; j++){
        vector<string> temp;
        
        for(int i = sequence.size() - 1; i >= 0; i--){
            string s = "1" + sequence[i];
            temp.push_back(s);
        }
        
        for(int i = 0; i < sequence.size(); i++){
            sequence[i] = "0" + sequence[i];
        }
        
       for(string num : temp){
          sequence.push_back(num);
       }
       
       temp.clear();
        
    }
    
    return sequence;
    }
};
