// Merge K sorted linked lists




/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
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
                curr->next = head1;
                curr=head1;
                head1 = head1->next;
                curr->next=NULL;
            }else{
                curr->next = head2;
                curr=head2;
                head2 = head2->next;
                curr->next=NULL;
            }
        }
        
        while(head1){
            curr->next = head1;
            curr=head1;
            head1 = head1->next;
            curr->next=NULL;
        }
        while(head2){
            curr->next = head2;
            curr=head2;
            head2 = head2->next;
            curr->next=NULL;
        }
        head = head->next;
        return head;
    }
    
    void mergeSort(vector<Node*>& arr, int start, int end){
        if(start>=end) return;
        
        int mid = start + (end-start)/2;
        
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        arr[start] = merge(arr[start],arr[mid+1]);
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        mergeSort(arr,0,arr.size()-1);
        return arr[0];
    }
};
