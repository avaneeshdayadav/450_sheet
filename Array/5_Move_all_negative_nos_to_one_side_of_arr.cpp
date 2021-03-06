#include <bits/stdc++.h>
using namespace std;


void dutchNationalFlagAppr(int *arr, int n)
{
    int low = 0,high = n-1;
    
    while(low <= high)
    {
        if(arr[low] < 0)
            low++;
        else
        {
            swap(arr[low],arr[high]);
            high--;
        }
    }
}


void quickSortAppr(int *arr,int n)
{
    int i=0,j=n-1;
    
    while(i<=j)
    {
        if(arr[i]<0)
        {
            i++;
            continue;
        }
        if(arr[j]>0)
        {
            j--;
            continue;
        }
        
        if(arr[i]>0 && arr[j]<0)
            swap(arr[i],arr[j]);
    }
}
int main() {
	
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}

	int i = 0,j=n-1;

	quickSortAppr(arr,n);
	dutchNationalFlagAppr(arr,n);
	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
