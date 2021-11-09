#include <iostream>
using namespace std;
#include<bits/stdc++.h>

string strReverse(string str)
{
    int f=0,b=str.length()-1;
    while(f<=b)
    {
        char temp = str[f];
        str[f] = str[b];
        str[b] = temp;
        f++;
        b--;
    }
    return str;
}


void arrayReverse(int *arr,int n)
{
    int f=0,b=n-1;
    
    while(f<=b)
    {
        int temp = arr[f];
        arr[f] = arr[b];
        arr[b] = temp;
        f++;
        b--;
    }
}

vector<int> vectorReverse(vector<int> vec)
{
    int f=0,b=vec.size()-1;
    
    while(f<=b)
    {
        int temp = vec[f];
        vec[f] = vec[b];
        vec[b] = temp;
        f++;
        b--;
    }
    
    return vec;

}


int main()
{
	// your code goes here
	
	string str = "Avaneesh";
	int arr[6] = {1,2,5,67,76,8};
    vector<int> vec{ 10, 20, 30, 40,50 },retVec;
    
    cout<<strReverse(str)<<endl;
    arrayReverse(arr,6);
    retVec = vectorReverse(vec);
    
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
    
    for(int i=0;i<retVec.size();i++)
        cout<<retVec[i]<<" ";
    
    cout<<endl;
    // cout<<vectorReverse(vec)<<endl;
	
	return 0;
}
