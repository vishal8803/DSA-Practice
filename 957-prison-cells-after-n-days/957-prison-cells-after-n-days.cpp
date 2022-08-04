class Solution {
public:
    vector<int> nextDay(vector<int> &cells) {
        int n = cells.size();
        vector<int> temp(n,0);
        
        for(int i = 1; i < n-1; i++) {
            if(cells[i-1]==cells[i+1]) {
                temp[i] = 1;
            }
        }
        return temp;
    }
    
    string convertArrayToString(vector<int> &temp) {
        string s = "";
        for(int i : temp) s += to_string(i);
        return s;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        set<string> st;
        bool cycle = false;
        int count = 0;
        // st.insert(convertArrayToString(cells));
        
        for(int i = 0; i < n; i++) {
            vector<int> next = nextDay(cells);
            string t = convertArrayToString(next);
            if(st.find(t) != st.end()) {
                cycle = true;
                break;
            } else {
                st.insert(t);
                count++;
            }
            cells = next;
        }
        
        if(cycle) {
            n = n%count;
            for(int i = 0; i < n; i++) {
                cells = nextDay(cells);
            }
        }
        return cells;
    }
};