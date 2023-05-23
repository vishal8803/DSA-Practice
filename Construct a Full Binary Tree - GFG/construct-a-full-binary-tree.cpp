//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* calc(int pre[], int preMirror[], int pst, int pend, int pmst, int pmend, map<int,int> mp1, map<int,int> mp2) {
        if(pst > pend) return NULL;
        Node* root = new Node(pre[pst]);
        if(pst == pend) return root;
        
        root->left = calc(pre, preMirror, pst+1, mp1[preMirror[pmst+1]]-1, mp2[pre[pst+1]], pmend, mp1, mp2);
        root->right = calc(pre, preMirror, mp1[preMirror[pmst+1]], pend, pmst+1, mp2[pre[pst+1]]-1, mp1, mp2);
        
        return root;
    }
    
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        map<int,int> mp1, mp2;
        
        for(int i = 0; i < size; i++) {
            mp1[pre[i]] = i;
            mp2[preMirror[i]] = i;
        }
        
        return calc(pre, preMirror, 0, size-1, 0, size-1, mp1, mp2);
        
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends