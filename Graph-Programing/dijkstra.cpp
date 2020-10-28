#include<bits/stdc++.h>
using namespace std;

int mind(int d[],vector<bool> vis,int V)
{
    int m=INT_MAX;
    int ver;
    for(int i=0;i<V;i++)
    {
        if(!vis[i] && d[i]<=m)
        {
            m=d[i];
            ver=i;
            
        }
        
    }
    return ver;
}
void dijkstra(vector<vector<int>> g, int src, int V)
{
int d[V];

for(int i=0;i<V;i++)
d[i]=INT_MAX;

d[src]=0;
vector<bool> vis(V,false);
for(int i=0;i<V-1;i++)
{
    int u=mind(d,vis,V);
    vis[u]=true;
    for(int j=0;j<V;j++)
    {
        if(!vis[j] && g[u][j] && d[u]!=INT_MAX && d[u]+g[u][j]<d[j])
        d[j]=d[u]+g[u][j];
    }
    
}

for(int i=0;i<V;i++)
{
    cout<<d[i]<<" ";
}
}
int main()
{
    int V;
    cout<<"Enter no.of nodes in the graph :"<<" ";
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                cin>>g[i][j];
            }
        }
        cout<<"enter the source node from where u wanna implement dijkstra algo :"<<" ";
        int s;
          cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       
        return 0;

}