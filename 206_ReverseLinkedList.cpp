/*
Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
            
        ListNode* res = head;
        head = head->next;
        ListNode* p = head;
        res->next = NULL;
        
        while(head!=NULL){
            head = head->next;
            p->next = res;
            res = p;
            p = head;
        }
        
        return res;
    }
};