// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node* even = new Node(-1);
        Node* odd = new Node(-1);
        
        Node* t1 = even;
        Node* t2 = odd;
        
        Node* temp = head;
        while(temp){
            if(temp->data%2==1){
                t2->next = temp;
                t2 = t2->next;
            }else{
                t1->next = temp;
                t1 = t1->next;
            }
            temp = temp->next;
        }
        
        t1->next = NULL;
        t2->next = NULL;
        
        even = even->next;
        odd = odd->next;
        
        if(even && odd){
            t1->next = odd;
            return even;
        }else if(even){
            return even;
        }else{
            return odd;
        }
        return NULL;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends