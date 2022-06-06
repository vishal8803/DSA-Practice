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
    int length(ListNode* head){
        int count = 0;
        
        while(head){
            head =  head->next;
            count++;
        }
        
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        
        ListNode *a1, *a2;
        int diff;
        
        if(l1>l2){
            diff = l1-l2;
            a1 = headA;
            a2 = headB;
        }else{
            diff = l2-l1;
            a1 = headB;
            a2 = headA;
        }
        
        while(diff>0){
            a1 = a1->next;
            diff--;
        }
        
        while(a1 && a2 && a1 != a2){
            a1 = a1->next;
            a2 = a2->next;
        }
        
        if(a1 && a2)
            return a1;
        
        return NULL;
    }
};