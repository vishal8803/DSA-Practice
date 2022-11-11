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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        
        vector<int> temp;
        while(head) {
            temp.push_back(head->val);
            head = head->next;
        }
        
        vector<int> v;
        
        for(int i = 1; i < temp.size() - 1; i++) {
            if(temp[i] > temp[i-1] and temp[i] > temp[i+1]) {
                v.push_back(i);
            } else if(temp[i] < temp[i-1] and temp[i] < temp[i+1]) {
                v.push_back(i);
            }
        }
        
        if(v.size() < 2) return ans;
        int mn = INT_MAX;
        int mx = v[v.size() - 1] - v[0];
        
        for(int i = 0; i < v.size() - 1; i++) {
            mn = min(mn, v[i+1] - v[i]);
        }
        
        return {mn, mx};
    }
};