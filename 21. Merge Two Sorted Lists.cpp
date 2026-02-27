// Solution of LeetCode Problem 
// 21. Merge Two Sorted Lists
// Solution in CPP 

// Approach - 1 (Using a vector to store the values of both lists and then sorting it and adding them in a new linked list )

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        vector<int> v;
        
        while(list1 != NULL) {
            v.push_back(list1->val);
            list1 = list1->next;
        }

        while(list2 != NULL) {
            v.push_back(list2->val);
            list2 = list2->next;
        }

        sort(v.begin(), v.end());

        if(v.size() == 0) return NULL;

        ListNode* head = new ListNode(v[0]);
        ListNode* curr = head;

        for(int i = 1; i < v.size(); i++) {
            curr->next = new ListNode(v[i]);
            curr = curr->next;
        }

        return head;
    }
};


// Appraoch - 2  (Not Using any vector only moving the nodes to a new list and returning its head)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Step 1: Create dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        // Step 2: Compare both lists
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // Step 3: Attach remaining nodes
        if (list1 != NULL) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Step 4: Return merged list
        return dummy->next;
    }
};