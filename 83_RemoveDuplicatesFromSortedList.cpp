/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
        ListNode *res = head;
        if(head==NULL)
            return res;
            
        ListNode *i = head,*j = head;
        while(j->next!=NULL){
            while(j->next!=NULL&&j->val==i->val)
                j = j->next;
            if(j->val==i->val){
                i->next = j->next;
                return res;
            }
            else{
                i->next = j;
                i = i->next;
            }
        }
        
        return res;
    }
};