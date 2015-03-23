/*You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a 
single digit. Add the two numbers and return it as a linked list.
/*

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* result=NULL;
        ListNode* p = NULL;
        
        int carrier = 0,plus = 0;
        while(l1!=NULL || l2!=NULL){
            if(l1==NULL){
                plus = carrier + l2->val;
                l2 = l2->next;
            }
            else if(l2==NULL){
                plus = carrier + l1->val;
                l1 = l1->next;
            }
            else{
                plus = carrier+l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            carrier = plus/10;
            ListNode *pNew = new ListNode(plus%10);
            
            if(result==NULL){
                result = pNew;
                p = pNew;
            }
            else{
                p->next = pNew;
                p = p->next;
            }
        }
        
        if(carrier > 0){
            ListNode *pNew = new ListNode(carrier);
            p->next = pNew;
        }
        
        return result;
    }
};