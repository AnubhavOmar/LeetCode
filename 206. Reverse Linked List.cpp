// Soluiton of LeetCode Problem
// 206. Reverse Linked List
// Solution in CPP

// Approach - 1 (Using Extra Space)

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