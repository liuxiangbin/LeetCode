/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *res = new ListNode(0);
        ListNode *i,*j,*k;
        i = head;
        j = head->next;
        k = res;
        
        while(j!=NULL){
            if(j->val == i->val){
                j = j->next;
            }
            else{
                if(i->next == j){
                    k->next = i;
                    k = k->next;
                    k->next = NULL;
                }
                
                i = j;
                j = j->next;
            }
        }
        
        if(i->next == j){
            k->next = i;
            k = k->next;
            k->next = NULL;
        }
        
        return res->next;
    }
};