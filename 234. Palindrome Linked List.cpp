// Solution of LeetCode Problem
// 234. Palindrome Linked List
// Solution in CPP

// Approach - 1
// Using an Array and Two-Pointer Comparison
// Time Complexity: O(n) - The list is traversed once and the stored values are compared once.
// Space Complexity: O(n) - The array stores all node values.

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

class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;

        ListNode* temp = head;

        while (temp != NULL) 
        {
            values.push_back(temp->val);
            temp = temp->next;
        }

        int left = 0;
        int right = values.size() - 1;

        while (left < right)
        {
            if (values[left] != values[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

// Approach - 2
// Using Slow/Fast Pointers with a First-Half Value Array
// Time Complexity: O(n) - The pointers find the midpoint and the second half is compared once.
// Space Complexity: O(n) - The array stores up to half of the list values.

class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if(head->next == NULL) return true ;
        if(head->next->next == NULL)
        {
            // only 2 nodes 
            if(head->val == head->next->val)
            {
                return true; 
            }
            return false;
        }
        vector<int>values ;
        ListNode * slow = head ;
        ListNode * fast = head ;
        
        while(fast != NULL && fast->next != NULL)
        {
            values.push_back(slow->val) ;
            slow = slow->next ;
            fast = fast->next->next ;
        }

        if (fast != NULL)
        {
            // middle skip
            slow = slow->next;
        }
        
        int idx = values.size() - 1;

       while (idx >= 0)
       {
            if (slow->val != values[idx])
            {
                return false;
            }

            idx--;
            slow = slow->next;
        }
        return true;
    }
};

// Approach - 3
// Using Slow/Fast Pointers and In-Place Reversal
// Time Complexity: O(n) - Finding the midpoint, reversing the second half, and comparing values are linear passes.
// Space Complexity: O(1) - Only constant extra pointers are used.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if(head->next == NULL) return true ;
        if (head->next->next == NULL)
        {
            // only 2 nodes 
            return head->val == head->next->val;
        }

        ListNode * fast = head;
        ListNode * slow = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next ;
            fast = fast->next->next ;
        }
        
        if (fast != NULL)
        {
            // middle skip
            slow = slow->next;
        }

        // now we reach to the middle now we will reverse the whole linklist after the half and then we again traverse from the head and middle and match the values on nodes

        ListNode * prev = NULL;
        ListNode * curr = slow ;
        ListNode * next ;

        while(curr != NULL)
        {
            next = curr->next ;

            curr->next = prev ;

            prev = curr ;
            
            curr = next ;
        }
        // now we have reverse linked list form middle 

        // now from here we will check again from start 
        // prev is now the head of the reversed second half

        ListNode * temp = head ;
        ListNode * temp2 = prev ;
        
        while(temp2 != NULL)
        {
           if(temp->val != temp2->val)
           {
                return false;
           } 
        
            temp = temp->next;
            temp2 = temp2->next;
        
        }
        return true ;
    }
};