// Soluiton of LeetCode Problem
// 206. Reverse Linked List
// Solution in CPP

// Approach - 5 
// Using Recursion 
/* 
  This approach recursively traverses to the end of the list.
  It uses a helper function `reversal` which returns the current node after pointing its next node's next back to itself.
  A global pointer `headd` is used to store and return the new head of the reversed list (the original last node).
 */

// Time Complexity: O(N) - since we visit each node exactly once.
// Space Complexity: O(N) - due to the recursion stack which can go up to N levels.
class Solution {
public:
ListNode* headd = NULL ;
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;

        ListNode * nodee = reversal(head);
        nodee->next = NULL;
        return headd;
    }

    ListNode * reversal(ListNode *node)
    {
        if(node->next == NULL)
        {
            headd = node ;
            return node ;
        }
        ListNode *temp = reversal(node->next) ;
        // here this temp will consist of the address from which we have to connect the current node
        temp->next = node ;
        // break the node connection and reverse it and then return its address
        return node ;
    }

};


// Approach - 4 
// Using three pointers 
// Time Complexity: O(N) - since we traverse the list exactly once.
// Space Complexity: O(1) - as we only use a constant amount of auxiliary space.
class Solution4 {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL) return head;

        ListNode * prev = NULL ;
        ListNode * curr = head ;
        ListNode * next ;
        while(curr->next != NULL)
        {
            // set the next ptr to next node of the list
            next = curr->next ;

            // Reversing the connection of current node
            curr->next = prev ;

            // updating the previous pointer
            prev = curr ;

            // updating the Current pointer
            curr = next ;
        }

        curr->next = prev ;

        return curr ;
    }
};


 // Appraoch - 3 
 // using stack to reverse the linked list 
 // Time Complexity: O(N) - where N is the number of nodes, as we traverse the list to push nodes onto the stack and then pop them.
 // Space Complexity: O(N) - since we store all the nodes (except the last one) in the stack.

class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL) return head;

        stack<ListNode *> st ;
        ListNode * temp = head ;
        // Inserting all the elements before lastnode

        while(temp->next != NULL)
        {
            st.push(temp);
            temp = temp->next;
        }

        // Point the head to the last node for giving the reverse linked list address start 
        
        head = temp ;
        
        while(!st.empty())
        {
            temp->next = st.top() ;
            st.pop() ;
            temp = temp->next ;
        }
        temp->next = NULL ;
        return head ;   
    }
};


 // Approach  - 2 (Using Recursion)
 // Time Complexity: O(N) - as we recursively visit each node.
 // Space Complexity: O(N) - due to the recursion stack of size N.
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL) return head;

        return reversell(head);
    }

    ListNode* reversell(ListNode * node )
    {
        if(node->next == NULL)
        {
            return node;
        }

        ListNode* newHead = reversell(node->next);


        node->next->next = node;

        node->next = NULL;
        
        return newHead;
    }

};

// Updating the Values of the node 
// Time Complexity: O(N) - as we traverse the list to store values, reverse the vector, and then update the node values.
// Space Complexity: O(N) - to store the node values in a vector of size N.
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *temp = head ;
        vector<int>list ;

        while(temp != NULL)
        {
            list.push_back(temp->val);
            temp = temp->next ;
        }
        
        reverse(list.begin(),list.end());

        temp = head ;

        for(int i = 0 ; i < list.size() ; i++)
        {
            temp->val  = list[i];
            temp = temp->next ;
        }

        
        
        return head;
    }
};