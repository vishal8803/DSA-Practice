//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int a[], int l, int h)
    {
        if (l < h)
        {
            int pIndex = partition(a, l, h);
    
            quickSort(a, l, pIndex - 1);
            quickSort(a, pIndex + 1, h);
        }
    }
    
    public:
    int partition (int a[], int l, int h)
    {
        int pivot = a[l];
        int i = l + 1;
        int j = h;
        do
        {
            while (a[i] <= pivot)
            {
                i++;
            }
            while (a[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        } while (i < j);
    
        int t = a[j];
        a[j] = a[l];
        a[l] = t;
        return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends