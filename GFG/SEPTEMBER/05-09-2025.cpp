// Sort a linked list of 0s, 1s and 2s




/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int cnt0=0, cnt1=0, cnt2=0;
        Node* curr=head;
        while(curr){
            if(curr->data == 0)
            cnt0++;
            else if(curr->data == 1)
            cnt1++;
            else
            cnt2++;
            
            curr = curr->next;
        }
        
        curr = head;
        
        while(curr){
            while(cnt0--){
                curr->data = 0;
                curr = curr->next;
            }while(cnt1--){
                curr->data = 1;
                curr = curr->next;
            }while(cnt2--){
                curr->data = 2;
                curr = curr->next;
            }
        }
        return head;
    }
};
