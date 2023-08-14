//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            String s = br.readLine();
            String[] S = s.split(" ");
            int[] v = new int[2 * n + 2];
            for(int i = 0; i < 2 * n + 2; i++)
            {
                v[i] = Integer.parseInt(S[i]);
            }
            Solution ob = new Solution();
            int[] ans = ob.singleNumber(v);
            for(int i = 0; i < ans.length; i++)
                System.out.print(ans[i] + " ");
            System.out.println();
        }
    }
}


// } Driver Code Ends



//User function Template for Java

class Solution
{
    public int[] singleNumber(int[] a)
    {
        int xor1 =0 ;
        int n =a.length ;
        for(int i =0 ;i<n ;i++)
        {
            xor1=xor1^a[i] ;
        }
        int set =0,pos =0,newXor=0,tempXor=xor1 ;
        while(set != 1)
        {
            set = xor1 & 1 ;
            pos++ ;
            xor1=xor1>>1 ;
        }
        for(int i =0 ;i<n ;i++)
        {
            if(setBit(a[i],pos-1) == 1)
            {
                newXor = newXor^a[i] ;
            }
        }
        int x =newXor ;
        int y = tempXor^newXor ;
        int b[] = new int[2] ;
        if(x>y)
        {
            b[0]=y ;
            b[1]=x ;
        }else
        {
            b[0]=x ;
            b[1]=y ;
        }
        return b ;
    }
    public int setBit(int a , int pos)
    {
        return (a>>pos)&1 ;
    }
}