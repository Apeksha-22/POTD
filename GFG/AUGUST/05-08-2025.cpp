// Palindrome Sentence



class Solution {
  public:
    bool isPalinSent(string &s) {
    int n=s.size();
    string x="";
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i]) || isdigit(s[i])) {
            x += tolower(s[i]);
        }
    }
    int i = 0, j = x.size() - 1;
    while (i < j) {
        if (x[i] != x[j]) return false;
        i++;
        j--;
    }
    return true;

    }
};
