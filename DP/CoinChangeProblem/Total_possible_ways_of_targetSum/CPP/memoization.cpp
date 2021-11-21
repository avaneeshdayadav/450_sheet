
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    map<string,long long int> memo;
  public:
    long long int count( int S[], int m, int n )
    {
        int noOfElem = m, sum = n;
      
        // Note , in between is necessary
        string key = to_string(noOfElem)+","+to_string(sum);

        if(memo.find(key) != memo.end())
            return memo[key];

        if(sum == 0)
        {
            memo[key] = 1;
            return 1;
        }

        if(sum<0)
        {
            return 0;
        }

        if((sum>0 && noOfElem<=0))
        {
            memo[key] = 0;
            return 0;
        }
            
        memo[key] = count(S,m-1,sum) + count(S,m,sum-S[m-1]);
        return memo[key];
    }
};

// { Driver Code Starts.
int main()
{
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
}  // } Driver Code Ends
