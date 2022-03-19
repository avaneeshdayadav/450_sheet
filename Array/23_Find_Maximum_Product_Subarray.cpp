// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    
	    long long temp, max_till_now = arr[0], min_till_now = arr[0], gmax = arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        temp = maxim(maxim(arr[i], arr[i]*max_till_now), arr[i]*min_till_now);
	        min_till_now = mini(mini(arr[i], arr[i]*max_till_now), arr[i]*min_till_now);
	        max_till_now = temp;
	        gmax = maxim(gmax,max_till_now);
	    }
	    
	    return gmax;
	}
	
	long long maxim(long long a, long long b)
	{
	    if(a > b)
	        return a;
	   return b;
	}
	
	
	long long mini(long long a, long long b)
	{
	    if(a < b)
	        return a;
	   return b;
	}

	
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
