#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>> &graph,int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void printGraph(vector<vector<int>> &graph)
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<" => ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" -> ";
        }
        cout<<"NULL"<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> graph(n);
    
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,2,1);
    addEdge(graph,4,1);
    addEdge(graph,3,4);
    
    printGraph(graph);
    
    return 0;
}
