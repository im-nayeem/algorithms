#include<bits/stdc++.h>
using namespace std;
bool bicolorable(vector<vector<int>>graph)
{
    vector<bool>visited(graph.size(),0);
    vector<bool>color(graph.size());
    queue<int>q;
    visited[0]=1;
    color[0]=0;
    q.push(0);
    while(!q.empty())
    {
        int v=q.front();q.pop();
        for(int u:graph[v])
        {
            if(color[u] && color[u]==color[v])
                return false;

            if(!visited[u])
            {

                visited[u]=1;
                (color[v]==0)?color[u]=1:color[u]=0;
                q.push(u);


            }
        }
    }
    return true;

}
int main()
{
    int node;
    while(cin>>node)
    {
        if(node==0)
            break;
        int edge;
        cin>>edge;
    vector<vector<int>>graph(node);
    for(int i=0;i<edge;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if(bicolorable(graph))
        cout<<"BICOLORABLE."<<endl;
    else
        cout<<"NOT BICOLORABLE."<<endl;
    }

}
