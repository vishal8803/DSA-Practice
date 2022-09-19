class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        
        for(string path : paths) {
            int i = 0;
            string rootDirectory = "";
            while(i < path.size() && path[i] != ' ') {
                rootDirectory += path[i];
                i++;
            }
            
            i++;
            while(i < path.size()) {
                string file = "";
                while(i < path.size() && path[i] != '(') {
                    file += path[i];
                    i++;
                }
                i++;
                string content = "";
                while(i < path.size() && path[i] != ')') {
                    content += path[i];
                    i++;
                }
                i+=2;
                
                mp[content].push_back(rootDirectory+"/"+file);
            }
        }
        
        for(auto it : mp) {
            if(it.second.size() > 1)
                ans.push_back(it.second);
        }
        
        return ans;
    }
};