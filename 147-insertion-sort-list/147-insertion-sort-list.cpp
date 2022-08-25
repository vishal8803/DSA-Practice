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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> temp;
        while(head) {
            temp.push_back(head->val);
            head = head->next;
        }
        
        sort(temp.begin(), temp.end());
        
        ListNode* dummy = new ListNode(-1);
        ListNode* t = dummy;
        
        for(int i : temp) {
            t->next = new ListNode(i);
            t = t->next;
        }
        
        return dummy->next;
    }
};