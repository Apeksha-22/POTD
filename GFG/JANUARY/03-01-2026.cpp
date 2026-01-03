// Flattening a Linked List



/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    Node* merge(Node* head1, Node* head2){
        Node* head = new Node(0);
        Node* curr=head;
        
        while(head1 && head2){
            if(head1->data <= head2->data){
                curr->bottom = head1;
                curr=head1;
                head1 = head1->bottom;
                curr->bottom=NULL;
            }else{
                curr->bottom = head2;
                curr=head2;
                head2 = head2->bottom;
                curr->bottom=NULL;
            }
        }
        
        while(head1){
            curr->bottom = head1;
            curr=head1;
            head1 = head1->bottom;
            curr->bottom=NULL;
        }
        while(head2){
            curr->bottom = head2;
            curr=head2;
            head2 = head2->bottom;
            curr->bottom=NULL;
        }
        head = head->bottom;
        return head;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        Node *head1, *head2, *head3;
        
        while(root->next){
            head1 = root;
            head2 = head1->next;
            head3 = head2->next;
            root = merge(head1, head2);
            root->next = head3;
        }
        return root;
    }
};
