// Solution of LeetCode Problem 
// 21. Merge Two Sorted Lists
// Solution in CPP

// Approach - 1
// Using a Vector, Sorting, and Constructing a New Linked List
// Time Complexity: O((m + n) log(m + n)) - The values are collected in O(m + n), sorted, and copied into a new list.
// Space Complexity: O(m + n) - The vector and newly constructed result list store all values.

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


// Approach - 2
// Using Two Pointers and Linked-List Relinking
// Time Complexity: O(m + n) - Each node from both lists is processed once.
// Space Complexity: O(1) - Only constant extra pointers are used; existing nodes are relinked.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL) return NULL ;
        if(list1 == NULL)
        {
            return list2;
        }
        if(list2 == NULL)
        {
            return list1 ;
        }
        
        ListNode * head ;
        if(list1->val < list2->val)
        {
            head = new ListNode(list1->val) ;
            list1 = list1->next;
        }
        else
        {
            head = new ListNode(list2->val) ;
            list2 = list2->next;
        }

        ListNode * temp = head;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                temp->next = list1 ;
                temp = temp->next ;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = temp->next ;
                list2 = list2->next ;
            }
        }

        while(list1 != NULL)
        {
            temp->next = list1;
            list1 = list1->next ;
            temp = temp->next ;
        }

        while(list2 != NULL)
        {
            temp->next = list2;
            list2 = list2->next ;
            temp = temp->next ;
        }
        return head;
    }
};