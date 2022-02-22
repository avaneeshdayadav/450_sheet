// Using Pair Method.

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int n;
	
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	
    int start = 0;
    int minG = INT_MIN;
    int maxG = INT_MAX;
    
    if(n%2 == 0)
    {
        if(arr[0] < arr[1])
        {
            minG = arr[0];
            maxG = arr[1];
        }
        else
        {
            minG = arr[1];
            maxG = arr[0];
        }
        start = 2;
    }
    else
    {
        minG = arr[0];
        maxG = arr[0];
        start = 1;
    }
	
    for(int i=start;i<n-1;i+=2)
    {
        minG = min(minG,min(arr[i],arr[i+1]));
        maxG = max(maxG,max(arr[i],arr[i+1]));
    }
    
    cout<<minG<<" "<<maxG<<endl;
	return 0;
}
