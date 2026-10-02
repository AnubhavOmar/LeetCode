// Solution of LeetCode Problem
// 19. Remove Nth Node From End of List
// Solution in CPP

// Approach - 1
// Using Two Pointers
// Time Complexity: O(n) - The fast and slow pointers traverse the list in linear time.
// Space Complexity: O(1) - Only a constant number of pointers and variables are used.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Case 1: Empty list
        if(head == NULL)
        {
            return head;
        }

        // Case 2: Sirf ek node hai
        if(head->next == NULL)
        {
            return NULL;
        }

        ListNode * fast  = head;
        ListNode * slow ;
        int idx = 0 ;
        // fast pointer first moves to n nodes
        while(idx < n)
        {
            fast = fast->next ;
            idx++;
        }
        if(fast == NULL)
        {
            return head->next;
        }

        // this pointer now will start form head node and both pointer will move simultaneously now and when the fast ptr will reach last node then prev will at one behind the node which is to be removed 
        
        slow = head ;
        while(fast->next != NULL)
        {
            slow = slow->next ;
            fast = fast->next ;
        }

        if(slow->next->next != NULL || slow->next != NULL)
        {
            slow->next = slow->next->next ;
        }
        else
        {
            slow->next = NULL ;
        }

        return head ;
    }
};

// Approach - 2
// Using an Array and Constructing a New Linked List
// Time Complexity: O(n) - The list is traversed to store values and traversed again to build the result.
// Space Complexity: O(n) - The values vector and newly constructed list use linear extra space.

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        vector<int> values;
        ListNode * curr = head;

        while(curr != NULL)
        {
            values.push_back(curr->val);
            curr = curr->next;
        }

        int size = values.size();
        int deleted_node = size - n;
        int idx = 0;

        ListNode * newHead = NULL;
        ListNode * prev = NULL;

        while(idx < size)
        {
            if(idx != deleted_node)
            {
                ListNode * newNode = new ListNode(values[idx]);

                if(newHead == NULL)
                {
                    newHead = newNode;
                    prev = newNode;
                }
                else
                {
                    prev->next = newNode;
                    prev = newNode;
                }
            }

            idx++;
        }

        return newHead;
    }
};

// Approach - 3
// Using List Length Calculation
// Time Complexity: O(n) - One traversal calculates the length and another locates and removes the node.
// Space Complexity: O(1) - Only constant extra pointers and variables are used.

class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = traverse(head) ;
        int deleted_node = size - n  + 1 ;
        int idx = 1 ;
        if(size - n == 0)
        {
            return head->next ;
        }
        ListNode * prev  ;
        ListNode * curr = head  ;

        while(curr->next != NULL)
        {
            if(idx == deleted_node )
            {
                curr = curr->next ;
                prev->next = curr ;
                break ;
            }
            else
            {
                prev = curr ;
                curr = curr->next ;
            }
            idx++;
        }
        if( n == 1)
        {
            prev->next = NULL ;
        }
        return head ;
    }
    int traverse(ListNode * node)
    {
        int count = 0 ;
        while(node != NULL)
        {
            count++ ;
            node = node->next ;
        }
        return count ;
    }
};