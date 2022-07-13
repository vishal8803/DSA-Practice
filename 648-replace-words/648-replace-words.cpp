class Solution
{
    public:
        string replaceWords(vector<string> &dictionary, string sentence)
        {
            string ans = "";
            map<string, int> mp;
            
            for(string s : dictionary){
                mp[s]++;
            }
            
            int i = 0;
            while(i < sentence.length()){
                string temp = "";
                bool flag = false;
                
                while(i < sentence.length() && sentence[i] != ' '){
                    temp += sentence[i];
                    
                    if(!flag && mp.find(temp) != mp.end()){
                        ans += temp+" ";
                        flag = true;
                    }
                    
                    i++;
                }
                if(!flag){
                    ans += temp+" ";
                }
                
                i++;
                
            }
            
            return ans.substr(0,ans.length()-1);
        }
};