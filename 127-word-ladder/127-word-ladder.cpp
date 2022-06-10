class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.length()==0 || endWord.length()==0 || wordList.size()==0)
            return 0;
        
        set<string> st;
        bool isPresent = false;
        for(int i=0; i<wordList.size(); i++)
        {
            if(wordList[i]==endWord) // checking the end word is present or not
                isPresent = true;
            
            st.insert(wordList[i]); // inserting the word in the set
        }
        
        if(!isPresent) // If the word is not present in the list
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int ans =0 ;
        while(!q.empty())
        {
            int size = q.size();
            ans++;
            while(size--)
            {
                string temp = q.front();
                q.pop();    
                for(int i=0; i<temp.length(); i++)
                {
                    char c = temp[i];
                    string curr = temp;
                    for(int j=0; j<26; j++)
                    {
                        if(c=='a'+j)
                            continue;
                        curr[i]='a'+j;
                        if(curr==endWord)
                            return ans+1;
                        if(st.find(curr)!=st.end())
                        {
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                }
            }
        }
        return 0;
    }
};