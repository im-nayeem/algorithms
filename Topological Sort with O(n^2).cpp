#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge;
    cin>>node>>edge;
    vector<vector<bool>>graph(node+1,vector<bool>(node+1,0));
    for(int i=1;i<=edge;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
    }
    vector<bool>taken(node+1,0);
    vector<int>indegree(node+1,0);
    int i,j;

    for(i=1;i<=node;i++)
        for(j=1;j<=node;j++)
            if(graph[j][i]==1)
                indegree[i]++;
   // cout<<"\n"<<endl;

   // for(int i=1;i<=node;i++)
   //     cout<<i<<"--> "<<indegree[i]<<endl;

      queue<int>q;
     for(i=1;i<=node;i++)
     	if(!indegree[i])
     		{
     			q.push(i);
     			taken[i]=true;
     		}

     while(!q.empty())
     {
     	int v=q.front();
     	q.pop(); 

     	cout<<v<<" ";
     	for(i=1;i<=node;i++)
     		if(graph[v][i] && !taken[i])
     		{
     			indegree[i]--;
     			if(!indegree[i])
     				{
     					q.push(i);
     					taken[i]=true;
     				}
     		}
     }

    
    cout<<endl;
}
