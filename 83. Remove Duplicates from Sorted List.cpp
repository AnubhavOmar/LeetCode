// Solution of LeetCode Problem 
// 83. Remove Duplicates from Sorted List
// Solution in CPP 

// Approach - 1 


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * temp = head ;
        
        if (head == NULL) return head ;

        while(head->next != NULL)
        {
            if(head->val == head->next->val )
            {
                head->next = head->next->next;
            }
            else 
            {
            head = head->next;
            }
        }
        return temp ;
    }
};