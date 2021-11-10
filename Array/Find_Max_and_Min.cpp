#include <bits/stdc++.h>
using namespace std;


class maxMin{
    public :
    int max = INT_MIN;
    int min = INT_MAX;
};


// Pair comparision method

    /*
        If n is odd:    3*(n-1)/2
        If n is even:   1 Initial comparison for initializing min and max, and 3(n-2)/2 comparisons for rest of the elements
                        =  1 + 3*(n-2)/2 = 3n/2 -2
    */
    maxMin pairCompare(int arr[], int n)
    {
        maxMin mm;
        int startIndx = 0;
        
        if(n == 1)
        {
            mm.min = mm.max = arr[0];
            return mm;
        }
        
        // Even array size even then initialize first and second element as min and max accordingly else initialize first element as min and max both.
        if(n%2 == 0)
        {
            if(arr[0] > arr[1])
            {
                mm.max = arr[0];
                mm.min = arr[1];
            }
            else
            {
                mm.max = arr[1];
                mm.min = arr[0];
            }
            
            startIndx = 2;
        }
        else
        {
            mm.max = mm.min = arr[0];
            startIndx = 1;
        }
        
        // Loop and compare every pair with maxMin class min and max number.
        while(startIndx < n-1)
        {
            if(arr[startIndx] > arr[startIndx+1])
            {
                if(arr[startIndx]>mm.max)
                {
                    mm.max = arr[startIndx];
                }
                if(arr[startIndx+1] < mm.min)
                {
                    mm.min = arr[startIndx+1];
                }
            }
            else
            {
                if(arr[startIndx+1] > mm.max)
                {
                    mm.max = arr[startIndx+1];
                }
                if(arr[startIndx] < mm.min)
                {
                    mm.min = arr[startIndx];
                }
            }
            
            startIndx+=2;
        }
        return mm;
    }
// pair comparision method end.


int main() {
	// your code goes here
	
	int arr[] = { 1000, 11, 445,1, 330, 3000 };
    int arr_size = 6;
    
    maxMin mm;
    mm = pairCompare(arr,arr_size);
    
    cout<<mm.max<<endl;
    cout<<mm.min<<endl;
    
	return 0;
	
}
