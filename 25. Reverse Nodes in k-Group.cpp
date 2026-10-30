// Solution of LeetCode Problem
// 25. Reverse Nodes in k-Group
// Solution in CPP

// Approach - 1
// Using In-Place Linked-List Reversal in Groups
// Time Complexity: O(n) - Each node is inspected and relinked a constant number of times.
// Space Complexity: O(1) - Only constant extra pointers are used.

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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1)
        {
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL)
        {
            ListNode* temp2 = temp;
            int count = 1;

            // Find the kth node
            while (temp2 != NULL && count < k)
            {
                temp2 = temp2->next;
                count++;
            }

            // Fewer than k nodes remain
            if (temp2 == NULL)
            {
                break;
            }

            ListNode* target = temp2->next;
            ListNode* groupTail = temp;
            ListNode* previousTail = prev;

            // Reverse the current group.
            // target is the boundary after this group.
            reverse(temp, target, target);

            // Connect the previous group to the new group head
            if (previousTail == NULL)
            {
                head = temp2;
            }
            else
            {
                previousTail->next = temp2;
            }

            // Original first node becomes the group tail
            prev = groupTail;
            temp = target;
        }

        return head;
    }

    void reverse(ListNode* temp, ListNode* target, ListNode* prev)
    {
        ListNode* curr = temp;

        while (curr != target)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
};

// Approach - 2
// Using a Value Array and Reversing Complete Groups
// Time Complexity: O(n) - The list is copied, each value is reversed at most once, and values are written back.
// Space Complexity: O(n) - The vector stores all node values.

class Solution1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head ;
        vector<int>vec ;
        while(temp != NULL)
        {
            vec.push_back(temp->val);
            temp = temp->next ;
        }

        int n = vec.size() ;

        if(n == k) 
        {
            reverse(vec.begin() , vec.end()) ;
            temp = head ;

            int i = 0 ;
            while(temp != NULL)
            {
                temp->val = vec[i];
                i++ ;
                temp = temp->next; 
            }
            return head;
        }
            // here we are doing this if i reached to last vector size where elements left in vector is less than of k groups then exiting the for loop 
        for(int i = 0 ; i + k <= n  ; i += k)
        {
            reverse(vec.begin() + i, vec.begin() + i + k);
        }

        
        temp = head ;
        int i = 0 ;
        while(temp != NULL)
        {
            temp->val = vec[i];
            i++ ;
            temp = temp->next; 
        }
        return head;
    }
    
};