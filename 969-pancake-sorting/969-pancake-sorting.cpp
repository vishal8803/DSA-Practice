class Solution {
public:
    int max_element(vector<int> &arr, int i) {
        int idx = 0;
        int mx = arr[0];
        for(int j = 0; j+i<arr.size(); j++) {
            if(arr[j] > mx) {
                mx = arr[j];
                idx = j;
            }
        }
        return idx;
    }
    void display(vector<int> &arr) {
        for(int i : arr) {
            cout<<i<<" ";
        }cout<<endl;
    }
    
    bool isSorted(vector<int> &arr) {
        for(int i = 0; i < arr.size()-1; i++) {
            if(arr[i] > arr[i+1]) return false;
        }
        return true;
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); i++) {
            int idx = max_element(arr,i);
            ans.push_back(idx+1);
            reverse(arr.begin(), arr.begin()+idx+1);
            ans.push_back(arr[0]);
            reverse(arr.begin(), arr.end()-i);
            if(isSorted(arr)) break;
        }
        
        
        return ans;
    }
    
};