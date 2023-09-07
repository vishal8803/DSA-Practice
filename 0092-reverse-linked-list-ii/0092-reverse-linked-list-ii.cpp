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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> temp;
        while(head){
            temp.push_back(head->val);
            head = head->next;
        }
        reverse(temp.begin()+left-1, temp.begin()+right);
        ListNode* dummy = new ListNode(-1);
        ListNode* t = dummy;
        for(int i : temp){
            t->next = new ListNode(i);
            t = t->next;
        }
        return dummy->next;
    }
};