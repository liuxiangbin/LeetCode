/*Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        int len = 0;
        for(;p1!=NULL;p1=p1->next)
            ++len;
        
        k = k%len;
        if(k==0)
            return head;
            
        p1 = head;
        while(k--)
            p1 = p1->next;
        while(p1->next!=NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        ListNode* res = p2->next;
        p1->next = head;
        p2->next = NULL;
        
        return res;
    }
};