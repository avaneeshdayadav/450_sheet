#include <iostream>
using namespace std;


void swap(int *p,int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void revArr(int *arr,int n)
{
   int i=0,j=n-1;
   
   while(i<=j)
   {
       swap(arr[i],arr[j]);
       i++;
       j--;
   }
   
}
int main() {
	// your code goes here
	
	int arr[] = {1,2,3,4,5,6};
	
	int a=9,b=3;
// 	swap(a,b);
// 	cout<<a<<b<<endl;
	revArr(arr,6);
	
	for(int i=0;i<6;i++)
	{
	    cout<<arr[i]<<" ";
	}
	return 0;
}
