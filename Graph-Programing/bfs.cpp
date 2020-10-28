#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
void bfs(int s, vector<int> adj[], bool vis[])
{
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        int n=q.front();
        
        cout<<n<<" ";
        q.pop();
        vector<int>&m=adj[n];
        for(int i=0;i<m.size();i++)
        {
            if(!vis[m[i]])
            {
                
                
                vis[m[i]]=true;
                q.push(m[i]);
            }
        }
    }
    
}


int main()
{
    
        int N, E;
        cout<<"enter total nodes"<<endl;
        cin>>N;
        cout<<"enter total edges"<<endl;
        cin>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cout<<"enter edge u and v :"<<" ";
            cin>>u>>v;
            adj[u].push_back(v);
             adj[v].push_back(u);
        }
        cout<<"enter a node from which u want to implement bfs"<<endl;
        int t;
        cin>>t;
        cout<<"\n";
        cout<<"The BFS order is"<<endl;
        bfs(t,adj, vis);
        cout<<endl;
    
}