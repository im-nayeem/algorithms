#include<bits/stdc++.h>
using namespace std;
void dfs1(vector<vector<int>>&graph,int v,vector<bool>&visited,stack<int>&stk)
{
     visited[v]=1;
    for(int x:graph[v])
        if(!visited[x])
             dfs1(graph,x,visited,stk);
    stk.push(v);

}
void dfs2(vector<vector<int>>&newGraph,int v,vector<bool>&visited,vector<int>&List)
{
    visited[v]=1;
    List.push_back(v);
    for(int x:newGraph[v])
        if(!visited[x])
            dfs2(newGraph,x,visited,List);
}
vector<vector<int>> getTranspose(vector<vector<int>>&graph)
{
    vector<vector<int>>newGraph(graph.size());

    for(int i=1;i<graph.size();i++)
        for(int j:graph[i])
            newGraph[j].push_back(i);
       
    return newGraph;
}
vector<vector<int>> findSCC(vector<vector<int>>&graph)
{
    vector<bool>visited(graph.size(),0);
    stack<int>stk;
    int i;
    for(i=1;i<graph.size();i++)
        if(!visited[i])
            dfs1(graph,i,visited,stk);

    vector<vector<int>>newGraph=getTranspose(graph);


    visited.assign(visited.size(),0);

    vector<vector<int>>ans;
    while(!stk.empty())
    {
        int x=stk.top();
        stk.pop();
        if(!visited[x])
        {
            vector<int>List;
            dfs2(newGraph,x,visited,List);
            reverse(List.begin(),List.end());
            ans.push_back(List);
//            for(int x:List)
//                cout<<x<<" ";
//            cout<<endl;
        }
    }
    return ans;

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
    vector<vector<int>>ans=findSCC(graph);

    
    for(auto j:ans)
    {
        for(int i:j)
            cout<<i<<" ";
        cout<<endl;
    }
}
