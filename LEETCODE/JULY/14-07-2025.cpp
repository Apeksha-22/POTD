//1290. Convert Binary Number in a Linked List to Integer



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s = "";
        ListNode *curr = head;
        while(curr){
            s += curr->val;
            curr = curr->next;
        }

        reverse(s.begin(), s.end());

        int n = s.size();
        int res=0;
        for(int i=0; i<n; i++){
            int x = pow(2,i);
            res += (s[i] * x);
        }
        return res;
    }
};
