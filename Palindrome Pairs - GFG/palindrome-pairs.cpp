// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    // Function to check if a palindrome pair exists
    
    void insertWordsInMap(int n, string words[], map<string,int> &wordsIndex){
        for(int i = 0; i < n; i++){
            string word = words[i];
            wordsIndex[word] = i;
        }
    }
    
    bool isPresent(map<string, int> &wordsIndex, string word){
        if(wordsIndex.find(word) != wordsIndex.end())
            return true;
        
        return false;
    }
    
    bool isPalindrome(string word){
        int i = 0;
        int j = word.length()-1;
        
        while(i<=j){
            if(word[i++] != word[j--]) return false;
        }
        return true;
    }
    
    bool palindromepair(int n, string arr[]) {
        map<string,int> wordsIndex;
        
        insertWordsInMap(n, arr, wordsIndex);
        
        // Refelection Case
        for(int i = 0; i < n; i++){
            string word = arr[i];
            string temp = word;
            reverse(temp.begin(), temp.end());
            
            if(isPresent(wordsIndex,temp) && wordsIndex[temp] != i){
                return true;
            }
        }
        
        // Tricky Case
        for(int i = 0; i < n; i++){
            string word = arr[i];
            for(int j = 1; j < word.length(); j++){
                string left = word.substr(0,j);
                string right = word.substr(j);
                
                if(isPalindrome(left)){
                    string reversedRight = right;
                    reverse(reversedRight.begin(), reversedRight.end());
                    
                    if(isPresent(wordsIndex,reversedRight) && wordsIndex[reversedRight] != i){
                        return true;
                    }
                }
                
                if(isPalindrome(right)){
                    string reversedLeft = left;
                    reverse(reversedLeft.begin(), reversedLeft.end());
                    
                    if(isPresent(wordsIndex,reversedLeft) && wordsIndex[reversedLeft] != i){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends