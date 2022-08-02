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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * nextHead = head;
            for (int i=0; i<k; ++i) {
              if (!nextHead)
              {
                  return head;
              }
              nextHead = nextHead->next;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt;
        
        int count = 0;
        
        while(curr && count < k) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        
        if(curr) {
            head->next = reverseKGroup(curr,k);
        }
        
        return prev;
    }
};