//{ Driver Code Starts
//Initial Template for Java



import java.util.stream.Collectors; 
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            int n = Integer.parseInt(br.readLine().trim());
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().print2largest(arr, n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    int print2largest(int arr[], int n) {
        int mx1 = Integer.MIN_VALUE;
        int mx2 = Integer.MIN_VALUE;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] == mx1) continue;
            if(mx1 < arr[i]) {
                mx2 = mx1;
                mx1 = arr[i];
            } else if(mx2 < arr[i]) {
                mx2 = arr[i];
            }
        }
        if(mx2 == Integer.MIN_VALUE) return -1;
        return mx2;
    }
}