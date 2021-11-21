
/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */



class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		while(t-- > 0)
		{
		    int n = sc.nextInt();
		    int m = sc.nextInt();
		    int Arr[] = new int[m];
		    
		    for(int i=0;i<m;i++)
		        Arr[i] = sc.nextInt();
		    
		    Solution ob = new Solution();
		    System.out.println(ob.count(Arr,m,n));
		    System.out.println(ob.memo);
		    
		}
	}
}


class Solution {
    public Map<String,Long> memo = new HashMap<String,Long>();
    public long count(int S[], int m, int n) {
        // code here.
        
        String key = Integer.toString(m)+","+Integer.toString(n);
        
        if(memo.containsKey(key) == true)
            return memo.get(key);
        
        if(n == 0)
            return 1;
        if(m == 0 && n>0)
            return 0;
        if(n<0)
            return 0;
        
        memo.put(key, count(S,m,n-S[m-1])+count(S,m-1,n));
        
        return memo.get(key);
        
    }
}
