/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return head;
            
        ListNode* res = head;
        while(head!=NULL&&head->val==val){
            head = head->next;
        }
        
        res = head;
        while(head!=NULL&&head->next!=NULL){
            if(head->next->val == val){
                head->next = head->next->next;
            }
            else{
                head = head->next;
            }
        }
        
        return res;
    }
};