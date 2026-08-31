// Solution of LeetCode Problem
// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// Solution in CPP

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

// Approach - 1
// Using Single Pass Linked List Traversal and Critical Point Tracking
// Time Complexity: O(N) - Single pass through the linked list of length N
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       if (head == NULL || head->next == NULL || head->next->next == NULL)
            return {-1, -1};

        ListNode * prev = head ;
        ListNode * curr = head->next ;
        ListNode * nexxt = head->next->next ;

        int min_dist = INT_MAX ;
        int max_dist = INT_MIN ;

        int indexx = 2 ;
        int prev_index = -1 ;
        int next_index = -1 ;

        int first_index = -1 ;


        while(nexxt != NULL)
        {
            bool critical_point = false;
            if( (prev->val < curr->val && nexxt->val < curr->val) || (prev->val > curr->val && nexxt->val > curr->val) )
            {
                critical_point = true ;
                prev_index = next_index ;
                next_index = indexx ;
            }
            
            if(critical_point)
            {
                if(first_index == -1)
                {
                    first_index = indexx; 
                }
                else
                {
                    min_dist = min(min_dist, indexx - prev_index);
                }

                prev_index = indexx;      

            }
            
            prev = curr ;
            curr = nexxt ;
            nexxt = nexxt->next ;
            indexx++;
        }

        if(first_index != -1)
        {
            max_dist = next_index - first_index ;
        }

        if(min_dist == INT_MAX || max_dist == INT_MIN)
        {
            return { -1 , -1 };
        }
        

        return  {min_dist , max_dist};
    }
};