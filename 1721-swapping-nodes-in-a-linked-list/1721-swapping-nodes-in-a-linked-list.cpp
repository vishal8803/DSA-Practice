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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        
        vector<int> temp;
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
        
        swap(temp[k-1],temp[temp.size()-k]);
        ListNode* ans = new ListNode(-1);
        ListNode* t = ans;
        
        for(int i : temp){
            t->next = new ListNode(i);
            t = t->next;
        }
        return ans->next;
    }
};