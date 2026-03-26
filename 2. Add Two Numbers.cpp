// Solution of LeetCode Problem 
// 2. Add Two Numbers
// Solution in CPP 

// Approach - 1 (Using an vector and then inserting the elements of the vector to the list )

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        vector<int> vec;
        int carry = 0;

        // Step 1: store sum in vector
        while (l1 != NULL || l2 != NULL || carry) {
            
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = val1 + val2 + carry;

            vec.push_back(sum % 10);
            carry = sum / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // Step 2: convert vector to linked list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for (int num : vec) {
            curr->next = new ListNode(num);
            curr = curr->next;
        }

        return dummy->next;
    }
};

// Approach - 2 (Not using any vector)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) {
            
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = val1 + val2 + carry;

            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }

        return dummy->next;
    }
};