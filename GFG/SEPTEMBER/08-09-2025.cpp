// Merge Sort for Linked List




/*
class Node {
public:
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
    Node* findMiddle(Node* head)
    {
        Node* slow = head;
        Node* fast = head->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* mergeTwoList(Node* l1, Node* l2)
    {
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        while(l1 !=nullptr && l2!=nullptr)
        {
            if(l1->data < l2->data)
            {
                temp->next = l1;
                temp=l1;
                l1=l1->next;
            }
            else
            
            {
                temp->next = l2;
                temp=l2;
                l2 = l2->next;
                
            }
            
        }
        
        if(l1) temp->next = l1;
        else (temp->next)=l2;
        
        return dummyNode->next;
    }
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==nullptr || head->next== nullptr) return head;
        Node* middle = findMiddle(head);
        Node* left = head;
        Node* right = middle->next;
        middle->next = nullptr;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        return mergeTwoList(left,right);
    }
};
