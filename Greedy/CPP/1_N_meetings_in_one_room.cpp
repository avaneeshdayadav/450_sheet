
#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static comp(pair<int,int> &a, pair<int,int> &b)
    {
        return (a.second<b.second);
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> meet;
        
        for(int i=0;i<n;i++)
        {
            meet.push_back({start[i],end[i]});
        }
        
        sort(meet.begin(),meet.end(),comp);
        
        int prevEndTime = meet[0].second, count=1;
        
        for(int i=1;i<n;i++)
        {
            if(meet[i].first > prevEndTime)
            {
                count++;
                prevEndTime = meet[i].second;
            }
        }
        
        
        return count;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
