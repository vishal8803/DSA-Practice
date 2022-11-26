//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        if(str.size() == 0) return NULL;
        int i = 0;
        int num = 0;
        while(i < str.size() and str[i] != '(') {
            num = num*10 + (str[i] - '0');
            i++;
        }
        
        Node* root = new Node(num);
        
        if(i == str.size()) return root;
        
        stack<char> st;
        st.push(str[i++]);
        string left = "";
        while(st.size() > 0) {
            if(str[i] == ')' and st.size() == 1) {
                st.pop();
            } else {
                left += str[i];
                if(str[i] =='(') {
                    st.push(str[i]);
                } else if(str[i] ==')') {
                    st.pop();
                }
            }
            i++;
        }
        root->left = treeFromString(left);
        
        if(i == str.size()) return root;
        
        st.push(str[i++]);
        string right = "";
        while(st.size() > 0) {
            if(str[i] == ')' and st.size() == 1) {
                st.pop();
            } else {
                right += str[i];
                if(str[i] =='(') {
                    st.push(str[i]);
                } else if(str[i] ==')') {
                    st.pop();
                }
            }
            i++;
        }
        
        root->right = treeFromString(right);
        
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends