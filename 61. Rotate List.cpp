 // Solution of LeetCode POTD
// 61. Rotate List
// Solution in CPP 

// Approach - 1 : (First find the size of the linked list. Then compute k % size to handle large rotations. Traverse to the (size - k - 1)th node and break the list from that point. The next node becomes the new head. Finally, traverse to the end of the new list and connect its last node to the original head to complete the rotation.)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL) return head;  

        int sizee =  0 ;
        ListNode *head1 = head ;
        while(head1 != NULL)
        {
            sizee++;
            head1 = head1->next ;
        }

        head1 = head ;
        k = k % sizee ;

        if(k==0) return head ;
        for(int i = 0 ; i<sizee - k - 1; i++)
        {
            head1 = head1->next ;
        }

        ListNode* new_head = head1->next; 

        head1->next = NULL ;

        ListNode* temp = new_head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = head;

        return new_head;
    }
};