// Solution of LeetCode Problem
// 328. Odd Even Linked List
// Solution in CPP

// Approach - 1
// Using In-Place Two-Pointer Relinking
// Time Complexity: O(n) - The odd and even pointers traverse the list once.
// Space Complexity: O(1) - Only a constant number of node pointers are used.

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head ;

        ListNode * odd = head; 
        ListNode * even = head->next;

        ListNode * evenHead = even;

        while(odd->next != NULL && even->next != NULL)
        {
            odd->next = even->next ;
            odd = odd->next ;

            even->next = odd->next ;
            even = even->next ;
        }
        odd->next = evenHead ;
        
        return head;

    }
};

// Approach - 2
// Using Separate Arrays for Odd and Even Position Values
// Time Complexity: O(n) - The list is traversed to collect values and traversed again to rewrite them.
// Space Complexity: O(n) - The odd and even value arrays store all node values.

class Solution1 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        vector<int> odd_values;
        vector<int> even_values;

        ListNode* temp = head;
        int index = 1;

        while (temp != NULL)
        {
            if (index % 2 == 1)
                odd_values.push_back(temp->val);

            else
                even_values.push_back(temp->val);

            temp = temp->next;
            index++;
        }

        temp = head;

        for (int value : odd_values)
        {
            temp->val = value;
            temp = temp->next;
        }

        for (int value : even_values)
        {
            temp->val = value;
            temp = temp->next;
        }

        return head;
    }
};
