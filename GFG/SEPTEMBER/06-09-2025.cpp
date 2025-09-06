// Find length of Loop




/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node *slow = head, *fast = head;

        // Step 1: Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Count loop length
                int count = 1;
                slow = slow->next;
                while (slow != fast) {
                    count++;
                    slow = slow->next;
                }
                return count;
            }
        }

        // No loop
        return 0;
    }
};
