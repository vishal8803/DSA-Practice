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
     int length(ListNode *node)
    {
        int l =0 ;
        while(node)
        {
            l=l+1 ;
            node = node->next ;
        }
        return l ;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int l = length(head) ;
        if(n==l)
        {
            return head->next ;
        }
        int x = l-n ;
        ListNode *t =head ;
        while(x>1)
        {
            t=t->next ;
            x-- ;
        }
        t->next =t->next->next ;
            return head ;
    }
};