// Solution of LeetCode Problem
// 24. Swap Nodes in Pairs
// Solution in CPP

// Approach - 1
// Using Iterative Pointer Manipulation
// Time Complexity: O(N) - Traversing each node in the linked list of length N once
// Space Complexity: O(1) - Constant extra space used for auxiliary pointers

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;

        ListNode * temp = head ; 
        ListNode *prev = NULL;

        head = head->next;

        while(temp != NULL && temp->next != NULL)
        {
            ListNode * first = temp ;
            ListNode * second = temp->next ;

            first->next = second->next;
            second->next = first ;

            if (prev != NULL)
            {
                prev->next = second;
            }

            prev = first;
            temp = temp->next ;
        }
        return head;
    }
};
