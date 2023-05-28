//{ Driver Code Starts
//Initial Template for C
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();


// } Driver Code Ends
//User function Template for C

//Function to find the data of nth node from the end of a linked list.
int length(struct Node *h)
{
    int l =0 ;
    while(h)
    {
        l=l+1 ;
        h=h->next ;
    }
    return l ;
}
int getNthFromLast(struct Node *head, int n)
{
    int l =length(head) ;
    if(n>l)
    {
        return -1 ;
    }
    int c = l-n ;
    int k =1 ;
   struct Node *t = head ;
    while(k<=c)
    {
        t=t->next ;
        k+=1 ;
    }
    return t->data ;
    
}

//{ Driver Code Starts.



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      start=NULL;
      int n,k;
      scanf("%d",&n);
      scanf("%d",&k);
      insert(n);
      int res = getNthFromLast(start,k);
      printf("%d\n",res);
    }
    return 0;

}


 void insert(int n)
 {   int value,i;
     struct Node *temp;
     for(i=0;i<n;i++)
     {
         scanf("%d",&value);
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }
 





// } Driver Code Ends