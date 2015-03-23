/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return head;
            
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        
        ListNode *i,*j,*k;
        i = head;
        j = head->next;
        k = j->next;
        
        while(k!=NULL){
            p->next = j;
            j->next = i;
            i->next = NULL;
            p = i;
            i = k;
            j = k->next;
            if(j!=NULL)
                k = j->next;
            else
                k = NULL;
        }
        
        if(j!=NULL){
            p->next = j;
            j->next = i;
            i->next = NULL;
            return res->next;
        }
        
        if(i!=NULL){
            p->next = i;
            i->next = NULL;
            return res->next;
        }
        
        return res->next;
    }
};