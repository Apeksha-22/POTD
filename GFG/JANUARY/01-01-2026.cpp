// Linked list Node



/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node* curr1=head1;
        while(curr1->next){
            curr1 = curr1->next;
        }curr1->next = head1;
        
        Node*slow = head2, *fast = head2;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            break;
        }
        
        slow = head2;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
