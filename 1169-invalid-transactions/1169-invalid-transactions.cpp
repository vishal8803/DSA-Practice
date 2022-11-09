class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> names, city;
        vector<int> times, amount;
        
        for(string s : transactions) {
            int i = 0;
            
            string name = "";
            while(i < s.size() and s[i] != ',') {
                name += s[i++];
            }
            i++;
            names.push_back(name);
            
            int time = 0;
            while(i < s.size() and s[i] != ',') {
                time = time*10 + (s[i]-'0');
                i++;
            }
            i++;
            times.push_back(time);
            
            int amt = 0;
            while(i < s.size() and s[i] != ',') {
                amt = amt*10 + (s[i] - '0');
                i++;
            }
            i++;
            amount.push_back(amt);
            
            string cty = "";
            while(i < s.size()) {
                cty += s[i];
                i++;
            }
            city.push_back(cty);
        }
        
        vector<string> ans;
        int n = names.size();

        for(int i = 0; i < n; i++) {
            if(amount[i] > 1000) {
                ans.push_back(transactions[i]);;
                continue;
            }
            
            for(int j = 0; j < n; j++) {
                if(j==i) continue;
                if(names[j] == names[i] and city[j] != city[i] and abs(times[i] - times[j]) <= 60) {
                    ans.push_back(transactions[i]);
                    break;
                }
            } 
        }
        return ans;
    }
};