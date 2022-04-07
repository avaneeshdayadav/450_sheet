
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    long long int countUtil(int S[], int m, int n, map<pair<int,int>,long long int> &memo)
    {
        // code here.
        
       if(memo.find({m,n}) != memo.end())
            return memo[{m,n}];
            
        if(n<0)
            return 0;
        
        if(n == 0)
        {
            memo[{m,n}] = 1;
            return 1;
        }
            
        
        if(n>0 && m<=0)
            return 0;
            
        

        memo[{m,n}] = countUtil(S,m-1,n,memo) + countUtil(S,m,n-S[m-1],memo);
        
        return memo[{m,n}];
        
    }
    
    
    long long int count(int S[], int m, int n) {
        
        // vector<vector<int>> memo(m,vector<int>(n+1,-1));
        
        map<pair<int,int>,long long int> memo;
        
        return countUtil(S,m,n,memo);
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
