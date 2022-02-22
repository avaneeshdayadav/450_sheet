#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int low = 0,high = n-1,mid = 0;
        while(mid <= high)
        {
            if(arr[mid] == 2)
            {
                swap(arr[mid],arr[high]);
                high--;
            }
            else if(arr[mid] == 0)
            {
                swap(arr[mid],arr[low]);
                low++;
                mid++;
            }
            else
                mid++;
        }
    }
    
};


int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
