// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* Structure of linked list Node

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

//You are required to complete this method

Node* reverse(Node* l1){
    Node* curr = l1;
    Node* prev = NULL;
    Node* nxt;
    
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    
    return prev;
}

int length(Node* l1){
    int count = 0;
    while(l1){
        count++;
        l1=l1->next;
    }
    return count;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    while(l1 && l1->data==0)
        l1 = l1->next;
        
    while(l2 && l2->data==0)
        l2 = l2->next;
        
    int len1 = length(l1);
    int len2 = length(l2);
    Node *g=NULL, *s=NULL;
    if(len1>len2){
        g = l1;
        s = l2;
    }else if(len2 > len1){
        g=l2;
        s=l1;
    }else{
        Node* t1 = l1;
        Node* t2 = l2;
        while(t1 && t2){
            if(t1->data > t2->data){
                g = l1;
                s = l2;
                break;
            }else if(t2->data > t1->data){
                g=l2;
                s=l1;
                break;
            }else{
                t1=t1->next;
                t2=t2->next;
            }
        }
        if(g==NULL && s==NULL){
            Node* ans = new Node(0);
            return ans;
        }
    }
    g = reverse(g);
    s = reverse(s);
    
    
    int carry = 0;
    
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    
    
    
    
    while(g || s || carry){
        int data1 = 0;
        int data2 = 0;
        
        if(g){
            data1 = g->data;
            g = g->next;
        }
        
        if(s){
            data2 = s->data;
            s = s->next;
        }
        
        int newCarry = 0;
        
        if(data1 < carry){
            data1 = 10 + data1;
            newCarry = 1;
        }
        
        data1-=carry;
        
        
        if(data1 < data2){
            data1 = 10 + data1;
            newCarry++ ;
        }
        
        carry = newCarry;
        
        Node* r = new Node(data1 - data2);
        temp->next = r;
        temp = temp->next;
    }
    
    Node* ans = reverse(dummy->next);
    
    while(ans && ans->data==0)
        ans = ans->next;
    
    return ans;
    
}