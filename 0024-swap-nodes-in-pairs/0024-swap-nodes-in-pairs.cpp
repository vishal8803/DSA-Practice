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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        
        while(t1 && t2){
            ListNode* r = t2->next;
            temp->next = t2;
            t2->next = t1;
            t1->next = r;
            temp = t1;
            t1=t1->next;
            if(t1){
                t2=t1->next;
            }
        }
        return dummy->next;
    }
};