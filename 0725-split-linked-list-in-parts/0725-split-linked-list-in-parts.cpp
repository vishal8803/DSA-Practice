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
    int length(ListNode* head) {
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = length(head);
        int size = len/k;
        int t = len%k;
        
        vector<ListNode*> ans;
        
        if(size==0){
            
            while(head){
                ListNode* t = head->next;
                head->next = NULL;
                ans.push_back(head);
                head = t;
            }
            while(ans.size() != k)
                ans.push_back(NULL);
            return ans;
        }
        
        
        while(head){
            ListNode* r = head;
            int cnt = 1;
            while(cnt < size){
                head = head->next;
                cnt++;
            }
            if(t){
                head = head->next;
                t--;
            }
            if(head){
                ListNode* e = head->next;
                head->next = NULL;
                ans.push_back(r);
                head = e;
            }else{
                ans.push_back(r);
            }
        }
        return ans;
    }
};