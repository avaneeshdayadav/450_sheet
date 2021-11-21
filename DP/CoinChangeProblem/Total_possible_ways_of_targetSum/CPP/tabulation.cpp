/*
  Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.

  Example 1:

  Input:
  n = 4 , m = 3
  S[] = {1,2,3}
  Output: 4
  Explanation: Four Possible ways are:
  {1,1,1,1},{1,1,2},{2,2},{1,3}.
  Example 2:

  Input:
  n = 10 , m = 4
  S[] ={2,5,3,6}
  Output: 5
  Explanation: Five Possible ways are:
  {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
  and {5,5}.

  Your Task:
  You don't need to read input or print anything. Your task is to complete the function count() which accepts an array S[] its size m and n as input parameter and returns the number of ways to make change for N cents.


  Expected Time Complexity: O(m*n).
  Expected Auxiliary Space: O(n).


  Constraints:
  1 <= n,m <= 103

*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long int count(int S[],int m, int n)
    {
        long long int dp[m+1][n+1];
        
        int i=0,j=0;
        for(i=0;i<m+1;i++)
        {
            for(j=0;j<n+1;j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = 0;
                else if(j==0)
                    dp[i][j] = 1;
                else if(j>=S[i-1])
                    dp[i][j] = dp[i][j-S[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[m][n];
    }
};
int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    
	    int arr[m];
	    for(int i=0;i<m;i++)
	        cin>>arr[i];
	       
	    Solution ob;
	    cout<<ob.count(arr,m,n)<<endl;
	}
	return 0;
}

