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
    bool isCycle(ListNode * head){
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if(isCycle(head)==false)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        
        if(fast==head)
            return fast;
        
        fast=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        return slow->next;
    }
};