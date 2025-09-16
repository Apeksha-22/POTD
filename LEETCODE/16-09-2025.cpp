// 2197. Replace Non-Coprime Numbers in Array




class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int num : nums) {
            while (!st.empty()) {
                int top = st.back();
                int g = gcd(top, num);
                if (g == 1) {
                    break;
                }
                st.pop_back();
                long long merged = (long long)top / g * num;
                num = (int)merged;
            }
            st.push_back(num);
        }
        return st;
    }
    
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
