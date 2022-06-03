// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

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

int length(Node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

Node* reverse(Node* head){
    Node* curr = head;
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

void reorderEvenList(Node* &head, Node* middle){
    Node* curr = head;
    
    while(curr){
        Node* temp = curr->next;
        curr->next = middle;
        Node* temp2 = middle->next;
        if(temp2 == NULL)
            return;
        middle->next = temp;
        curr = temp;
        middle = temp2;
    }
}

void reorderOddList(Node* &head, Node* middle){
    Node* curr = head;
    
    while(curr){
        Node* temp = curr->next;
        curr->next = middle;
        Node* temp2 = middle->next;
        
        middle->next = temp;
        if(temp2 == NULL)
        {
            temp->next = NULL;
            return;
        }
        curr = temp;
        middle = temp2;
    }
}

void reorderList(Node* head) {
    if(head==NULL || head->next==NULL)
        return;
        
    int len = length(head);
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    slow->next = reverse(slow->next);
    
    
    if(len%2==0){
        reorderEvenList(head, slow->next);
    }
    else{
        reorderOddList(head, slow->next);
    }
}


