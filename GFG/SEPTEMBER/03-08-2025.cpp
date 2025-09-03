//Reverse a Doubly Linked List





/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node *temp = head, *curr = NULL, *front=NULL;
        while(temp){
            front = temp->next;
            curr = temp->prev;
            temp->prev = front;
            temp->next = curr;
            curr= temp;
            temp = front;
        }
        return curr;
    }
};
