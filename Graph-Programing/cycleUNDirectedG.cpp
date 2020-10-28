#include<bits/stdc++.h>
using namespace std;
int iscyc(int s,vector<int> adj[],int V,int p,vector<bool>&vis)
{
    vis[s]=true;
    vector<int>&m=adj[s];
    for(int i=0;i<m.size();i++)
    {
        if(!vis[m[i]] )
        {
            if(iscyc(m[i],adj,V,s,vis)==1)
            {
              
                return 1;
            }
        }
        else if(m[i]!=p)
        {
          
        return 1;}
    }
    
    return 0;
}
int isCyclic(vector<int> adj[], int V)
{
   vector<bool> vis(V,false);
   
   for(int i=0;i<V;i++)
   {
    if(!vis[i])
      {
       if(iscyc(i,adj,V,-1,vis)==1)
        {
           return 1;
        }
      }
   }
   return 0;
   
}
int main()
{
   
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(isCyclic(adj, V)==1)
        {
          cout<<"Graph has a cycle"<<endl;
        }
        else
          cout<<"Graph has a No cycle"<<endl;
    
}