/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesser = new ListNode(-1);
        ListNode* greater = new ListNode(-1);
        
        ListNode* t1 = lesser;
        ListNode* t2 = greater;
        
        while(head){
            if(head->val < x){
                t1->next = head;
                t1 = t1->next;
            }else{
                t2->next = head;
                t2 = t2->next;
            }
            head = head->next; 
        }
        t1->next = greater->next;
        t2->next = NULL;
        return lesser->next;
    }
};