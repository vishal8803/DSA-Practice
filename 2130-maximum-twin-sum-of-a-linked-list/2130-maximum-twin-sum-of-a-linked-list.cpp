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
    int pairSum(ListNode* head) {
        vector<int> ans;
        while(head)
        {
            ans.push_back(head->val);
            head=head->next;
        }
        int i=0;
        int j=ans.size()-1;
        int fans=INT_MIN;
        while(i<j){
            fans=max(fans,ans[i]+ans[j]);
            i++;
            j--;
        }
        return fans;
    }
};