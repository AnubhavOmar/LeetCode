// Solution of LeetCode Problem
// 24. Swap Nodes in Pairs
// Solution in CPP

// Approach - 1: Iterative Pointer Manipulation
// Time Complexity: O(N) - Traversing each node once
// Space Complexity: O(1) - Constant extra space
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

// Approach - 2: Recursive
// Time Complexity: O(N) - Traversing each node once
// Space Complexity: O(N) - Recursive stack space
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        return reversal(head);
    }

    ListNode *reversal(ListNode *node)
    {
        if (node == NULL || node->next == NULL)
        {
            return node;
        }

            ListNode * remaining = reversal(node->next->next);

            ListNode * first = node ;
            ListNode * second = node->next ;

            first->next = remaining;
            second->next = first ;

            return second;
    }

};
