#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&graph,int v,vector<bool>&visited,stack<int>&stk)
{
    visited[v]=1;
    for(int x:graph[v])
        if(!visited[x])
             dfs(graph,x,visited,stk);
    stk.push(v);

}
int main()
{
    int node,edge;
    cin>>node>>edge;

    vector<vector<int>>graph(node+1);

    for(int i=1;i<=edge;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    vector<bool>visited(node+1,0);
    stack<int>ans;

    for(int i=1;i<=node;i++)
        if(!visited[i])
            dfs(graph,i,visited,ans);

    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;

}
