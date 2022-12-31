//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        int count = 0;
        unordered_set<string> st, vis;
        
        
        for(string word : wordList) {
            st.insert(word);
        }
        
        queue<string> q;
        if(st.find(targetWord) == st.end()) return 0;
        q.push(startWord);
        vis.insert(startWord);
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                string word = q.front();
                q.pop();
                if(word == targetWord) return count+1;
                for(int i = 0; i < word.size(); i++) {
                    string temp = word;
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        if(ch == word[i]) continue;
                        temp[i] = ch;
                        if(st.find(temp) != st.end() and vis.find(temp) == vis.end()) {
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            count++;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends