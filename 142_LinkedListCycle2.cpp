/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                fast = head;
                while(fast!=slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        
        return NULL;
    }
};