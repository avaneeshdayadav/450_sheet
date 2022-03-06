#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxSum = 0,sum=0,minElm=arr[0];
        
        for(long long i = 0;i<n;i++)
        {
            sum += arr[i];
            if(sum > maxSum)
                maxSum = sum;
            if(sum < 0)
                sum = 0;
            
            if(minElm < arr[i])
                minElm = arr[i];
        }
        
        if(maxSum == 0)
            return minElm;
        return maxSum;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
