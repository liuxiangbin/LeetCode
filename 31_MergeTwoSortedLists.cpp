/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        
        ListNode *i = l1;
        ListNode *j = l2;
        ListNode *res = NULL;
        if(i->val <= j->val){
            res = i;
            i = i->next;
        }
        else{
            res = j;
            j = j->next;
        }
        ListNode *k = res;
        while(i!=NULL&&j!=NULL){
            if(i->val <=j->val){
                    k->next = i;
                    k = k->next;
                    i = i->next;
            }
            else{
                    k->next = j;
                    k = k->next;
                    j = j->next;
            }
        }
        
        if(i!=NULL){
            k->next = i;
        }
        if(j!=NULL){
            k->next = j;
        }
        
        return res;
    }
};